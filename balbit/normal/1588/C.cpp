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

const int maxn = 3e5+5;

//map<ll, int> mp;
//vector<int> here[maxn];

ll seg[2 * maxn];

void build() {  // build the tree
  for (ll i = maxn - 1; i > 0; --i) seg[i] = min(seg[i<<1] , seg[i<<1|1]);
}

void modify(ll p, ll value) {  // set value at position p
    for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p] , seg[p^1]);
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = inf;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, seg[l++]);
        if (r&1) res = min(res, seg[--r]);
    }
    return res;
}

ll a[maxn];

map<ll, int> get(vector<int> v) {
//    vector<int> re;
    vector<ll> ar(SZ(v)+1);
    ll mo0 = 0, mo1 = 0;
    map<ll, int> ha;
    bug(SZ(v));
    REP(i,SZ(v)) {
        ar[i+1] = ar[i] + (i % 2 == 0? 1 : -1) * v[i];
        if (i % 2 == 0) {
            mo0 = min(mo0 + v[i], v[i]);
            if (i)
                mo1 = mo1-v[i];
        }else{
            mo0 = mo0-v[i];
            mo1 = min(mo1 + v[i], v[i]);
        }
        if (min(mo0, mo1) >= 0) {
//            re.pb(ar[i+1]);
            ++ha[ar[i+1]];
            bug(ar[i+1]);
        }
    }
//    sort(ALL(re));
//    for (int t : re) ha[t]++;
    return ha;
}

ll solve(int l, int r) {
    if (l == r) return a[l] == 0;
    int mid = (l+r)/2;
    vector<int> v1, v2;
    for (int i = mid; i>=l; --i) {
        v1.pb(a[i]);
    }
    for (int i = mid+1; i<=r; ++i) {
        v2.pb(a[i]);
    }
    map<ll,int> g1 = get(v1), g2 = get(v2);
    ll re = 0;
    for (auto pp : g1) {
        if (g2.count(pp.f)) {
            re += pp.s * g2[pp.f];
        }
    }
    return solve(l,mid) + solve(mid+1,r) + re;
}

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        REP(i,n) cin>>a[i];
        cout<<solve(0,n-1)<<endl;
    }

}