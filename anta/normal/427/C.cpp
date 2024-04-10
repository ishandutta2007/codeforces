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

void visit(const vector<vector<int> > &g, int v,
        vector<int> &scccolor, int &colors,
        vector<int> &S, vector<char> &inS,
        vector<int> &low, vector<int> &num, int& time) {
    low[v] = num[v] = ++time;
    S.push_back(v); inS[v] = true;
    each(e, g[v]) {
        int w = *e;
        if (num[w] == 0) {
            visit(g, w, scccolor, colors, S, inS, low, num, time);
            low[v] = min(low[v], low[w]);
        } else if (inS[w])
            low[v] = min(low[v], num[w]);
    }
    if (low[v] == num[v]) {
        while (1) {
            int w = S.back(); S.pop_back(); inS[w] = false;
            scccolor[w] = colors;
            if (v == w) break;
        }
        colors ++;
    }
}
int stronglyConnectedComponents(const vector<vector<int> >& g,
        vector<int>& scccolor) {
    const int n = g.size();
    vector<int> num(n), low(n);
    vector<int> S;
    vector<char> inS(n);
    scccolor.resize(n);
    int time = 0, colors = 0;
    rep(u, n) if (num[u] == 0)
        visit(g, u, scccolor, colors, S, inS, low, num, time);
    return colors;
}

template<int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt(): x(0) { }
    ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    int get() const { return (int)x; }
    
    ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        return ModInt(u);
    }
    
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
typedef ModInt<1000000007> mint;

int c[100000];
int main() {
    int n;
    scanf("%d", &n);
    rep(i, n) scanf("%d", &c[i]);
    vector<vi> g(n);
    int m;
    scanf("%d", &m);
    rep(i, m) {
        int u, v;
        scanf("%d%d", &u, &v), u --, v --;
        g[u].pb(v);
    }
    vi color;
    int S = stronglyConnectedComponents(g, color);
    vi minc(S, INF);
    rep(i, n) amin(minc[color[i]], c[i]);
    ll mincost = 0;
    rep(i, S) mincost += minc[i];
    vi mincnt(S, 0);
    rep(i, n) if(c[i] == minc[color[i]]) mincnt[color[i]] ++;
    mint ans = 1;
    rep(i, S) ans *= mincnt[i];
    cout << mincost << " " << ans.get() << endl;
    return 0;
}