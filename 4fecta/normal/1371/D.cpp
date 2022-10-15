#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 305;

int a[MN][MN], R[MN], C[MN];

int sq(int x) {return x * x;}

int32_t main() {
    boost();

    int t, n, k;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        cin >> n >> k;
        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                if (!k) goto done;
                int col = c + r;
                if (col > n) col -= n;
                a[r][col] = 1;
                R[r]++; C[col]++;
                k--;
            }
        }
        done:
        int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f, max1 = 0, max2 = 0;
        for (int i = 1; i <= n; i++) {
            min1 = min(min1, R[i]);
            max1 = max(max1, R[i]);
            min2 = min(min2, C[i]);
            max2 = max(max2, C[i]);
        }
        printf("%lld\n", sq(max1 - min1) + sq(max2 - min2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) printf("%d", a[i][j]);
            printf("\n");
        }
    }

    return 0;
}