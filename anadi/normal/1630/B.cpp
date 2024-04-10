#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n, k;
int in[N];
int pref[N];

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int need = (n + k + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &in[i]);
            pref[i] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            pref[in[i]]++;
        }

        for (int i = 1; i <= n; ++i) {
            pref[i] += pref[i - 1];
        }

        int ptr = 1;
        int best_x = 1, best_y = n;

        for (int i = 1; i <= n; ++i) {
            while (ptr < n && pref[ptr] - pref[i - 1] < need) {
                ++ptr;
            }

            if (pref[ptr] - pref[i - 1] >= need && ptr - i < best_y - best_x) {
                best_x = i, best_y = ptr;
            }
        }

        int last = 0, last_bal = 0;
        int cur_bal = 0, intrvs = 0;

        printf("%d %d\n", best_x, best_y);
        if (k == 1) {
            printf("%d %d\n", 1, n);
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            if (best_x <= in[i] && in[i] <= best_y) {
                cur_bal++;
            } else {
                cur_bal--;
            }

            if (cur_bal > last_bal) {
                printf("%d %d\n", last + 1, i);
                last = i;
                last_bal = cur_bal;
                intrvs++;
            }

            if (intrvs == k - 1) {
                printf("%d %d\n", last + 1, n);
                break;
            }
        }
    }

    return 0;
}