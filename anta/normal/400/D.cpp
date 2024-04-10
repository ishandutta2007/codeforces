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
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct UnionFind {
    vector<int> data;
    UnionFind() { }
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

int c[500], csum[501];
int g[500][500];
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    UnionFind uf(n);
    rep(i, k) {
        scanf("%d", &c[i]);
        csum[i+1] = csum[i] + c[i];
    }
    mset(g, INF);
    rep(i, m) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        u --, v --;
        int uk = upper_bound(csum, csum+k, u) - csum - 1;
        int vk = upper_bound(csum, csum+k, v) - csum - 1;
//      cerr << u << ", " << v << ": " << uk << ", " << vk << endl;     if(x == 0 && uk == vk)
        if(x == 0)
            uf.unionSet(u, v);
        amin(g[uk][vk], x);
        amin(g[vk][uk], x);
    }
    bool ok = true;
    rep(i, k) {
        rep(j, c[i])
            ok &= uf.findSet(csum[i], csum[i] + j);
        g[i][i] = 0;
    }
    if(!ok) {
        puts("No");
        return 0;
    }
    rep(kk, k) rep(i, k) rep(j, k)
        amin(g[i][j], g[i][kk] + g[kk][j]);
    puts("Yes");
    rep(i, k) {
        rep(j, k) {
            if(j != 0) putchar(' ');
            printf("%d", g[i][j] == INF ? -1 : g[i][j]);
        }
        puts("");
    }
    return 0;
}