#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
vector<pii> g[maxn];
vector<int> mi[maxn];
void solve() {
    cin >> n >> x;
    int ans = -1;
    for(int i = 0; i < n; i++) {
        int l, r, cost;
        cin >> l >> r >> cost;
        g[r - l + 1].emplace_back(make_pair(r, cost));
    }
    for(int t = 0; t <= x; t++) {
        sort(g[t].begin(), g[t].end());
        for(int j = 0; j < g[t].size(); j++) {
            if(j == 0) mi[t].emplace_back(g[t][j].second);
            else mi[t].emplace_back(min(mi[t].back(), g[t][j].second));
        }
    }
    for(int t = 0; t <= x; t++) {
        for(auto d: g[t]) {
            int L = d.first - t;
            auto it = lower_bound(g[x-t].begin(), g[x-t].end(), make_pair(L, inf));

            if(it == g[x-t].begin()) continue;
            int pos = it-g[x-t].begin() - 1;
            int cur = d.second + mi[x-t][pos];
            if(ans == -1 || ans > cur) ans = cur;
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}