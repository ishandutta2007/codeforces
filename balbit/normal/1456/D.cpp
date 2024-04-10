#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GGNO(){cout<<"NO\n"; exit(0);}
void GGYES(){cout<<"YES\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 5005+5;

int t[maxn], x[maxn], X[maxn];
int dp[maxn];
bool can[maxn][maxn];

//int s[maxn];
//
//ll QU(int e) {
//    ll re = 0;
//    for (++e; e>0; e-=e&-e) re += s[e];
//    return re;
//}
//
//void MO(int e, int v) {
//    for (++e; e<maxn; e+=e&-e) s[e] += v;
//}


signed main(){
    IOS();

    int n; cin>>n;
    vector<int> xp = {0};
    memset(dp, 0x3f, sizeof dp);
    REP1(i,n) {
        cin>>t[i]>>x[i];
         xp.pb(x[i]);
    }
    SORT_UNIQUE(xp);
    REP1(i,n) {
        X[i] = lower_bound(ALL(xp), x[i]) - xp.begin();
    }
    dp[0] = 0;
    for (int i = 0; i<=n; ++i) {
        for (int j = i; j<=n; ++j) {
            if (i == j) can[i][j] = 1;
            else{
                can[i][j] = can[i][j-1] && (t[j-1] + abs(x[j] - x[j-1]) <= t[j]);
            }
        }
    }
    for (int i = 0; i<=n; ++i) {
        bug(i, dp[i]);
        if (i==n) {
            if (dp[i]>t[i]) GGNO();
            else
                GGYES();
        }
        if (dp[i] > t[i]) continue;
        if (i) MX(dp[i], t[i-1]);
        for (int j = i; j<=n; ++j) {
            bool ok = 1;
            int tothat = max(t[i], dp[i] + abs(x[j] - x[i])); // when am I ready to add clone here
            if (j != i) {
                if (tothat > t[j] || tothat + abs(x[j] - x[i+1]) > t[i+1]) {
                    ok = 0; continue;
                }
                if (i+1<j-1 && !can[i+1][j-1]) {
                    ok = 0; continue;
                }
                if (ok) {
                    bug(i,j);

                    if (j == n) GGYES();
                    if (j == i+1) {
                        bug("HI");
                        MN(dp[j+1], tothat+abs(x[j] - x[j+1]));
                    }else{
                        MN(dp[j+1],t[j-1] + abs(x[j-1] - x[j+1]));
                    }
                }
            }else{
                MN(dp[i+1], dp[i] + abs(x[i+1] - x[i]));
            }
        }
    }
//    bug(dp[0]);
//    if (dp[0] == n) cout<<"YES"<<endl;
//    else cout<<"NO"<<endl;
}