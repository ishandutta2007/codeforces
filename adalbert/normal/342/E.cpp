//#pragma GCC optimize("O2147483647")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx,avx")
//#pragma GCC optimze("fast-math")
//#define GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include "testlib.h"
#define rep(i, j, k) for (int i = (int)(j); i<(int)(k); i++)
#define per(i, j, k) for (int i = (int)(k); i>=(int)(j); i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define fprd fprintf(stderr,
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
//#define int ll
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

const int N=1e5+5;
int sz[N],del[N],ans[N],parent[N],dep[N],depA[N],par[N][22];
vi g[N];

void Sz(int v, int p=-1) {
    sz[v]=1;
    for (auto i:g[v])
        if (!del[i]&&i!=p)
            Sz(i,v), sz[v]+=sz[i];
}

int Centroid(int v,int p,int n) {
    for (auto i:g[v]) {
        if (!del[i] && i!=p && sz[i]>n/2)
            return Centroid(i,v,n);
    }
    return v;
}

void Decompose(int v,int deep=0) {
    Sz(v);
    del[v]=1;
    for (auto i:g[v])
        if (!del[i]) {
            int c=Centroid(i,v,sz[i]);
            parent[c]=v;
            dep[c]=deep+1;
            Decompose(c,deep+1);
        }
}

int dist(int u,int v) {
    int U=u,V=v;
    for (int i = 20; i >= 0; i--)
    if (depA[u] - (1<<i) >= depA[v]) {
        u = par[u][i];
    }

    for (int i = 20; i >= 0; i--)
    if (depA[v] - (1<<i) >= depA[u]) {
        v = par[v][i];
    }

    for (int i = 20; i >= 0; i--)
        if (par[u][i] != par[v][i]) {
            v = par[v][i];
            u = par[u][i];
        }

    while (u!=v) u=par[u][0],v=par[v][0];
    return depA[U]+depA[V]-2*depA[u];
}

void Paint(int v) {
    int ok=1;
    for (int cur=v;parent[cur]!=cur||ok;cur=parent[cur],ok&=(parent[cur]!=cur))
        ans[cur]=min(ans[cur],dist(cur,v));
}

int Dist(int v) {
    int answ=1e9,ok=1;
    for (int cur=v;parent[cur]!=cur||ok;cur=parent[cur],ok&=(parent[cur]!=cur)) {
        answ=min(answ,ans[cur]+dist(v,cur));
    }
    assert(answ!=1e9);
    return answ;
}

void dfsDeep(int v,int h=1,int p=-1) {
    depA[v]=h;
    if (p == -1)
        par[v][0] = 0; else
        par[v][0] = p;
    for (int i = 1; i <= 20; i++) {
        par[v][i] = par[par[v][i-1]][i-1];
    }
    for (auto i:g[v]) if (i!=p) {
        dfsDeep(i,h+1,v);
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
        if (u>v) swap(u,v);
    }
    Sz(1);
    dfsDeep(1);
    rep(i,0,N) ans[i]=1e9;
    Decompose(Centroid(1,-1,sz[1]));
    Paint(1);
    while (m--) {
        int type,x;
        scanf("%d%d",&type,&x);
        if (type==1) Paint(x);
        else printf("%d\n",Dist(x));
    }
}

/*
10 1
10 7
10 6
1 4
7 8
5 1
6 2
7 5
6 3
7 9

2 2
*/