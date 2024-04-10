#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (int)200200;
const ll inf = (1ll<<50);
int n, m;
vector< pair<int, int> > g[maxn];
ll d[maxn][4];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 4; j++) d[i][j] = inf;
    }
    d[1][0] = 0;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    priority_queue< pair<ll, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(1, 0)));
    while(pq.size() > 0) {
        ll dis = -pq.top().first;
        int v = pq.top().second.first;
        int mask = pq.top().second.second;
        pq.pop();
        if(d[v][mask] < dis) continue;
        for(auto x: g[v]) {
            if(d[x.first][mask] > d[v][mask] + x.second) {
                d[x.first][mask] = d[v][mask] + x.second;
                pq.push(make_pair(-d[x.first][mask], make_pair(x.first, mask)));
            }

            if((mask & 1) == 0 && d[x.first][mask|1] > d[v][mask]) {
                d[x.first][mask|1] = d[v][mask];
                pq.push(make_pair(-d[x.first][mask|1], make_pair(x.first, mask|1)));
            }
            if((mask & 2) == 0&&d[x.first][mask|2] > d[v][mask] + 2*x.second) {
                d[x.first][mask|2] = d[v][mask] + x.second * 2;
                pq.push(make_pair(-d[x.first][mask|2], make_pair(x.first, mask|2)));
            }
            if(mask == 0 && d[x.first][3] > d[v][mask] + x.second) {
                d[x.first][3] = d[v][mask] + x.second;
                pq.push(make_pair(-d[x.first][3], make_pair(x.first, 3)));
            }
        }
    }
    for(int i = 2; i <= n; i++) cout << d[i][3] << " ";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}