#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int maxn = 3e5+5;

int g[21][21], w[21][21];
int mof[21][27];
int dp[21][1<<20];
int mskcol[21][27], sumcol[21][27], maxcol[21][27];
bool solo[21][21];
bool last[21][21];

signed main(){
    IOS();
    int n,m; cin>>n>>m;
    for (int i = 0; i<n; i++) for (int j = 0; j<m; j++) {
        char c;
        cin>>c;
        g[i][j] = c-'a';
    }
    for (int i = 0; i<n; i++) for (int j = 0; j<m; j++) {
        cin>>w[i][j];
    }

    for (int j = 0; j<m; j++) {
        for (int i = 0; i<n; i++) {
            sumcol[j][g[i][j]] += w[i][j];
            mskcol[j][g[i][j]] |= (1<<i);
            maxcol[j][g[i][j]] = max(maxcol[j][g[i][j]], w[i][j]);
        }
        for (int i = 0; i<n; i++) {
            if (mskcol[j][g[i][j]] == (1<<i)) {
                solo[i][j] = 1;
            }
            if ((mskcol[j][g[i][j]]) < (1<<(i+1))) {
                last[i][j] = 1;
            }
        }

    }
    memset(dp, 0x3f, sizeof dp);
    bug(dp[0][0]);
    dp[n-1][(1<<n)-1] = 0;
    for (int j = 0; j<m; j++) {
        for (int i = 0; i<n; i++) {
            int ibit = 1<<i;
            int frm = i-1 + (i==0?n:0);
            for (int msk = 0; msk < (1<<n); ++msk) {
                dp[i][msk] = dp[frm][msk];
                if (msk & ibit) {
                    dp[i][msk] = min(dp[i][msk],dp[frm][msk | ibit]);
                }else{
                    if (solo[i][j]) {
                        dp[i][msk] = min(dp[i][msk],dp[frm][msk^ibit]);
                    }else{
                        dp[i][msk] = min(dp[i][msk], dp[frm][msk^ibit] + w[i][j]);
//                        bug(msk, msk & ( ~ mskcol[j][g[i][j]] ));
//                        if (last[i][j])
                            dp[i][msk] = min(dp[i][msk], dp[frm] [msk | ( mskcol[j][g[i][j]] ) ]  + sumcol[j][g[i][j]] - maxcol[j][g[i][j]]);
                    }
                }
            }
        }
    }

    cout<<dp[n-1][0]<<endl;
}