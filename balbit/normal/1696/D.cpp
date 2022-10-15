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

const int maxn = 5e5+5;

struct tree{
    vector<int> seg;
    int mxn;

    void modify(int p, int value) {  // set value at position p
        for (seg[p += mxn] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p] , seg[p^1]);
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = iinf;
        for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = min(res, seg[l++]);
            if (r&1) res = min(res, seg[--r]);
        }
        return res;
    }

    tree(int sz){
        mxn = sz; seg.resize(mxn * 2, iinf);
    }
};




signed main(){
    IOS();

    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> where(n);
        vector<int> a(n);

        tree MNT(n), MXT(n);

        REP(i,n) {
            cin>>a[i]; --a[i]; where[a[i]] = i;
            MNT.modify(i, a[i]);
            MXT.modify(i, -a[i]);
        }

        vector<int> nxt(n);

        tree PT(n+1);

        for (int i = n-1; i>=0; --i) {
            if (i < n-1) {
                if (a[i] > a[i+1]) {
                    nxt[i] = PT.query(a[i]+1, n);
                }else{
                    nxt[i] = PT.query(0, a[i]);
                }
                MN(nxt[i], n);
            }
            PT.modify(a[i], i);
        }

        int at = 0;
        int re = 0;



        while (at != n-1) {
            int t; ++ re;
            if (a[at] > a[at+1]) {
                t = MNT.query(at+1, nxt[at]);
            }else{
                t = -MXT.query(at+1, nxt[at]);
            }
            at = where[t];
            bug(at);
        }

        cout<<re<<endl;


    }

}