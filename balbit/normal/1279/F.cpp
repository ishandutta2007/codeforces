#include <bits/stdc++.h>
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

int n,k,L;

ll dp[maxn];
int num[maxn]; // number of sections i took

pii alien(vector<int> &v, int pen) {
    for (int i = 1; i<=SZ(v); ++i) {
        dp[i] = dp[i-1] + v[i-1]; num[i] = num[i-1];
        if (dp[max(0, i-L)] + pen < dp[i]) {
            dp[i] = dp[max(0, i-L)] + pen;
            num[i] = num[max(0,i-L)]+1;
        }
    }
    return {dp[SZ(v)], num[SZ(v)]};
}

int solve(vector<int> v) {
    // v is of 0s and 1s, trying to make them all 0

    int l = 0, r = n;
    while (l!=r) {
        int mid = (l+r)/2;
        pii pp = alien(v, mid);
        if (pp.s > k) {
            // i take too many sections!! more penalty!!!
            l = mid+1;
        }else{
            r = mid;
        }
    }
    pii pa = alien(v, l);
    ll org = pa.f - pa.s * l;
    return org + (k - pa.s) * -l; // same slope, so...
}

signed main(){
    IOS();

    cin>>n>>k>>L;
    string s; cin>>s;
    vector<int> v;
    REP(i,n) {
        v.pb((s[i] >= 'A' && s[i] <= 'Z'));
    }
    int s1 = solve(v);
    for (int &x : v) x = 1-x;
    int s2 = solve(v);
    bug(s1,s2);
    cout<<min(s1, s2)<<endl;


}