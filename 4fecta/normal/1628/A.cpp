#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, a[MN], b[MN];
vector<int> pos[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        vector<int> ans;
        int lft = 1;
        while (lft <= n) {
            int p = lft, v = 0;
            for (int i = 0; i <= n; i++) {
                auto it = lower_bound(pos[i].begin(), pos[i].end(), lft);
                if (it == pos[i].end()) break;
                p = max(p, *it);
                v++;
            }
            ans.push_back(v);
            lft = p + 1;
        }
        printf("%lld\n", ans.size());
        for (int p : ans) printf("%lld ", p);
        printf("\n");
        for (int i = 0; i <= n; i++) pos[i].clear();
    }

    return 0;
}