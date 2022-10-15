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

const int iinf = 1e9+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

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

const int maxn = 405;

ll dp[maxn][maxn];
ll a[maxn];

struct Ev{
    int f, c,r;
};
vector<Ev> qq[maxn];

signed main(){
    IOS();
    int n, m; cin>>n>>m;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
    }

    for (int cnt = 0; cnt < m; ++cnt) {
        int s,f,c,r; cin>>s>>f>>c>>r; --s; --f;
        ++r; r = min(r, n);
        qq[s] .pb ({f,c,r});
    }

    ll V = 0;

    for (int frm = 0; frm<n; ++frm) {
        dp[0][frm] = 0;
        for (int r = 1; r<=n; ++r) {
            int j = frm;
            for (int i = frm; i<n; ++i) {
                while (j < i && max(dp[r-1][j+1], a[i] - a[j+1]) <= max(dp[r-1][j], a[i] - a[j])) ++j;
                dp[r][i] = max(dp[r-1][j], a[i] - a[j]);
            }
        }
        for (Ev & e : qq[frm]) {
            V = max(V, dp[e.r][e.f] * (ll)e.c);
        }
    }

//    bug(dp[0][2][2]);

//    int m; cin>>m;
    cout<<V<<endl;

}