#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector<pll> vpll; typedef vector<string> vs; typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight capacity, cost;
  Edge(int src_, int dst_, Weight capacity_, Weight cost_) :
    src(src_), dst(dst_), capacity(capacity_), cost(cost_) { }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

//flow
void createRev(const Graph& g, Graph &r) {
    r.assign(g.size(), Edges());
    each(i, g) each(j, *i) {
        r[j->src].pb(*j);
        r[j->dst].pb(Edge(j->dst, j->src, 0, -j->cost));
    }
}
pair<Weight, Weight> minimumCostFlow(const Graph &g_, int s, int t, int f){
    Graph g; createRev(g_, g);
    int n = g.size();
    vector<Weight> dist(n);
    vi prev(n);
    Matrix capacity(n, Array(n)), flow(n, Array(n));
    rep(i, n) each(e, g[i])
        capacity[e->src][e->dst] += e->capacity;
    pair<Weight, Weight> total = mp(0, 0);  // (cost, flow)

    while(f > 0){
        fill(all(dist), INF); dist[s] = 0;
        bool update;
        do {
            update = false;
            rep(u, n) if(dist[u] != INF) {
                each(e, g[u]) {
                    int v = e->dst; Weight cost = e->cost;
                    if(capacity[u][v] - flow[u][v] > 0 &&
                        dist[v] > dist[u] + cost){
                        dist[v] = dist[u] + cost;
                        prev[v] = u;
                        update = true;
                    }
                }
            }
        } while(update);
        if(dist[t] == INF) break;   //
        
        int d = f;
        for(int v = t; v != s; v = prev[v])
            d = min(d, capacity[prev[v]][v] - flow[prev[v]][v]);
        f -= d; total.first += d * dist[t]; total.second += d;
        for(int v = t; v != s; v = prev[v]){
            flow[prev[v]][v] += d; flow[v][prev[v]] -= d;
        }
    }
    return total;
}


#define X 1000000
char b[111];
int main() {
    scanf("%s", b);
    string t(b);
    int n;
    scanf("%d", &n);
    Graph g(n+26+2);
    int src = n+26, dst = n+26+1;
    map<char,int> m;
    each(i, t) m[*i] ++;
    each(i, m)
        g[src].pb(Edge(src, n+(i->first-'a'), i->second, -X));
    rep(i, n) {
        m.clear();
        scanf("%s", b);
        string s(b);
        each(j, s) m[*j] ++;
        int a;
        scanf("%d", &a);
        each(j, m) {
            int x = n+(j->first-'a');
            g[x].pb(Edge(x, i, j->second, i+1));
        }
        g[i].pb(Edge(i, dst, a, 0));
    }

    pii p = minimumCostFlow(g, src, dst, t.size());
    cerr << "p: " << p.first << ", " << p.second << endl;
    int r = -2;
    if(p.second != t.size()) {
        r = -1;
    }else {
        r = p.first - (-X * t.size());
    }
    printf("%d\n", r);
    return 0;
}