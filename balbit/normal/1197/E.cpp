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

const int iinf = 1<<30;
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

int mn[maxn*2];
ll pos[maxn*2];

map<int, int> mp;

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fill(mn,mn+maxn*2,iinf);
    int n; cin>>n;
    vector<pii> edge;
    vector<int> app;
    int mnlb = 0;
    REP(i,n){
        int a, b; cin>>a>>b;
        swap(a,b);
        app.pb(a); app.pb(b);
        edge.pb({a,b});
        MXTO(mnlb,a);
    }
    SORT_UNIQUE(app);
    vector<vector<pii>> g(SZ(app));
    REP(i,SZ(app)){
        mp[app[i]]=i;
        if (i){
            g[i-1].pb({i,app[i]-app[i-1]});
        }
    }
    for (pii x : edge){
        g[mp[x.f]].pb({mp[x.s],0});
    }
    ll re = 0;
    // debug(mnlb);
    pos[0]=1;
    mn[0]=0;
    int ttm = iinf;
    REP(i,SZ(app)){
        for (pii xx : g[i]){
            if (mn[xx.f] == mn[i] + xx.s){
                pos[xx.f] += pos[i]; pos[xx.f]%=mod;
            }
            if (mn[xx.f] > mn[i] + xx.s){

                mn[xx.f] = mn[i] + xx.s;
                pos[xx.f] = pos[i];
            }
        }
        if (i > mp[mnlb]) {
            MNTO(ttm, mn[i]); 
        }
    }
    // debug(ttm);
    FOR(i,mp[mnlb]+1,SZ(app)){
        if (mn[i]==ttm){
            re+=pos[i]; re%=mod;
        }
    }
    cout<<re<<'\n';
}