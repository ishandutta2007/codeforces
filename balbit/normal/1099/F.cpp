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

int n; ll T;

struct BIT{
    vector<ll> s;
    int MX = 0;
    ll QU(int e){
        e++; ll re = 0;
        while (e>0){
            re+=s[e]; e-=e&(-e);
        } return re;
    }
    void MO(int e, ll v){
        e++; 
        while (e<MX){
            s[e]+=v; e+=e&(-e);
        }
    }
    BIT(int len){
        s.resize(len+10); MX = len;
    }
};

ll cat[maxn], ct[maxn]; // Cookies at, cookie time
BIT ntm(1e6+5), nc(1e6+5); // Time, # of cookies
int par[maxn]; ll cl[maxn]; // Length of edge above this node
vector<int> ch[maxn];

ll dp[maxn]; // Max number of cookies you can eat, ending here
ll ans[maxn]; // Max number after cutting

ll mxc(ll tlef){
    ll l = 0, r = 1e6+2;
    while (l!=r){
        ll mid = (l+r)/2;
        if (ntm.QU(mid)<tlef){
            l=mid+1;
        }else{
            r = mid;
        }
        // cout<<l<<' '<<r<<endl;
    }
    tlef -= ntm.QU(l); 
    ll nadd = 0;
    if (tlef<0){
        if (l==0) return 0;
        nadd = (-tlef + l-1)/l;
        tlef += nadd *l; 
    }
    // debug(l);
    return max(nc.QU(l) - nadd,0ll);

}

void dfs(int at, ll tlef){
    tlef -= 2*cl[at];
    ntm.MO(ct[at], ct[at]*cat[at]);
    nc.MO(ct[at], cat[at]);
    // cout<<"DONE"<<endl;
    dp[at] = mxc(tlef); 
    for (int v : ch[at]){
        dfs(v, tlef);
    }
    ntm.MO(ct[at], -ct[at]*cat[at]);
    nc.MO(ct[at], -cat[at]);
}

ll re = 0;

void dfs2(int at){
    vector<ll> mv; ll mx = 0;
    for (int v : ch[at]){
        dfs2(v);
        mv.pb(dp[v]); MXTO(mx, dp[v]);
    }
    if (at) REP(i, SZ(mv)) {
        if (mv[i]==mx) {mv[i]=-1; break;} 
    }
    ll m2 = 0;
    REP(i, SZ(mv)) {MXTO(m2, mv[i]);}
    MXTO(dp[at], m2);
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>T;
    REP(i,n) cin>>cat[i];
    REP(i,n) cin>>ct[i];
    FOR(i,1,n){
        cin>>par[i]; par[i]--;
        ch[par[i]].pb(i); cin>>cl[i];
    }
    // cout<<"GO"<<endl;
    dfs(0, T); 
    dfs2(0);
    cout<<dp[0]<<endl;
    
}