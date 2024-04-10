#include <bits/stdc++.h>
#define int ll
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

const int maxn = 1e3+5;

int a[maxn][maxn];

int get(int n) {
    int r = 0, c = 0;
    int re = 0;
    while (1) {
        int R = r, C = c;
        while (R >= 0 && C < n) {
            re ^= a[R][C];
            bug(R,C);
            R -= 2; C += 2;
        }
        REP(t, 4) {
            if (r < n-1) ++r;
            else ++c;
        }
        if (c >= n) break;
    }
    return re;
}

signed main(){
    IOS();
    int _T; cin>>_T;
    while (_T--) {
        int n; cin>>n;
        REP(i,n) REP(j,n) cin>>a[i][j];
        int s1 = get(n);

        REP(i,n) REP(j,n) {
            if (i < n/2) swap(a[i][j], a[n-i-1][j]);
        }
        int s2 = get(n);
        bug(s1, s2);
        cout<<(s1^s2)<<endl;
    }


}