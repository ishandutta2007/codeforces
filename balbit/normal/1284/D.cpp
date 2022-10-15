#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+87;


void GG(){cout<<"-1\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

struct seg{
    ll l, r;
    ll id;
};

ll B = 200003;

bool cmp(seg a, seg b) {
    if (a.r!=b.r) return a.r<b.r;
    return a.id<b.id;
}
bool cmpl(seg a, seg b) {
    if (a.l!=b.l) return a.l<b.l;
    return a.id<b.id;
}
ll hv[maxn];
ll pB[maxn];

void solve(vector<ll> &ans, vector<seg> &v) {
    sort(ALL(v), cmpl);
    int n = SZ(v);
    vector<ll> valat(n+1);
    REP(i,n) {
        valat[i+1] = (valat[i] + hv[v[i].id]) % mod;
    }
    REP(i,n){
        seg tmp = {v[i].r,-1,10000000000000ll};
        int it = lower_bound(ALL(v), tmp, cmpl)-v.begin()-1;
        ans[v[i].id] += valat[it+1];
        while (ans[v[i].id]>=mod) ans[v[i].id] -= mod;
    }
}

void solve2(vector<ll> &ans, vector<seg> &v) {
    sort(ALL(v), cmp);
    int n = SZ(v);
    vector<ll> valat(n+1);
    REP(i,n) {
        valat[i+1] = (valat[i] + hv[v[i].id]) % mod;
    }
    REP(i,n) {
        seg tmp = {-1,v[i].l-1,10000000000000ll};
        int it = lower_bound(ALL(v), tmp, cmp)-v.begin()-1;
        ans[v[i].id] -= valat[it+1];
        while (ans[v[i].id]<0) ans[v[i].id] += mod;
    }
}



signed main(){
    IOS();
    int n; cin>>n;
    pB[0] = 1;
    REP(i,n) {
        pB[i+1] = pB[i] * B % mod;
        hv[i] = (pB[i] * (i) + 1)%mod;
    }
    vector<seg> va, vb;
    REP(i,n) {
        int a, b, c, d; cin>>a>>b>>c>>d;
        va.pb({a,b,i});
        vb.pb({c,d,i});
    }
    vector<ll> a1(n), a2(n);
    solve(a1,va);
    solve(a2,vb);

    solve2(a1,va);
    solve2(a2,vb);
    REP(i,n) {
        a1[i] = (a1[i]%mod+mod)%mod;
        a2[i] = (a2[i]%mod+mod)%mod;
    }
#ifdef BALBIT
    REP(i,n) {
        cerr<<a1[i]<<" \n"[i==n-1];
    }
    REP(i,n) {
        cerr<<a2[i]<<" \n"[i==n-1];
    }
#endif
    if (a1!=a2) cout<<"NO\n";
    else cout<<"YES\n";
}
/*
10
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 2 2
1 1 1 1
1 1 1 1
1 1 1 1
*/