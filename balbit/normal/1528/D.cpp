#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define int ll
#define y1 zck_is_king
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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 600+5;

ll d[maxn];
int g[maxn][maxn];
bool done[maxn];

int nice[maxn];int n;
inline int F(int x) {
    return x>=n?x-n:x;
}

void go(int s) {
    memset(done, 0, sizeof done);
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    REP(rrr, n) {
        int v = -1;
        REP(i,n) {
            if (!done[i] && (v == -1 || d[i] < d[v])) {
                v = i;
            }
        }
        bug(s, v);
        if (d[v] == inf) break;
        done[v] = 1;
        int sh = d[v] % n;
        memset(nice, 0x3f, sizeof nice);
        for (int i = 0; i<n; ++i) {
            if (g[v][i] != -1) {
                MN(nice[F(i+sh)], g[v][i]);
            }
        }
        for (int i = 1; i<n*2; ++i) {
            MN(nice[F(i)], nice[F(i-1)]+1);
        }
        REP(i,n) {
            if (!done[i]) {
                if (d[i] > d[v] + nice[i]) {
//                    assert(nice[i] != 0);

                    d[i] = d[v] + nice[i];
                }
            }
        }
    }
}

signed main(){
    IOS();
    int m; cin>>n>>m;
    memset(g, -1, sizeof g);
    REP(i,m) {
        int a,b,c; cin>>a>>b>>c;
        g[a][b] = c;
    }
    REP(i,n) {
        go(i);
        REP(j,n) {
            cout<<d[j]<<" \n"[j==n-1];
        }
    }

}