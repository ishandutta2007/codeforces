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
const ll mod = 998244353 ;


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

const int maxn = 1e4+5;
#define REP(i,n) for (int i = 0; i<n; ++i)
int a[maxn];
int ip[maxn], b[maxn];
int d[maxn];
int D[21][21];
int dp[1<<20];

signed main(){
    IOS();
    int n,k,l; cin>>n>>k>>l;
    REP(i,k){
        int x; cin>>x; --x;
        ip[x] = 1;
    }
    int N = 0;
    vector<int> pos;
    ++n;
    for (int i = 0; i<n; ++i) {
        b[i] = ip[i] ^ (i==0?0:ip[i-1]);
        if (b[i] == 1) {
            N++; pos.pb(i);
        }
    }
    if (N % 2 == 1) GG();
    REP(i,l) cin>>a[i];
    bug("HI");
    for (int i = 0; i<N; ++i) {
        memset(d, -1, sizeof d);
        d[pos[i]] = 0;
        queue<int> q ({pos[i]});
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int j = 0; j<l; ++j) {
                if (v + a[j] < n && d[v+a[j]] == -1) {
                    d[v+a[j]] = d[v] + 1;
                    q.push(v+a[j]);
                }
                if (v - a[j] >=0 && d[v-a[j]] == -1) {
                    d[v-a[j]] = d[v] + 1;
                    q.push(v-a[j]);
                }
            }
        }
        for (int j = 0; j<N; ++j) {
            D[i][j] = d[pos[j]];
            bug(D[i][j]);
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int msk = 1; msk < (1<<N); ++msk) {
        if (__builtin_popcount(msk) % 2 == 0) {
            int v = msk & (-msk);
            v = log2(v);
            for (int i = 0; i<N; ++i) {
                if (i != v && msk & (1<<i) && D[v][i] != -1) {
                    assert(D[v][i] == D[i][v]);
                    MN(dp[msk], dp[msk ^ (1<<i) ^ (1<<v)] + D[v][i]);
                }
            }
            bug(msk, v, dp[msk]);
        }
    }
    if (dp[(1<<N)-1] == 0x3f3f3f3f) cout<<-1<<endl;
    else cout<<dp[(1<<N)-1]<<endl;
}