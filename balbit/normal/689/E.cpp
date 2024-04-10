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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
using namespace std;

#define int ll

const int maxn = 2e5+5;
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

int ps[maxn*2];
ll fac[maxn];

ll C(int a, int b){
    if (b>a) return 0 ;
    return fac[a] * inv(fac[a-b]) %mod * inv(fac[b]) % mod;
}

void build()
{
    fac[0]=1;
    FOR(i,1,maxn) fac[i] = fac[i-1] * i % mod;
}

map<int, int> mp;
map<int, int> dst;

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    build();
    int n, k; cin>>n>>k;
    vector<pii> v; vector<int> tp;
    REP(i,n){
        int a, b; cin>>a>>b;
        v.pb({a,b+1});
        tp.pb(a); tp.pb(b+1);
    }
    SORT_UNIQUE(tp);
    REP(i,SZ(tp)){
        mp[tp[i]]=i;
        if (i!=SZ(tp)-1) dst[i] = tp[i+1]-tp[i];
        else dst[i]=1000;
    }
    REP(i,n){
        ps[mp[v[i].f]]++; ps[mp[v[i].s]]--;
    }
    ll re = 0;
    REP(i,SZ(tp)){
        if (i) ps[i]+=ps[i-1];
        // debug(ps[i]);
        // debug(dst[i]);
        re+= C(ps[i],k) * dst[i]%mod;
        re%=mod;
    }
    cout<<re<<'\n';
    
}