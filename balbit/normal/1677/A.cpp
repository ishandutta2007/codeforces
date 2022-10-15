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

const int maxn = 1e5+5;

signed num[5005][5005];

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        REP(i,n) {
            cin>>a[i];
        }
        REP(i,n) {
            num[i][n] = 0;
            for (int j = n-1; j>=0; --j) {
                num[i][j] = num[i][j+1] + (a[j] < a[i]);
            }
        }
        ll re = 0;
        RREP(i,n) {
            int sum = 0;
            REP(j,i-1) {
                sum += a[j] < a[i];
                re += (ll) sum * num[j+1][i+1];
                bug(j,i,sum,num[j+1][i+1]);
            }
        }

//        REP(a,n) for (int b = a+1; b<n; ++b) {
//            re += num[0][a][b] * (ll) num[1][b][a];
//        }
        cout<<re<<endl;

    }

}