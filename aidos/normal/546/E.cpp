#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1 << 30);
const int maxn = (int) 1e3 + 10;

using namespace std;

struct edge{
    int a, b, cap, flow;
};
int s, t;
int p[maxn];
vector < int > g[maxn];
vector < edge > e;
int d[maxn];  

void add(int a, int b, int cap){
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].pb(e.size());
    e.pb(e1);
    g[b].pb(e.size());
    e.pb(e2);
}
bool bfs(){
    memset(d, -1, sizeof d);
    d[s] = 0;
    queue < int > q;
    q.push(s);
    while(!q.empty() && d[t] == -1){
        int x = q.front();
        q.pop();
        for(int i = 0 ; i < g[x].size();i++){
            int to = e[g[x][i]].b;
            if(d[to] == -1 && e[g[x][i]].flow < e[g[x][i]].cap){
                q.push(to);
                d[to] = d[x] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow){
    if(flow == 0) return 0;
    if(v == t) return flow;
    for( ; p[v] < g[v].size(); p[v]++){
        int id = g[v][p[v]], to=e[id].b;
        if(d[to] != d[v] + 1) continue;
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if(pushed > 0){
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}


int dinic(){
    int flow = 0;
    while(bfs()){
        memset(p, 0, sizeof p);
        int pushed = dfs(s, inf);
        while(pushed){
            flow+=pushed;
            pushed = dfs(s, inf);
        }
        //cout << "cur" << endl;
    }
    return flow;
}
int ans[222][222];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    int sum = 0, sum2 = 0;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        sum += x;
        add(0, i + 1, x);
        add(i+1, i + n + 1, 1000);
    }
    for(int i = 0, x; i < n; i++){
        cin >> x;
        sum2+= x;
        add(i+n + 1, 2 * n + 1, x);
    }
    s = 0;
    t = 2 * n + 1;
    for(int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        add(x, y + n, 1000);
        add(y, x + n, 1000);
    }
    int flow = dinic();
    //cout << flow << endl;
    if( sum  != sum2 || sum2 != flow){
        cout << "NO\n";
        return 0;
    }
    for(int i = n+1; i < t; i++){
        for(int j =0; j < g[i].size(); j++){
            int id=g[i][j], to =e[id].b;
            if(to <= n && e[id].flow < 0 ) ans[to][i-n] = -e[id].flow;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }









    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}