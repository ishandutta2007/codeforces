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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


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

const int maxn = 505;

int lb[maxn], rb[maxn], wei[maxn], str[maxn],val[maxn];
int dp[505][1002];
vector<int> atr[maxn*2];

struct Box{
    int l,r,w,s,v;
};

signed main(){
    IOS();
    int n, S; cin>>n>>S;
    vector<Box> inp;
    for (int i = 0; i<n; ++i){
        int l,r,w,s,v;
        cin>> l>>r>>w>>s>>v;
        inp.pb({l,r,w,s,v});
    }
    inp.pb({0,2*n,0,S,0});
    sort(ALL(inp),[&](Box a, Box b){return a.r!=b.r?a.r<b.r:a.l>b.l;});
    ++n;
    for (int i = 0; i<n; i++){
        tie(lb[i],rb[i],wei[i],str[i],val[i]) = tie(inp[i].l,inp[i].r,inp[i].w,inp[i].s,inp[i].v);
        atr[rb[i]].pb(i);
    }
    for (int i = 0; i<n; i++){
        for (int w = 0; w<=S; w++) {
            if (w > str[i]) {
                dp[i][w] = dp[i][w-1]; continue;
            }
            vector<int> tdp(2*n+1);
            for (int it = lb[i]+1; it<=rb[i]; ++it){
                tdp[it] = tdp[it-1];
                for (int j : atr[it]){
                    if (lb[j] >= lb[i] && j!=i && w-wei[j]>=0){
                        MX(tdp[it], tdp[lb[j]] + dp[j][w-wei[j]]);
                    }
                }
            }
            dp[i][w] = max(tdp[rb[i]] + val[i],w>0?dp[i][w-1]:0);
        }
    }
    cout<<dp[n-1][S]<<endl;
}