#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

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

const int maxn = 2000+5;

ll dp[maxn][maxn][2]; // 0: To the right, m
int nr[maxn][maxn][2]; //1: Down , n
bool g[maxn][maxn];
ll sumr[maxn], sumd[maxn]; // Sum OF things going down
ll lastr[maxn];
ll lastd[maxn];

ll f(ll &x){
    while (x>=mod) x-=mod;
    return x;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    if (n==m&&m==1) {
        cout<<1<<endl; return 0;
    }
    REP(i,n) REP(j,m) {
        char c;
        cin>>c; g[i][j] = (c=='R');
    }
    // RREP(i,n) RREP(j,m){
    //     // if (!i) break; if (!j) break;
    //     if (i)nr[i-1][j][1]=nr[i][j][1] + g[i][j];
    //     if (j)nr[i][j-1][0]=nr[i][j][0] + g[i][j];
    // }
    // REP(i,n) REP(j,m){
    //     cout<<nr[i][j][0]<<" \n"[j==m-1];
    // }
    // cout<<endl;
    REP(i,n) lastr[i] = m;
    REP(i,m) lastd[i] = n;
    RREP(i,n) {
        RREP(j,m){
            // cout<<i<<' '<<j<<endl;
            
            if (g[i][j]){
                lastr[i]--; lastd[j]--;
            }

            // cout<<' '<<lastr[i]<<' '<<lastd[i]<<endl;
            if(lastr[i]==j && lastd[j]==i) continue;
            if (i==n-1 && j==m-1) {
                dp[i][j][0] = dp[i][j][1] = 1; 
                sumr[i] += dp[i][j][1];f(sumr[i]);
                sumd[j] += dp[i][j][0];f(sumd[j]);
                continue;
            }
            dp[i][j][0] = sumr[i];
            dp[i][j][1] = sumd[j];
            sumr[i] += dp[i][j][1]; f(sumr[i]);
            sumd[j] += dp[i][j][0]; f(sumd[j]);
            // cout<<"DP: "<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
            if (g[i][j]){
                sumr[i] -= dp[i][lastr[i]][1]-mod; f(sumr[i]);
                sumd[j] -= dp[lastd[j]][j][0]-mod; f(sumd[j]);
            }
        }
    }
    cout<<(dp[0][0][0]+dp[0][0][1])%mod<<endl;
}