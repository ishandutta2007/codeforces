#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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
#ifdef BALBIT
const int maxn = 1e4+5;
#else
const int maxn = 1e6+5;
#endif
int dp[7000][6000];
vector<ll> F;
vector<ll> P;
__gnu_pbds::gp_hash_table<ll, int> pos, pat;
int pp[maxn];
ll pof[maxn];
bool np[maxn]; // is prime power, not prime
vector<int> prms;
bool isprime(ll x){
    for (ll y : prms){
        if (x%y==0) return 0;
    }
    return 1;
}
bool ispow(ll x){
    for (ll y : prms){
        for (ll at = y; at <= x; at *= y) if (at == x) return 1;
    }
    return 0;
}
signed main(){
    IOS();
    np[0]=np[1]=1;
    for (int i = 2; i<maxn; i++){
        if (np[i]) continue;
        prms.pb(i);
        for (int j = i+i; j<maxn; j+=i) np[j]=1;
        for (ll j = i; j<maxn; j*=i){
            pp[j] = i;
        }
    }
    bug("DONE");
    ll A; cin>>A;
    REP1(i,floor(sqrt(A))){
        if (A%i==0){
            F.pb(i); if (i*i!=A) F.pb(A/i);
        }
    }
    sort(ALL(F));
    int m = SZ(F);
    REP(i,m){
        bug(i,F[i]);
        pos[F[i]] = i;
        if (F[i] < maxn){
            if (pp[F[i]-1]){
                bug(F[i], pp[F[i]-1]);
                P.pb(pp[F[i]-1]);
                pof[i] = pp[F[i]-1];
            }
        }
        else{
            if (isprime(F[i]-1) || ispow(F[i]-1)) {
                P.pb(F[i]-1);
                pof[i] = F[i]-1;
            }
        }
    }
    SORT_UNIQUE(P);
    int sp = SZ(P);

    vector<vector<ll> > mp(SZ(P));

    bug(sp, m);

    dp[0][sp]=1;
    REP(i,m){
        if (pof[i]) {
            int pofat = lower_bound(ALL(P),pof[i]) - P.begin();
            mp[pofat].pb(F[i]);
        }
        FOR(j,0,sp+1){
            if (i==0) {
                dp[i][j] = 1; continue;
            }
            if (j) dp[i][j] += dp[i][j-1];
            else continue;
            for (ll ff : mp[j-1]){
                if (F[i] % ff == 0){
//                    bug(F[i], "from", ff, pos[F[i]/ff], j-1);
                    dp[i][j] += dp[pos[F[i]/ff] ][j-1];
                }
            }
        }
    }
    cout<<dp[m-1][sp]<<endl;
}