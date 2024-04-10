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

const int maxn = 5e5+5;

ll A[maxn], B[maxn], C[maxn], tmpC[maxn];

int seg[2 * maxn];

void modify(int p, int value) {  // set value at position p
    for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p] , seg[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    ll res = inf;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, seg[l++]);
        if (r&1) res = min(res, seg[--r]);
    }
    return res;
}

struct line{
    int l,r,k;
};

ll mn[maxn*4], tg[maxn*4], mna[maxn*4], ra[maxn*4];

void push(int o, int l, int r){
    if (tg[o] != inf) {
        MN(mn[o], tg[o]);
        MN(ra[o], mna[o] + mn[o]);
        if (l!=r) {
            MN(tg[o*2], tg[o]);
            MN(tg[o*2+1], tg[o]);
        }
        tg[o] = inf;
    }
}

int n;

void build(int o=1, int l=0, int r=maxn-1) {
    tg[o] = mn[o] = ra[o] = inf;
    if (l == r) {
        if (l == 0 || l > n) {
            mna[o] = inf;
        }else{
            mna[o] = A[l];
        bug(o, l, r, mna[o]);
        }
        return;
    }
    int mid = (l+r)/2;
    build(o*2, l, mid);
    build(o*2+1, mid+1,r);
    mna[o] = min(mna[o*2], mna[o*2+1]);
}

void MO(int L, int R, ll v, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l>R || r<L) return;
    if (l >= L && r <= R) {
        MN(tg[o], v);
        push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid);
    MO(L,R,v,o*2+1,mid+1,r);
//    mn[o] = min(mn[o*2], mn[o*2+1]);
    ra[o] = min(ra[o*2], ra[o*2+1]);
//    MN(ra[o], )
}

ll QU(int L, int R, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l>R || r<L) return inf;
    if (l>=L && r<=R) {
        return ra[o];
    }
    int mid = (l+r)/2;
    return min(QU(L,R,o*2,l,mid), QU(L,R,o*2+1,mid+1,r));
}

signed main(){
    IOS();

    cin>>n; int q; cin>>q;
    REP1(i,n) {
        cin>>A[i]; A[i] = -A[i];

        if (i) A[i] += A[i-1];
    }
    REP1(i,n) {
        cin>>B[i]; B[i] = -B[i];

        if (i) B[i] += B[i-1];
    }
    REP1(i,n) {
        cin>>tmpC[i]; tmpC[i] = -tmpC[i];

        if (i) tmpC[i] += tmpC[i-1];
    }

    ll totC = tmpC[n];

    REP1(i,n) {
        A[i] = A[i] - B[i-1];

        C[i] = totC - tmpC[i-1] + B[i];

        modify(i, A[i]);
    }

    REP1(i,n) {
        bug(i, A[i], C[i]);
    }

    vector<line> L;
    REP(i,q) {
        int l,r,k; cin>>l>>r>>k;
        L.pb({l,r,k});
    }
    sort(ALL(L), [&](line a, line b){return a.r !=b.r?a.r < b.r : a.l < b.l;});


    for (line e : L) {
        MN(A[e.r+1], query(e.l, e.r+1) + e.k);
        if (e.r != n) modify(e.r+1, A[e.r+1]);
    }

    REP1(i,n) {
        bug(i, A[i]);
    }

    build();

    int lastx = 0;

    ll re = inf;


    for (line e : L) {
        bug(e.l, e.r);
        while (lastx < e.r) {
            ++lastx;
            bug(lastx, C[lastx]);
            MO(1, lastx, C[lastx]);
        }
        ll ha = QU(e.l, e.r);
        bug(ha, e.k);
        MN(re, ha + e.k);
    }

    cout<<-re<<endl;
}