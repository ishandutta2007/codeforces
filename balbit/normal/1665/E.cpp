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

const int maxn = 1e5+5;

struct Trie{
    array<int, 2> c;
    vector<int> v; // indexes of all leaf children
    Trie(){
        c[0]=c[1]=0;
    }
    inline int btw(int l, int r) {
        // number of elements in (sorted) v between [l,r]
        return upper_bound(ALL(v), r) - upper_bound(ALL(v), l-1);
    }
}T[maxn * 65];

int IT = 1;

int root;

void add(int x, int id) {
    int at = root;
    for (int i = 29; i >=0; --i) {
        bool has = (x&(1<<i)) != 0;
        if (!T[at].c[has]) T[at].c[has] = IT++;
        at = T[at].c[has];
        T[at].v.pb(id);
    }
}

int a[maxn];

int get(int l, int r) {
    int at = root;
    int re = 0;
    vector<int> spec;
    for (int i = 29; i>=0; --i) {
        int n0 = (at != 0 && T[at].c[0]!=0) ?T[T[at].c[0]].btw(l,r) : 0;
        for (int x : spec) {
            if ((x&(1<<i)) == 0) {
                ++n0;
            }
        }
        if (n0 >= 2) {
            for (int j = SZ(spec)-1; j>=0; --j) {
                if ((spec[j] & (1<<i))) {
                    spec.erase(spec.begin() + j);
                }
            }
            if (at) at = T[at].c[0];
            continue;
        }
        re += (1<<i);
        if (n0 == 1) {
            if (at && T[at].c[0]) {
                auto where = lower_bound(ALL(T[T[at].c[0]].v), l);
                if (where != T[T[at].c[0]].v.end() && *where <= r) {
                    bug(*where, a[*where], (1<<i));
                    assert((a[*where] & (1<<i) )== 0);
                    spec.pb(a[*where]);
                }
            }
        }
        if (at) at = T[at].c[1];
    }
    bug(SZ(spec));
    return re;
}

signed main(){
    IOS();
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        root=IT++;
        REP(i,n) {
            cin>>a[i];
            add(a[i], i);
        }
        int q; cin>>q;
        while (q--) {
            int l,r; cin>>l>>r; --l; --r;
            cout<<get(l,r)<<endl;
        }
    }

}