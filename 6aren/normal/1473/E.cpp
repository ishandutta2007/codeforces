#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 200005;

int n, m;
vector<pair<int, int>> g[N];
long long d[N][4];
bool done[N][4];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) d[i][j] = 1e18;
    }
    d[1][0] = 0;
    struct Data {
        int dis, u, st;
        Data(int dis, int u, int st) : dis(dis), u(u), st(st) {} 
        bool operator > (Data other) {
            return dis < other.dis;
        }
    };
    struct Cmp {
        bool operator()(const Data &x, const Data &y) {
            return x.dis > y.dis;
        }
    };
    priority_queue<Data, vector<Data>, Cmp> pq;
    pq.emplace(0, 1, 0);
    while (!pq.empty()) {
        auto foo = pq.top();
        pq.pop();
        int u = foo.u;
        int dis = foo.dis;
        int st = foo.st;
        if (done[u][st]) continue;
        done[u][st] = 1;
        for (auto e : g[u]) {
            int len = e.second;
            int v = e.first;
            if (((st >> 1) & 1) == 0) {
                int nst = st + 2;
                int nDis = dis + 2 * len;
                if (d[v][nst] > nDis) {
                    d[v][nst] = nDis;
                    pq.emplace(nDis, v, nst);
                }
            }
            if ((st & 1) == 0) {
                int nst = st + 1;
                int nDis = dis;
                if (d[v][nst] > nDis) {
                    d[v][nst] = nDis;
                    pq.emplace(nDis, v, nst);
                }
            }
            if (st == 0) {
                int nst = 3;
                int nDis = dis + len;
                if (d[v][nst] > nDis) {
                    d[v][nst] = nDis;
                    pq.emplace(nDis, v, nst);
                }
            }
            {
                int nst = st;
                int nDis = dis + len;
                if (d[v][nst] > nDis) {
                    d[v][nst] = nDis;
                    pq.emplace(nDis, v, nst);
                }
            }
        }
    } 
    for (int i = 2; i <= n; i++) {
        cout << d[i][3] << ' ';
    }
    cout << '\n';
    return 0;
}