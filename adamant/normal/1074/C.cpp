#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> g[n];
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    int k1, k2;
    cin >> k1;
    int x[k1];
    for(int i = 0; i < k1; i++) {
        cin >> x[i];
    }
    cin >> k2;
    int y[k2];
    for(int i = 0; i < k2; i++) {
        cin >> y[i];
    }
    
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n], y[n];
    
    int maxx = -inf, maxy = -inf;
    int minx = inf, miny = inf;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        maxx = max(maxx, x[i]);
        maxy = max(maxy, y[i]);
        minx = min(minx, x[i]);
        miny = min(miny, y[i]);
    }
    int p[4][n];
    iota(p[0], p[0] + n, 0);
    iota(p[1], p[1] + n, 0);
    iota(p[2], p[2] + n, 0);
    iota(p[3], p[3] + n, 0);
    sort(p[0], p[0] + n, [&](int a,  int b) {return x[a] < x[b];});
    sort(p[1], p[1] + n, [&](int a,  int b) {return x[a] > x[b];});
    sort(p[2], p[2] + n, [&](int a,  int b) {return y[a] < y[b];});
    sort(p[3], p[3] + n, [&](int a,  int b) {return y[a] > y[b];});
    vector<int> cands;
    for(int z = 0; z < 4; z++) {
        for(int i = 0; i < 3; i++) {
            cands.push_back(p[z][i]);
        }
    }
    sort(all(cands));
    int tri_ans = 0;
    cands.erase(unique(all(cands)), end(cands));
    for(int i = 0; i < cands.size(); i++) {
        for(int j = 0; j < cands.size(); j++) {
            for(int k = 0; k < n; k++) {
                if(i == j || cands[j] == k || cands[i] == k) {
                    continue;
                }
                int MAX = max({x[cands[i]], x[cands[j]], x[k]});
                int MIX = min({x[cands[i]], x[cands[j]], x[k]});
                int MAY = max({y[cands[i]], y[cands[j]], y[k]});
                int MIY = min({y[cands[i]], y[cands[j]], y[k]});
                tri_ans = max(tri_ans, 2 * (MAX - MIX + MAY - MIY));
            }
        }
    }
    cout << tri_ans << ' ';
    for(int i = 4; i <= n; i++) {
        cout << 2 * (maxx - minx + maxy - miny) << ' ';
    }
    /*
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    * */
    return 0;
}