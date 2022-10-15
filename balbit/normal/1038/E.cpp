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

#define int ll

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

const int maxn = 1e5+5;

int deg[4];
int par[4];
int mn[4];
int nodd[4];
bool seen[4];
ll S[4];
int nv[4];

int find(int x){
    if (par[x]==x) return x;
    return par[x]=find(par[x]);
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    REP(i,4) par[i]=i;
    vector<pair<pii, int> > E;
    REP(i,n){
        int a, b, w; cin>>a>>w>>b;
        a--; b--;
        E.pb({{a,b},w});
        if (a!=b) {
            deg[a]++; deg[b]++;
        }else{
            nv[a]+=w;
        }
        par[find(b)] = par[find(a)];
    }
    fill(mn, mn+4, inf);
    for (auto x : E){
        if (x.f.f!=x.f.s){
            int tmp = x.s;
            if (deg[x.f.f]==1){
                tmp+=nv[x.f.f];
            }
            if (deg[x.f.s]==1){
                tmp+=nv[x.f.s];
            }
            MNTO(mn[find(x.f.f)],tmp);
        }
        S[find(x.f.f)]+=x.s;
    }
    REP(i,4){
        if (deg[i]&1){
            nodd[find(i)]++;
        }
    }
    ll re = 0;
    REP(i,4){
        if (seen[find(i)]) continue;
        seen[find(i)]=1;
        int b = find(i);
        if (nodd[b]>2){
            assert(nodd[b]==4);
            MXTO(re, S[b]-mn[b]);
        }else{
            MXTO(re, S[b]);
        }
    }
    cout<<re<<'\n';
}