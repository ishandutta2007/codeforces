#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

int bipartiteMatching(const vector<vector<int> > &g) {
    int nleft = g.size(), nright = 0;
    each(es, g) if(!es->empty()) nright = max(nright, *max_element(es->begin(), es->end()) + 1);
    vi matchL(nleft, -1), matchR(nright, -1), prev(nleft), seen(nleft, -1);
    rep(i, nleft) {
        vi stk; stk.push_back(i);
        seen[i] = i; prev[i] = -1;
        while(!stk.empty()) {
            int v = stk.back(); stk.pop_back();
            each(ui, g[v]) {
                int u = *ui, j = matchR[u];
                if(j == -1) {
                    while(v != -1) {
                        matchR[u] = v;
                        swap(u, matchL[v]);
                        v = prev[v];
                    }
                    goto break_;
                }else if(seen[j] < i) {
                    seen[j] = i; prev[j] = v;
                    stk.push_back(j);
                }
            }
        }
        break_:;
    }
    return (int)matchL.size() - count(matchL.begin(), matchL.end(), -1);
}

int a[1000], b[1000];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, m) {
        scanf("%d%d", &a[i], &b[i]);
        a[i] --, b[i] --;
    }
    int ans = INF;
    vector<vi> g(n);
    rep(center, n) {
        rep(i, n) g[i].clear();
        int centeredges = 0, otheredges = 0;
        rep(i, m) {
            if(a[i] == center || b[i] == center) {
                centeredges ++;
            }else {
                g[a[i]].pb(b[i]);
                otheredges ++;
            }
        }
        int matching = bipartiteMatching(g);
        int cost = 0;
        cost += (n * 2 - 1) - centeredges;
        cost += otheredges - matching;
        cost += (n-1) - matching;
        ans = min(ans, cost);
//      cerr << center+1 << ": " << cost << "; " << centeredges << ", " << otheredges << ", " << matching << endl;
    }
    printf("%d\n", ans);
    return 0;
}