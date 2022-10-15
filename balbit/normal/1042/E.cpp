#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast", "unroll-loops")
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
const ll mod = 998244353;


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

const int maxn = 1005;

ll ivt[maxn*maxn];

main(){ 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
    int n, m; cin>>n>>m; 
    // map<int, vector<pii> > mp; 
    vector<pair<int, pii> > mv;
    REP(i,n) REP(j,m){ 
        int x; cin>>x; mv.pb({x,{i,j}}); 
    } 
    sort(ALL(mv));
    ll dp = 0; 
    int tr, tc; cin>>tr>>tc; tr--; tc--; 
    // cout<<tr<<' '<<tc<<endl; 
    int nt = 0; 
    ll cc =0, rr=0, cs = 0, rs = 0; 
    ivt[1]=1;
    FOR(i,2,n*m+1){
        ivt[i] = ivt[mod%i] * (mod - mod/i) %mod;
    }
    REP(i, n*m){
        int it = i+1;
        while (it < n*m && mv[it].f==mv[i].f) it++;
        vector<ll> mm; 
        FOR(j, i, it){ 
            ll r = mv[j].s.f, c = mv[j].s.s; 
            if (nt){ 
                // debug(nt); 
                ll ans = ((dp + rs + cs - (r+r) * rr)%mod  - ((c+c) * cc) %mod ) % mod; 
                if (ans < 0) ans += mod;
                ans *= ivt[nt]; ans %=mod; 
                ans = (ans + (r*r)%mod + (c*c) % mod );
                ans %=mod;
                mm.pb(ans); 
                if (r==tr and c == tc) { 
                    cout<<ans<<endl; return 0; 
                } 
            } 
        } 
        for (ll &lol : mm) { 
            dp = (dp+lol); if (dp> mod) dp-= mod;
        } 
        // nt += v.size();
        FOR(j, i, it){ 
            ll r = mv[j].s.f, c = mv[j].s.s; 
            rs = (rs+r*r)%mod; 
            cs = (cs+c*c)%mod; 
            rr = (rr + r); if (rr>mod) rr-=mod;
            cc = (cc+c);  if (cc>mod) cc-=mod;
            nt++;
        }
        i = it-1;
    }

    cout<<0;
}