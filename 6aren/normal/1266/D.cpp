#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 100005;

int n, m;
int in[N], out[N];
vector<ii> lai, lo;

main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        out[u] += w;
        in[v] += w;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] > out[i]) {
            lai.pb({i, in[i] - out[i]});
        }
        if (in[i] < out[i]) {
            lo.pb({i, out[i] - in[i]});
        }
    }
    int cur = 0;
    vector<pair<ii, int>> res;
    for (auto u : lo) {
        for (int i = cur; i < lai.size(); i++) {
            if (u.y <= lai[i].y) {
                res.pb({{u.x, lai[i].x}, u.y});
                lai[i].y -= u.y;
                if (lai[i].y == 0) cur++;
                break; 
            } else {
                res.pb({{u.x, lai[i].x}, lai[i].y});
                u.y -= lai[i].y;
                cur++;
            }
        }
    }
    cout << res.size() << endl;
    for (auto u : res) {
        cout << u.x.x << ' ' << u.x.y << ' ' << u.y << '\n';
    }
    return 0;
}