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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

vector<int> dia;
vector<pii> g[maxn];
bool vis[maxn], mon[maxn], ok[maxn], ondia[maxn];

pii dfs(int v, int p) {
    bug(v);
    pii re = {0,v};
    for (pii u : g[v]) {
        if (u.f != p && ok[u.f] && !ondia[u.f]) {
            pii tmp = dfs(u.f,v); tmp.f += u.s;
            re = max(re, tmp);
        }
    }
    return re;
}

bool dfs1(int v, int p) {
    if (mon[v]) ok[v] = 1;
    for (pii u : g[v]) {
        if (u.f != p) {
            ok[v] |= dfs1(u.f,v);
        }
    }
    return ok[v];
}

int target = -1;
vector<int> diadist = {0};
bool finddia(int v, int p) {
    if (v == target) {
        dia.pb(v);
        ondia[v] = 1;
        return 1;
    }
    for (pii u : g[v]) {
        if (u.f != p && ok[u.f]) {
            if (finddia(u.f,v)) {
                dia.pb(v);
                ondia[v] = 1;
                diadist.pb(u.s);
                return 1;
            }
        }
    }
    return 0;
}

int sz[maxn];
int most=0, ways=1;

inline void ANS(int num) {
    if (num > most) most = num, ways = 0;
    if (num == most) ways++;
}

void dfssz(int v, int p=-1) {
    sz[v] = mon[v];
    for (pii u : g[v]) {
        if (u.f != p && ok[u.f] && !ondia[u.f]) {
            dfssz(u.f,v);
            sz[v] += sz[u.f];
        }
    }
    if (!ondia[v] && !mon[v]) {
        ANS(sz[v]);
    }
}

signed main(){
    IOS();
    int n,m; cin>>n>>m;
    vector<int> mons;
    for (int i = 0; i<m; ++i) {
        int x; cin>>x; -- x;
        mon[x] = 1; mons.pb(x);
    }
    for (int i = 0; i<n-1; ++i) {
        int a,b,c; cin>>a>>b>>c; --a; --b;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    dfs1(mons[0],-1);

    pii firstgo = dfs(mons[0],-1);
    pii secondgo = dfs(firstgo.s,-1);
    bug(secondgo.s, secondgo.f);
    target = firstgo.s;
    bug(target);
    finddia(secondgo.s, -1);
    for (int x : dia) bug(x);
    int D = secondgo.f;

    int ld = 0;
    int N = SZ(dia);
    vector<int> deep(N), lok(N,-1), rok(N, N+1), L(N), R(N);;

    for (int i = 0; i<SZ(dia); ++i) {
        int v = dia[i];
        ld += diadist[i];
        bug(v, ld);
        pii myv = dfs(v, -1);
        bug(v, myv.f, myv.s);
        deep[i] = myv.f;
        L[i] = ld; R[i] = D-ld;
        if (deep[i] == L[i]) {
            lok[i] = i;
        }
        if (deep[i] == R[i]) {
            rok[i] = i;
        }
        assert(deep[i] <= L[i] && deep[i] <= R[i]);
        dfssz(v);
    }
    assert(ld == D);
    for (int i = 1; i<N; ++i) {
        lok[i] = max(lok[i], lok[i-1]);
    }
    for (int i = N-2; i>=0; --i) {
        rok[i] = min(rok[i], rok[i+1]);
    }
    vector<int> ps(N+1);
    auto upd = [&](int l, int r, int w) {
        ps[l] +=w; ps[r+1]-=w;
    };
    for (int i = 0; i<N; ++i) {
        if (L[i] == R[i]) {
            upd(i,i,sz[dia[i]]);
        }
        if (L[i] > R[i]) {
            upd(min(lok[i] ,i),i, sz[dia[i]]);
        }
        if (L[i] < R[i]) {
            upd(i, max(rok[i],i),sz[dia[i]]);
        }
    }
    for (int i = 0; i<N; ++i) {
        if (i) ps[i] += ps[i-1];
        bug(i, dia[i], ps[i]);
        if (!mon[dia[i]]) {
            ANS(ps[i]);
        }
    }
    cout<<most<<' '<<ways<<endl;
}