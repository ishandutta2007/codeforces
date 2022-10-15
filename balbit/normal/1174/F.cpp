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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 2e5+5;

vector<int> g[maxn];

int fa[21][maxn];
int dep[maxn];
int sz[maxn];
int bigch[maxn];

void build(){
    FOR(i,1,21){
        REP(j,maxn){
            fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    }
}

void pdfs(int at){
    sz[at]=1;
    for (int v : g[at]){
        if (v!=fa[0][at]){
            fa[0][v]=at;
            dep[v]=dep[at]+1;
            pdfs(v);
            sz[at]+=sz[v];
        }
    }
    bigch[at]=-1;
    for (int v : g[at]){
        if (v!=fa[0][at]) if (sz[v]>(sz[at])/2){
            bigch[at]=v;
        }
    }
}

int kth(int a, int k){
    REP(i,21){
        if (k&(1<<i)){
            a = fa[i][a];
        }
    }
    return a;
}

bool killed[maxn];

int rtdst = -1;

void soldfs(int at, bool nbc) { // No big child
    if (dep[at] == rtdst){
        cout<<"! "<<at+1<<endl; return;
    }
    if (nbc){
        sz[at]-=sz[bigch[at]];
        killed[bigch[at]]=1;
        bigch[at]=-1;
        for (int v : g[at]){
            if (!killed[v] && v!=fa[0][at]){
                if (sz[v]>(sz[at])/2){
                    bigch[at]=v;
                }
            }
        }
    }
    if (bigch[at]==-1){
        cout<<"s "<<at+1<<endl;
        int to; cin>>to; to--;
        soldfs(to, 0);
    }
    else{
        int tat= at;
        while (bigch[tat]!=-1 && dep[tat]<rtdst){
            tat = bigch[tat]; 
            // cout<<bigch[tat]<<endl;
        }
        cout<<"d "<<tat+1<<endl;
        int mdst; cin>>mdst;
        if (mdst == rtdst-dep[tat]) {
            soldfs(tat, 0);
        }else{
            int df = mdst - (rtdst-dep[tat]); df/=2;
            tat = kth(tat, df);
            soldfs(tat, 1);
        }
    }
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    REP(i,n-1){
        int a,b ;cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    pdfs(0); build();
    cout<<"d "<<1<<endl; cin>>rtdst;
    soldfs(0,0);
}