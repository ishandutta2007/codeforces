#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}


int fa[21][maxn];
int sz[maxn];
int dep[maxn]; // Dep of root is 1
vector<int> graph[maxn];

void dfs1(int at){
    sz[at]=1;
    for (int &v : graph[at]){
        if (!dep[v]){
            dep[v]=dep[at]+1;
            fa[0][v]=at;
            dfs1(v);
            sz[at]+=sz[v];
        }
    }
}

void build(){
    FOR(i,1,21){
        FOR(j,0,maxn){
            fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    }
}

int kth(int a, int k){ // kth ancestor of a
    int j = 0;
    while (k){
        if (k&1) a = fa[j][a];
        j++;
        k/=2;
    }
    return a;
}

int LCA(int a, int b){
    if (dep[a]<dep[b]) swap(a,b);
    int need = dep[a]-dep[b];
    a = kth(a,need);
    RREP(j,20){
        if (fa[j][a]!=fa[j][b]){
            a = fa[j][a];
            b = fa[j][b];
        }
    }
    if (a!=b) return fa[0][a];
    return a;
}



main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    REP(i,n-1){
        int a, b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dep[0]=1; dfs1(0); build();
    int m; cin>>m;
    while (m--){
        int a, b; cin>>a>>b; a--; b--;
        if (a==b) {cout<<n<<'\n'; continue;}
        if (dep[a]<dep[b]) swap(a,b);
        int lca = LCA(a,b);
        int dst = dep[a]+dep[b]-2*dep[lca];
        if (dst&1) {cout<<0<<'\n'; continue;}
        int c = kth(a,dst/2);
        int re = sz[c];
        if (dep[a]==dep[b]) {
            re = n;
            re-=sz[kth(b,(dst/2)-1)];
            re-=sz[kth(a,(dst/2)-1)];
        }else{
            re-=sz[kth(a,(dst/2)-1)];
        }
        cout<<re<<'\n';
    }

    
}

/*
5
1 2
1 3
3 4
4 5
2
2 5
2 3
*/