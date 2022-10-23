#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;

int n;
int p[N];
int l[N], r[N];
int can_use[N];

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &n);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &p[i]);
        }

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &l[i], &r[i]);
            can_use[i] = 0;
        }

        int ans = 0;
        for (int i = n; i >= 1; --i) {
            if (can_use[i] < l[i]) {
                ans++;
                can_use[i] = r[i];
            }

            can_use[p[i]] = min(can_use[p[i]] + can_use[i], r[p[i]]);
        }

        printf("%d\n", ans);
    }

    return 0;
}