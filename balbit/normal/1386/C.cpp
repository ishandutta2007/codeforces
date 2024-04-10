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

const int maxn = 2e5+15;

int par[maxn];
bool pd[maxn]; // parent, distance to parent
int sz[maxn];

pii find(int v) {
    if (par[v] == v) {
        return {v, 0};
    }
    pii hi = find(par[v]);
    hi.s ^= pd[v];
    return hi;
}

vector<int> did; // {node}
int nbad = 0;

int merge(int a, int b) {
    // returns 1 if merge, 0 if nothing, -1 if illegal
    pii fa = find(a), fb = find(b);
    if (fa.f == fb.f) {
        if (fa.s == fb.s) {
            did.pb(-1);
            nbad++;
            return -1;
        }else {
            return 0;
        }
    }
    bool edgeb = fa.s ^ fb.s ^ 1;
    if (sz[fa.f] > sz[fb.f]) {
        swap(fa, fb);
    }
    did.pb(fa.f);
    sz[fb.f] += sz[fa.f];
    par[fa.f] = fb.f;
    pd[fa.f] = edgeb;
    return 1;
}

void undo(){
    int a = did.back(); did.pop_back();
    if (a == -1) {
        --nbad; return;
    }
    sz[par[a]] -= sz[a]; par[a] = a;
}

int far[maxn]; // for each i, maximum L such that [0,L) U [i, N] is legal
int U[maxn], V[maxn];

void gt(int ql, int qr, int al, int ar) {
    // currently, [0, ql) and (ar, n-1] are filled in

    // the answer is somewhere in [ql, qr]

    bug(ql, qr, al, ar);
    if (al > ar) return;
    if (ql == qr) {
        for (int i = al; i<=ar; ++i) {
            far[i] = ql;
        }
        return;
    }
    int mid = (ql + qr) / 2;
    // solve for mid?
    int atfirst = SZ(did);

    for (int i = ql; i<=mid; ++i) {
        merge(U[i], V[i]);
    }

    int uptomid = SZ(did);

    // try ar and stuff
    int mintor = ar+1;
    for (int i = ar; i>=al; --i) {
        merge(U[i], V[i]);
        if (nbad == 0) {
            mintor = i;
        }else{
            break;
        }
    }
    while (SZ(did) > uptomid) undo();

    gt(mid+1, qr, mintor, ar);

    while (SZ(did) > atfirst) undo();

    for (int i = ar; i>=mintor; --i) {
        merge(U[i], V[i]);
    }

    gt(ql, mid, al, mintor-1);

    while (SZ(did) > atfirst) undo();
}

signed main(){
    IOS();

    int n,m,q; cin>>n>>m>>q;

    REP(i,n+4) {
        sz[i] = 1; par[i] = i;
    }

    REP(i,m) {
        cin>>U[i]>>V[i];
//        merge(U[i], V[i]);
//        bug(i, nbad);
        --U[i]; --V[i];
    }
    U[m] = n+1, V[m] = n+2;

    gt(0, m, 0, m);

    bug(SZ(did));
    assert(SZ(did) == 0);

    for (int i = m-1; i>=0; --i) {
        merge(U[i], V[i]);
        if (nbad) {
            far[i] = -1;
        }
    }

    REP(i,m+1) {
        bug(i, far[i]);
    }

    while (q--) {
        int l, r; cin>>l>>r;
        --l; --r;
        assert(l <= r);
        if (l <= far[r+1]) {
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
}

/*
6 6 5
1 2
1 1
1 1
1 1
1 1
1 1

*/