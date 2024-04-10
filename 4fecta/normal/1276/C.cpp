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

const int MN = 400005;

int n, a[MN], freq[MN];
map<int, int> mp;
vector<int> which[MN];

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
    for (pii p : mp) freq[p.s]++, which[p.s].push_back(p.f);
    for (int i = 400000; i > 0; i--) freq[i] += freq[i + 1];
    /*for (int i = 1; i <= 6; i++) printf("%d ", freq[i]);
    printf("\n");*/
    int cnt = 0, ans = 0, H = 0, W = 0;
    for (int i = 1; i <= 400000; i++) {
        cnt += freq[i];
        int h = cnt / i;
        if (h * i > ans && h >= i) {
            ans = h * i;
            H = h, W = i;
        }
    }
    int res[H + 5][W + 5];
    memset(res, 0, sizeof(res));
    int r = 1, c = 1;
    for (int id = 400000; id > 0; id--) {
        for (int num : which[id]) {
            for (int i = 0; i < min(W, id); i++) {
                if (res[r][c]) {
                    r++;
                    if (r > H) r -= H;
                }
                res[r++][c++] = num;
                if (c > W) c -= W;
                if (r > H) r -= H;
            }
        }
    }
    printf("%lld\n%lld %lld\n", ans, H, W);
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            assert(res[i][j]);
            printf("%lld ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}