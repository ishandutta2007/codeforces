#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
//#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
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

const int maxn = 1e6+5;

int ps[maxn+maxn];
bool has[maxn];

bool solve(){
    int n; cin>>n;
    int C; cin>>C;
    REP(i, C+1) has[i] = 0, ps[i] = 0;
    REP(i,n) {
        int x; cin>>x; has[x] = 1;
    }
    for (int i = 1; i<=C; ++i) {
        if (has[i]) {
            int sq = min(i, (int)sqrt(i) + 2);
            for (int j = 1; j<=sq; ++j) {
                if (has[j] && !has[i/j]) {
                    bug(i, j, "deaddd");
                    return 0;
                }
            }
        }
    }
    int mo = min(C, (int)sqrt(C) + 5);
    for (int c = 1; c<mo; ++c) {
        if (!has[c]) {
            for (int b = 1; b*c<=C; ++b) {
                if (has[b]) {
                    ++ps[b*c]; --ps[b*c+b];
                }
            }
        }
    }
    REP1(i, C) {
        ps[i] += ps[i-1];
        if (ps[i] > 0 && has[i]) {
            bug(i, "dead");
            return 0;
        }
    }
    return 1;
}

signed main(){
    IOS();


    int _T; cin>>_T;
    while (_T--) {
        cout<<(solve()?"Yes":"No")<<endl;
    }

}