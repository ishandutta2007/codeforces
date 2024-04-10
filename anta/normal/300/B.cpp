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
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

struct UnionFind {
    vector<int> data;
    UnionFind(int size_) : data(size_, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionFind uf(n);
    rep(i, m) {
        int a, b;
        scanf("%d%d", &a, &b); a --, b --;
        uf.unionSet(a, b);
    }
    vector<vi> groups[4];
    vector<vi> gg;
    rep(i, n) if(uf.size(i) > 3) goto bad;
    rep(i, n) if(uf.root(i) == i) {
        vi v;
        rep(j, n) if(uf.findSet(i, j)) v.pb(j);
        groups[uf.size(i)].pb(v);
    }
    rep(i, n/3) {
        vi g;
        if(!groups[3].empty()) {
            g = groups[3].back(); groups[3].pop_back();
        }else if(!groups[2].empty() && !groups[1].empty()) {
            g = groups[2].back(); groups[2].pop_back();
            g.pb(groups[1].back()[0]); groups[1].pop_back();
        }else if(groups[1].size() >= 3) {
            rep(k, 3) {
                g.pb(groups[1].back()[0]);
                groups[1].pop_back();
            }
        }else goto bad;
        gg.pb(g);
    }
    rep(i, n/3) {
        vi g = gg[i];
        printf("%d %d %d\n", g[0]+1, g[1]+1, g[2]+1);
    }
    return 0;
bad:
    puts("-1");
    return 0;
}