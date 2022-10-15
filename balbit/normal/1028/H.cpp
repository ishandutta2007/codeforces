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

const int maxn = 2e5+5;
const int maxa = 51e5+5;

vector<int> pf[maxa];
bool ina[maxa], np[maxa];
int a[maxn], ans[1050000];
vector<pii> que[maxn];

int zck[2 * maxn];

void build() {  // build the tree
  for (int i = maxn - 1; i > 0; --i) zck[i] = min(zck[i<<1] , zck[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    if (zck[p+maxn] <= value) return;
    for (zck[p += maxn] = value; p > 1; p >>= 1) zck[p>>1] = min(zck[p] , zck[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 1000000;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, zck[l++]);
        if (r&1) res = min(res, zck[--r]);
    }
    return res;
}

int mp[maxa][8];
int mskprod[1<<7], popcnt[1<<7];

signed main(){
    IOS();
    memset(zck, 0x3f, sizeof zck);

    int n,q; cin>>n>>q;
    REP(i,1<<7) popcnt[i] = __builtin_popcount(i);
    REP(i,n) {
        cin>>a[i]; ina[a[i]] = 1;
    }
    for (int i = 2; i<maxa; ++i) {
        if (!np[i]) {
            for (int j = i; j<maxa; j+=i) {
                if (ina[j]) pf[j].pb(i);
                np[j] = 1;
            }
        }
    }
    REP(i,q) {
        int l,r; cin>>l>>r; --l; --r;
        que[r].pb({l,i});
    }
    memset(mp, -1, sizeof mp);
    mskprod[0] = 1;
    REP(i,n) {
        vector<int> myp;
        int tmp = a[i];
        for (int x : pf[a[i]]) {
            bool cnt = 0;
            while (tmp % x == 0) {
                tmp /= x; cnt ^=1;
            }
            if (cnt) myp.pb(x);
        }
        int m = SZ(myp);
        for (int M = 0; M<(1<<m); ++M) {
            if (M) mskprod[M] = mskprod[M ^ (M&-M)] * myp[__lg(M&-M)];
            REP(j,8) if (mp[mskprod[M]][j] != -1) {
                modify(mp[mskprod[M]][j], j + m - popcnt[M]);
            }
        }
        for (auto & qq : que[i] ) {
            ans[qq.s] = query(qq.f, i+1);
        }
        for (int M = 0; M<(1<<m); ++M) {
            mp[mskprod[M]][m-popcnt[M]] = i;
        }
    }

    REP(i,q) cout<<ans[i]<<endl;

}