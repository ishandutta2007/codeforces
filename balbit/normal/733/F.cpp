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

const int maxn = 2e5+5;

int n,m;

struct Edge{
    int u,w;
};
struct E2{
    int v, u, w, c, id;
};
vector<Edge>g[maxn];
int W[maxn], C[maxn];
int par[maxn];
bool ok[maxn];
int dep[maxn];
ll fa[21][maxn], mx[21][maxn];

int find(int x) {
    return x==par[x]?x:par[x] = find(par[x]);
}

void dfs(int v, int p) {
    bug(v, p);
    for (Edge & e : g[v ]) {
        if (e.u != p) {
            mx[0][e.u] = e.w;
            fa[0][e.u] = v;
            dep[e.u] = dep[v] + 1;
            dfs(e.u, v);
        }
    }
}

ll big(int a, int b) {
    if (dep[a] < dep[b] ) swap(a,b);
    int dif = dep[a] - dep[b];
    ll re = 0;
    for (int j = 0; dif != 0; ++j, dif/=2) {
        if (dif & 1) {
            re = max(re, mx[j][a]);
            a = fa[j][a];
        }
    }
    assert(dep[a] == dep[b]);
    for (int j = 20; j>=0; --j) {
        if (fa[j][a] != fa[j][b]) {
            re = max(re, mx[j][a]);
            re = max(re, mx[j][b]);
            a = fa[j][a];
            b = fa[j][b];
        }
    }
    return a==b?re : max(re, max(mx[0][a], mx[0][b]));
}

signed main(){
    IOS();
    cin>>n>>m;
    for (int i = 0; i<n; ++i) par[i] = i;
    for (int i = 0; i<m; ++i) cin>>W[i];
    for (int i = 0; i<m; ++i) cin>>C[i];
    vector<E2> egs;
    for (int i = 0; i<m; ++i) {
        int a,b; cin>>a>>b; --a; --b;
        egs.pb({a,b,W[i], C[i],i});
    }
    sort(ALL(egs), [&](E2 a, E2 b){return a.w < b.w; });
    ll W1 = 0;
    ll mxc = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i<m; ++i) {
        if (find(egs[i].v) != find(egs[i].u)) {
            par[find(egs[i].v)] = find(egs[i].u);
            W1 += egs[i].w;
            mxc = min(mxc, (ll)egs[i].c);
            g[egs[i].v].pb({egs[i].u,egs[i].w});
            g[egs[i].u].pb({egs[i].v,egs[i].w});
            ok[i] = 1;
        }
    }
    dfs(0,0);
    for (int j = 1; j<21; ++j) {
        for (int i = 0; i<n; ++i) {
            mx[j][i] = max(mx[j-1][i], mx[j-1][fa[j-1][i]]);
            fa[j][i] = fa[j-1][fa[j-1][i]];
        }
    }
    bug(mxc);
    ll S; cin>>S;
    ll re = W1 - S / mxc;
    bug(re);

    int add = -1;

    for (int i = 0; i<m; ++i) {
        if(!ok[i]) {
            ll ans = W1 - big(egs[i].v, egs[i].u) + egs[i].w - S / egs[i].c;
            bug(i,ans);
            if (ans < re) {
                add = i;
                re = min(re, ans);
            }
        }
    }

    cout<<re<<endl;

        for (int i = 0; i<n; ++i) par[i] = i;
    if (add != -1) {
        cout<<egs[add].id+1<<' '<<egs[add].w - S / egs[add].c<<endl;
        par[find(egs[add].v)] = find(egs[add].u);
    }

    for (int i = 0; i<m; ++i) {
        if (find(egs[i].v) != find(egs[i].u)) {
            par[find(egs[i].v)] = find(egs[i].u);
            if (add == -1 && egs[i].c == mxc) {
                egs[i].w -= S / mxc;
                add = -2;
            }
            cout<<egs[i].id+1<<' '<<egs[i].w<<endl;
        }
    }


}