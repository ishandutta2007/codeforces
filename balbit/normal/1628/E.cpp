#include <bits/stdc++.h>
//#define int ll
using namespace std;
#define ll long long
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

#ifdef BALBIT
const int maxn = 3e3+5;
#else
const int maxn = 3e5+5;
#endif
// 1. build dsu tree
// 2. build seg tree storing dsu tree euler tour min/max
// 3. log2(n) seg trees for each dsu tree depth
// basically make max seg tree that supports range unlock and lock
const int HO = 1050000;
struct seg{
    signed a[maxn];
    signed mx[HO], s[HO];
    char tag[HO];

//    signed mx[maxn*4], s[maxn*4];
//    char tag[maxn*4];
    void push(int o, int l, int r) {
        if (tag[o] == -1) return;
        if (tag[o] == 1) {
            s[o] = mx[o];
        }else s[o] = -iinf;

        if( l != r) {
            tag[o*2] = tag[o*2+1] = tag[o];
        }
        tag[o] = -1;
    }
    void build(int o=1, int l=0, int r=maxn-1) {
        if (l == r) {
            mx[o] = a[l]; return;
        }
        int mid = (l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
        mx[o] = max(mx[o*2], mx[o*2+1]);
    }

    void MO(int L, int R, int v, int o=1, int l=0, int r=maxn-1) {
        push(o,l,r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            tag[o] = v; push(o,l,r); return;
        }
        int mid = (l+r)/2;
        MO(L,R,v,o*2,l,mid);
        MO(L,R,v,o*2+1,mid+1,r);
        s[o] = max(s[o*2], s[o*2+1]);
    }
    seg(){
        memset(tag, -1, sizeof tag);
        memset(s, -iinf, sizeof s);
        memset(a, -iinf, sizeof a);
        memset(mx, -iinf, sizeof mx);
    }
};


const int POPO = 18;

struct SEG{
    array<int,POPO> a[maxn];
    array<int,POPO> mx[HO], s[HO];
    char tag[HO];

//    signed mx[maxn*4], s[maxn*4];
//    char tag[maxn*4];
    void push(int o, int l, int r) {
        if (tag[o] == -1) return;
        if (tag[o] == 1) {
            s[o] = mx[o];
        }else fill(ALL(s[o]), -iinf);

        if( l != r) {
            tag[o*2] = tag[o*2+1] = tag[o];
        }
        tag[o] = -1;
    }
    void build(int o=1, int l=0, int r=maxn-1) {
        if (l == r) {
            mx[o] = a[l]; return;
        }
        int mid = (l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
        REP(i,POPO) mx[o][i] = max(mx[o*2][i], mx[o*2+1][i]);
    }

    void MO(int L, int R, int v, int o=1, int l=0, int r=maxn-1) {
        push(o,l,r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            tag[o] = v; push(o,l,r); return;
        }
        int mid = (l+r)/2;
        MO(L,R,v,o*2,l,mid);
        MO(L,R,v,o*2+1,mid+1,r);
        REP(i,POPO) s[o][i] = max(s[o*2][i], s[o*2+1][i]);
    }
    SEG(){
        memset(tag, -1, sizeof tag);
        REP(T, maxn) {
            fill(ALL(a[T]), -iinf);
        }
        REP(T, HO) {
            fill(ALL(mx[T]), -iinf);
            fill(ALL(s[T]), -iinf);
        }
    }
};

// dsu tree time!!!!!
int par[maxn], parw[maxn];
vector<pii> g[maxn]; // to, weight (only down, no parents)
int sz[maxn];
int find(int x) {
    // don't do path compression!!!
    if (x == par[x]) return x;
    return find(par[x]);
}
int IT;
int L[maxn], R[maxn]; // timestamps
int dep[maxn];
vector<int> ord;
void dfs(int v) {
    L[v] = R[v] = IT++;
    ord.pb(v);
    for (pii e : g[v]) {
        int u = e.f;
        bug(v,u,e.s);
        dep[u] = dep[v] + 1;
        dfs(u);
        R[v] = R[u];
    }
}

//seg lay[POPO];

SEG lay;

signed main(){
    IOS();

    int n,q; cin>>n>>q;
    REP(i,n) {
        par[i] = i; sz[i] = 1;
    }
    vector<pair<int, pii> > vc;
    REP(i,n-1) {
        int a,b,w;cin>>a>>b>>w;
        vc.pb({w,{a-1,b-1}});
    }
    sort(ALL(vc));

    for (auto e : vc) {
        int a = e.s.f, b = e.s.s;
        int w = e.f;
         a = find(a); b = find(b);
        if (sz[a] > sz[b]) swap(a,b);
        // a is smaller!
        par[a] = b; parw[a] = w;
        sz[b] += sz[a];
        g[b].pb({a,w});
    }

    int rt = -1; REP(i,n) if (par[i] == i) rt = i;
    bug(rt);
    dfs(rt);

    seg eumin, eumax;

    int deep = 0;

    REP(i,n) {
        bug(i, L[i]);
        eumin.a[i] = -L[i];
        eumax.a[i] =  L[i];
        MX(deep, dep[i]);
    }
    eumin.build(); eumax.build();

    REP(i,n) {
        int ho = -1;
        for (int at = i; ; at = par[at]) {
            if (ho != -1) lay.a[i][dep[at]] = ho;
            if (at == rt) break;
            MX(ho, parw[at]);
        }
    }

    lay.build();

    REP(qqq,q) {
        int tp; cin>>tp;
        if (tp == 3) {
            int v; cin>>v; --v;
            int lp = -eumin.s[1], rp = eumax.s[1];
            bug(lp, rp);
            MN(lp, L[v]); MX(rp, L[v]);

            lp = ord[lp]; rp = ord[rp];

            while (lp != rp) {
                if (dep[lp] < dep[rp]) swap(lp, rp);
                lp = par[lp];
            }

            bug("lca is ", lp); // this is
            if (dep[lp] >= deep) {
                cout<<-1<<endl; continue;
            }
            int oth = max(-1, dep[lp] < POPO? lay.s[1][dep[lp]] : -1);
            MX(oth, lay.a[v][dep[lp]]);

            cout<<oth<<endl;
        }else {
            bool on = tp == 1;
            int l, r; cin>>l>>r; --l; --r;
            eumin.MO(l,r,on);
            eumax.MO(l,r,on);
            lay.MO(l,r,on);
//            REP(i,deep+1) lay[i].stuff.pb({{l,r},on});
        }
    }
}