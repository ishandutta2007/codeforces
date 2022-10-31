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
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector<pll> vpll; typedef vector<string> vs;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
    Edge(int src_, int dst_, Weight weight_) : src(src_), dst(dst_), weight(weight_) { }
    Edge(int dst_, Weight weight_) : src(-2), dst(dst_), weight(weight_) { }
};
bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void dijkstra(const Graph &g, int start,
    vector<Weight> &dist) {
    int n = g.size();
    dist.assign(n, INF); dist[start] = 0;
    vi prev(n, -1);
    priority_queue<Edge> q;
    for (q.push(Edge(-2, start, 0)); !q.empty(); ) {
        Edge e = q.top(); q.pop();
        if (prev[e.dst] != -1) continue;
            prev[e.dst] = e.src;
            each(f,g[e.dst]) {
                if (dist[f->dst] > e.weight+f->weight) {
                dist[f->dst] = e.weight+f->weight;
                q.push(Edge(f->src, f->dst, e.weight+f->weight));
            }
        }
    }
}

int main() {
    int n;
    int x0, y0, x1, y1;
    vector<pair<int,pair<int,int> > > v;
    cin >> y0 >> x0 >> y1 >> x1;
    cin >> n;
    rep(i, n) {
        int o, a, b;
        cin >> o >> a >> b;
        v.pb(mp(o,mp(a,b)));
    }
    sort(all(v));
    map<pair<int,int>,int> m;
    int t = 0;
    static const int dy[4]={0,-1,-1,-1},dx[4]={-1,0,-1,1};
    Graph g;
    each(i, v) {
        rer(j, i->second.first, i->second.second) {
            if(m.count(mp(i->first, j))) continue;
            int q = m[mp(i->first, j)] = t ++; g.pb(Edges());
            rep(d, 4) if(m.count(mp(i->first+dy[d], j+dx[d]))) {
                g[q].pb(Edge(q, m[mp(i->first+dy[d], j+dx[d])], 1));
            }
        }
    }
    Graph gg(t);
    rep(i, t) each(j, g[i]) {
        gg[j->src].pb(Edge(j->src, j->dst, 1));
        gg[j->dst].pb(Edge(j->dst, j->src, 1));
    }
    int r = -1;
    if(!m.count(mp(y0, x0))) r = -999;
    else if(!m.count(mp(y1, x1))) r = -999;
    else {
        vi d;
        dijkstra(gg, m[mp(y0, x0)], d);
        r = d[m[mp(y1, x1)]];
        if(r == INF) r = -1;
    }
    cout << r << endl;
    return 0;
}