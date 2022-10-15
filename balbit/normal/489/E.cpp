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

const int maxn = 1e3+5;

int n,l;
int x[maxn], b[maxn];
double dp[maxn];
int frm[maxn];

bool ok(double M) {
    dp[0] = -M*b[0];
    for (int i = 1; i<n; ++i) {
        dp[i] = 10000000000.0;
        for (int j = 0; j<i; ++j) {
            double val = dp[j] + sqrt(abs(x[i] - x[j] - l)) - M * b[i];
            if (dp[i] > val) {
                dp[i] = val; frm[i] = j;
            }
        }
    }
    return dp[n-1] <= 0;
}

signed main(){
    IOS();
    cin>>n>>l;
    ++n;
    for (int i = 1; i<n; ++i) {
        cin>>x[i]>>b[i];
    }
    double l = 0, r = 1000.0;
    while (r-l > 1e-8)  {
        double mid = (r+l)/2.0;
        if (ok (mid)) {
            r = mid;
        }else{
            l = mid;
        }
        bug(l,r);
    }
    bug(l);

    vector<int> v;
    for (int at = n-1; at != 0; at = frm[at]) {
        bug(at);
        v.pb(at);
    }
    for (int i = SZ(v)-1; i>=0; --i) cout<<v[i]<<' ';
}