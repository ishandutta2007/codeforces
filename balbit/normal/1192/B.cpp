#include <bits/stdc++.h>
#undef BALBIT
using namespace std;
#define ll long long
#define int ll
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
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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

const int maxn = 1e5+5;
const int maxlg = 17;
int n,q;
set<pair<ll, int>, greater<pair<ll, int> > > bst[maxn]; // for each centroid
int cenpar[maxn][17], iord[maxn][17], oord[maxn][17];
int lay[maxn], cpar[maxn], c2[maxn][17]; // c2 is the 2nd last guy on the path to this centroid
bool dead[maxn];
int sz[maxn];

vector<int> g[maxn];
#define pil pair<int, ll>
vector<pil> wg[maxn];

void szdfs(int v, int p) {
    sz[v] = 1;
    for (int u: g[v]) {
        if (u!=p && !dead[u]) {
            szdfs(u,v);
            sz[v] += sz[u];
        }
    }
}
int allsz = 0;

int findcen(int v, int p) {
    for (int u : g[v]) {
        if (u!=p && !dead[u] && sz[u] > allsz/2) {
            return findcen(u,v);
        }
    }
    return v;
}

int LIT = 0; // leaf iterator

ll s[maxn*maxlg*4], tag[maxn*4*maxlg];
ll initval[maxn*maxlg*2];

void build(int o=1, int l=0, int r = LIT-1) {
    if (l==r) {
        s[o] = initval[l];
        return;
    }
    int m = l+r>>1;
    build(o*2,l,m);
    build(o*2+1,m+1,r);
    s[o] = max(s[o*2], s[o*2+1]);
}

void push(int o, int l, int r) {
    if (tag[o] == 0) return;
    s[o] += tag[o];
    if (l!=r) {
        tag[o*2] += tag[o];
        tag[o*2+1] += tag[o];
    }
    tag[o] = 0;
}

void MO(int L, int R, ll val, int o=1, int l=0, int r = LIT-1) {
    push(o,l,r);
    if (l>R || r<L) return;
    if (l>=L && r<= R) {
        tag[o] += val;
        push(o,l,r);
        return;
    }
    int m = l+r>>1;
    MO(L,R,val,o*2,l,m);
    MO(L,R,val,o*2+1,m+1,r);
    s[o] = max(s[o*2], s[o*2+1]);
}

ll QU(int L, int R, int o=1, int l=0, int r = LIT-1) {
    if (l>R || r<L) return -10000000000000ll;
    push(o,l,r);
    if (l>=L && r<=R) {
        return s[o];
    }
    int m = (l+r)>>1;
    return max(QU(L,R,o*2,l,m), QU(L,R,o*2+1,m+1,r));
}

void cendfs(int v, int p, int cen, int lol, int parfriend = -1, ll sum=0) {
    cenpar[v][lol] = cen;
    c2[v][lol] = parfriend;
    if (SZ(g[v]) == 1 && v!=cen) {
        iord[v][lol] = oord[v][lol] = LIT;
        initval[LIT] = sum;
        ++LIT;
    }else{
        iord[v][lol] = 100000000;
        oord[v][lol] = -1;
        int nat = 0;
        for (pil u: wg[v]) {
            if (u.f!=p && !dead[u.f]) {
                int pf = parfriend;
                if (pf == -1) pf = nat;
                cendfs(u.f,v,cen,lol,pf, sum+u.s);
                iord[v][lol] = min(iord[v][lol], iord[u.f][lol]);
                oord[v][lol] = max(oord[v][lol],oord[u.f][lol]);
            }
            nat++;
        }
    }
}
vector<ll> valof[maxn];

void decomp(int v, int pcen=-1, int layer=0) {
    szdfs(v,-1);
    allsz = sz[v];
    int cen = findcen(v, -1);
    bug(allsz, cen, layer);
    lay[cen] = layer;
    cpar[cen] = pcen;
    dead[cen] = 1;
    cendfs(cen, -1, cen, layer);
    for (int u : g[cen]) {
        if (!dead[u]) {
            valof[cen].pb(1);
        }else{
            valof[cen].pb(0);
        }
    }
    for (int u : g[cen]) {
        if (!dead[u]) {
            decomp(u,cen,layer+1);
        }
    }
}


signed main(){
    IOS();
    cin>>n>>q;
    ll W; cin>>W;
    vector<pii> Ed;
    vector<ll> wei;
    for (int i = 0; i<n-1; i++) {
        int a,b; cin>>a>>b; --a; --b;
        Ed.pb({a,b});
        g[a].pb(b);
        g[b].pb(a);
        ll w; cin>>w;
        wg[a].pb({b,w});
        wg[b].pb({a,w});
        wei.pb(w);
    }
    decomp(0);
    build();
    ll last = 0;
    set<pair<ll, int>, greater<pair<ll, int> > > all;

    vector<int> ansof(n);

    for (int v = 0; v<n; v++) {
        int i = 0; int lol = lay[v];
        for (pair<ll, int> u : wg[v]) {
            if (valof[v][i]) {
                valof[v][i] = QU(iord[u.f][lol], oord[u.f][lol]);
                bug(v, u.f, valof[v][i]);
                bst[v].insert({valof[v][i],i});
            }
            ++i;
        }
        if (SZ(bst[v]) != 0) {
            auto iter = bst[v].begin();
            ansof[v] = (*iter).f;
            if (SZ(bst[v]) > 1) {
                ansof[v] += (*(++iter)).f;
            }
            all.insert({ansof[v],v});
        }
    }
/*
6 10 100000000
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1

*/
    while (q--) {
        ll eid;
        ll nw;
        cin>>eid>>nw;
#ifndef BALBIT
        eid = (eid + last) % (n-1);
        nw = (nw + last) % (W);
#endif
        ll ow = wei[eid];
        wei[eid] = nw;
        nw -= ow;
        int a = Ed[eid].f, b = Ed[eid].s;
        if (lay[a]  > lay[b]) swap(a,b);

        for (int cen = a; cen != -1; cen = cpar[cen]) {

            if (SZ(bst[cen]) == 0) continue;

            int lol = lay[cen];
            int l = max(iord[a][lol], iord[b][lol]), r = min(oord[b][lol], oord[a][lol]);
            bug("MO",l,r,nw);
            MO(l,r,nw);
            int upd = max(c2[a][lol], c2[b][lol]);
            if (upd == -1) assert(0);

            bug(upd, cen, a,b, nw);

            bst[cen].erase({valof[cen][upd],upd});
            int sc = g[cen][upd];

            valof[cen][upd] = QU(iord[sc][lol], oord[sc][lol]);

            bst[cen].insert({valof[cen][upd],upd});

            auto iter = bst[cen].begin();

            all.erase({ansof[cen], cen});
            ansof[cen] = (*iter).f;
            if (SZ(bst[cen]) > 1) {
                ansof[cen] += (*(++iter)).f;
            }
            all.insert({ansof[cen], cen});

        }
        last = (*(all.begin())).f;
        cout<<last<<endl;
    }

}