#include <bits/stdc++.h>
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

//int n;  // array size
int seg[2 * maxn];

void build() {  // build the tree
  for (int i = maxn - 1; i > 0; --i) seg[i] = max(seg[i<<1] , seg[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p] , seg[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 100000000000000000ll;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, seg[l++]);
        if (r&1) res = min(res, seg[--r]);
    }
    return res;
}

int s2[2 * maxn];

void BB() {  // build the tree
  for (int i = maxn - 1; i > 0; --i) s2[i] = min(s2[i<<1] , s2[i<<1|1]);
}

void MM(int p, int value) {  // set value at position p
    for (s2[p += maxn] = value; p > 1; p >>= 1) s2[p>>1] = min(s2[p] , s2[p^1]);
}

int QQ(int l, int r) {  // sum on interval [l, r)
    int res = 100000000000000000ll;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, s2[l++]);
        if (r&1) res = min(res, s2[--r]);
    }
    return res;
}

ll dp[maxn];

signed main(){
    IOS();
    int n; cin>>n;
    vector<pii> v(n);
    ll re = 0;
    REP(i,n) {
        cin>>v[i].f>>v[i].s;
        re += v[i].s;
    }
    sort(ALL(v));
    for (int i = n-1; i>=0; --i) {
        if (i != n-1) {
            int j = lower_bound(ALL(v), pii{v[i].f + v[i].s, 1000000000000000ll})-v.begin();
            bug(i,j);
            dp[i] = min(query(i+1,j), QQ(j, n)-v[i].f-v[i].s);
        }
        modify(i,dp[i]);
        MM(i,dp[i]+v[i].f);
    }
    bug(dp[0]);
    cout<<dp[0]+re<<endl;

}