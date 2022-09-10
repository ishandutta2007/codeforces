#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
char in[N];
int pref[N];
int suf[N];

void solve()
{
    scanf("%d %s", &n, in + 1);
    n *= 2;

    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (in[i] == '(' ? 1 : -1);
    }

    suf[n] = suf[n + 1] = 0;
    for (int i = n - 1; i >= 1; --i) {
        suf[i] = min(suf[i + 1], pref[i]);
    }

    int best = 0, ptr = 1;
    vector <pair <int, int> > ans;

    while (ptr <= n) {
        if (pref[ptr] > pref[best]) {
            best = ptr;
        }

        if (pref[ptr] >= 0) {
            ptr++;
            continue;
        }

        int cur_best = ptr;
        for (int i = ptr + 1; i <= n; ++i) {
            if (pref[i] > pref[cur_best]) {
                cur_best = i;
            }

            if (pref[i] + pref[best] >= max(pref[cur_best], 0) && suf[i] >= 0) {
                ans.push_back({best + 1, i});
                break;
            }
        }

        if (ans.empty()) {
            ans = {{best + 1, cur_best}, {cur_best + 1, n}};
        }

        break;
    }

/*    for (auto [l, r]: ans) {
        reverse(in + l, in + r + 1);
    }

    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += in[i] == '(' ? 1 : -1;
        if (s < 0) {
            exit(1);
        }
    }*/

    printf("%d\n", (int)ans.size());
    for (auto [l, r]: ans) {
        printf("%d %d\n", l, r);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}