#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;

struct edge{
    int to, cap, flow, cost;
    edge(){

    }
    edge(int _to, int _cap, int _cost) {
        to = _to;
        cap = _cap;
        flow = 0;
        cost = _cost;
    }
};
vector<edge> e;
vector<int> g[maxn];
void add_edge(int from, int to, int cap, int cost) {
    g[from].push_back(e.size());
    e.push_back(edge(to, cap, cost));
    g[to].push_back(e.size());
    e.push_back(edge(from, 0, -cost));
}
int s, t;
int dis[maxn];
int fr[maxn];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int ans = 0;
int spfa() {
    for(int i = 0; i <= t; i++) {
        dis[i] = inf;
        fr[i] = -1;
    }
    queue <int> q;
    dis[s] = 0;
    q.push(s);
    while(q.size() > 0) {
        int v = q.front();
        q.pop();
        for(int to: g[v]) {
            edge &o = e[to];
            if(o.cap - o.flow == 0) continue;
            if(dis[o.to] > dis[v] + o.cost) {
                dis[o.to] = dis[v] + o.cost;
                fr[o.to] = to;
                q.push(o.to);
            }
        }
    }
    if(fr[t] == -1) {
        return 0;
    }
    int v = t;
    vector<int> edges;
    while(fr[v] != -1) {
        edges.push_back(fr[v]);
        v = e[fr[v]^1].to;
    }
    int mi = inf;
    for(int id: edges) {
        mi = min(mi, e[id].cap - e[id].flow);
    }
    for(int id: edges) {
        e[id].flow += mi;
        e[id ^ 1].flow -= mi;
        ans += e[id].cost * mi;
    }
    return true;
}
int n, m;
int a[88][88];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    s = 0;
    t = n * m + 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int id = i * m + j + 1;
            if((i + j) % 2 == 0) {
                for(int t = 0; t < 4; t++) {
                    int x = i + dx[t];
                    int y = j + dy[t];
                    if(x >= 0 && x < n && y >= 0 && y < m) {
                        int o = x * m + y + 1;
                        if(a[x][y] == a[i][j]) add_edge(id, o, 1, 0);
                        else add_edge(id, o, 1, 1);
                    }
                }
                add_edge(s, id, 1, 0);
            } else {
                add_edge(id, t, 1, 0);
            }
        }
    }
    while(spfa()) {

    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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