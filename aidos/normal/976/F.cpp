#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;
int n1, n2, m;
struct edge{
    int to, cap, flow, id;
    edge() {

    }
    edge(int to, int cap, int id): to(to), cap(cap), flow(0), id(id){

    }
};
vector<int> g[maxn], G[maxn];
vector<edge> e;
void add_edge(int from, int to, int cap, int id) {
    g[from].push_back(e.size());
    e.push_back(edge(to, cap, id));
    g[to].push_back(e.size());
    e.push_back(edge(from, 0, -1));
}
pii A[maxn];
int s, t;
int T;
int u[maxn];
int cnt[maxn];
int dfs(int v) {
    if(v == t) return true;
    if(u[v] == T) return false;
    u[v] = T;
    for(int id: g[v]) {
        if(e[id].cap > e[id].flow && dfs(e[id].to)) {
            e[id].flow += 1;
            e[id^1].flow -= 1;
            return 1;
        }
    }
    return 0;
}
void max_flow() {
    T++;
    while(dfs(s)) {
        T++;
    }
}
void solve() {
    cin >> n1 >> n2 >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        y += n1;
        add_edge(x, y, 1, i);
        A[i] = make_pair(x, y);
        G[x].push_back(i);
        G[y].push_back(i);
    }
    int mi = inf;
    for(int i = 1; i <= n1 + n2; i++) {
        mi = min(mi, (int)G[i].size());
    }
    s = 0;
    t = n1 + n2 + 1;
    for(int it = 0; it <= mi; it++) {
        max_flow();
        for(int i = 1; i <= n1 + n2; i++) {
            cnt[i] = 0;
        }
        T++;
        vector<int> ans;
        for(edge &E: e) {
            if(E.id == -1) continue;
            if(E.flow == 0) continue;
            cnt[A[E.id].first]++;
            cnt[A[E.id].second]++;
            u[E.id] = T;
            ans.emplace_back(E.id);
        }
        for(int i = 0; i < m; i++) {
            if(u[i] == T) continue;
            if(cnt[A[i].first] >= it && cnt[A[i].second] >= it) continue;
            cnt[A[i].first]++;
            cnt[A[i].second]++;
            ans.emplace_back(i);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size();
        for(int v: ans) cout<<" "<<v + 1;
        cout << "\n";
        for(int i = 1; i <= n1 + n2; i++) {
            if(i <= n1) {
                add_edge(s, i, 1, -1);
            }else {
                add_edge(i, t, 1, -1);
            }
        }
    }
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