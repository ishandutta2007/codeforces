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

const int inf = (1 << 20) ;
const int maxn = (int) 5e5 + 100;

using namespace std;

struct edge {
    int a, b, cap, flow,id;
};
vector < edge > e;
vector < int > g[maxn];
int d[maxn];
int p[maxn];
int a[maxn];
int s, t;

void add(int a, int b, int cap, int id=-1){
    edge e1 = {a, b, cap, 0, id};
    edge e2 = {b, a, 0, 0, -1};
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
    while(d[t]==-1 && q.size() > 0){
        int x = q.front();
        q.pop();
        for(int i = 0; i < g[x].size(); i++){
            int id = g[x][i], to = e[id].b;
            if(d[to] == -1 && e[id].flow < e[id].cap){
                d[to] = d[x] + 1;
                q.push(to);
            }
        }
    }
    return d[t] != -1;
}
int dfs(int v, int flow){
    if(flow == 0) return 0;
    if( v == t ) {
        return flow;
    }

    for( ; p[v] < g[v].size(); p[v]++){
        int id = g[v][p[v]], to = e[id].b;
        if(d[to] != d[v] + 1) continue;
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if(pushed){
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic(){
    int flow=  0;
    while(bfs()){
        memset(p, 0, sizeof p);
        int pushed = dfs(s, inf);
        while(pushed){
            flow += pushed;
            pushed = dfs(s, inf);
            //if(pushed == inf) return flow;
        }
    }
    return flow;
}

int ans[maxn];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    for(int i = 0, x, y;  i < n; i++){
        scanf("%d %d\n", &x, &y);
        add(x, y + 200000, 1, i);
        a[x]++;
        a[y+200000]++;
    }
    
    s = 0;
    t = 400001;
    int cur = t + 1;
    int cur2= t+2;
    for(int i = 1; i <= 200000; i++){
        if(a[i] > 1){
            add(s, i, a[i]/2);
            add(cur, t, a[i]/2);
        }
        if(a[i] & 1) add(cur, i, 1);
    }
    for(int i = 200001; i <= 400000; i++){
        if(a[i] > 1){
            add(s, cur2, a[i]/2);
            add(i, t, a[i]/2);
        }
        if(a[i] & 1) add(i, cur2, 1);
    }
    add(cur2, cur, inf);
    //cout << s << " "<< t << endl;
    dinic();
    //return 0;
    for(int id = 0; id < e.size(); id++){
        if(e[id].id >=0){
            ans[e[id].id] = e[id].flow > 0;
        }
    }
    for(int i = 0; i < n; i++)
        if(ans[i]) printf("r");
        else printf("b");










    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}