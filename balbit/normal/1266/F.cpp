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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 5e5+5;

int n;
vector<int> g[maxn];

vector<pii> nxt[maxn];
int mxdep[maxn];

void dfs1(int v, int p) {
    for (int u : g[v]) {
        if (u != p) {
            dfs1(u,v);
            nxt[v].pb({mxdep[u],u});
            mxdep[v] = max(mxdep[v], mxdep[u]);
        }
    }
    sort(ALL(nxt[v]),greater<pii>());
    ++mxdep[v];
}

vector<pii> case1; // where you have one lesser thingy

void dfs2(int v, int p) {
    if (p != -1) {
        if (nxt[p][0].s != v) {
            nxt[v].pb({nxt[p][0].f + 1, p});
        }else if (SZ(nxt[p]) > 1 ) {
            nxt[v].pb({nxt[p][1].f + 1, p});
        }else{
            nxt[v].pb({0 + 1, p});
        }
    }
    sort(ALL(nxt[v]), greater<pii>());
    for (int u : g[v]) {
        if (u != p) {
            dfs2(u,v);
        }
    }
}

int s[maxn];

void MO(int L, int R, int v, int o = 1, int l = 0, int r = maxn-1) {
    if ( l> R || r < L) return;
    if (l >= L && r <= R) {
        MX(s[o], v); return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid);
    MO(L,R,v,o*2+1,mid,r);
}

int gt(int p, int o=1, int l =0, int r  =maxn-1){
    int mid = (l+r)/2;
    if (l == r) return s[o];
    if (p <= mid) {
        return min(s[o],gt(p,o*2,l,mid));
    }else{
        return min(s[o], gt(p,o*2+1,mid+1,r));
    }
}

int ans[maxn];

struct Ev{
    int t, w; // time, who
};

signed main(){
    IOS();

    cin>>n;
    for(int i = 0; i<n-1; i++) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }

    dfs1(0,-1);
    dfs2(0,-1);

    // case 1:
    for (int i = 0; i<n; ++i) {
        bug(i);
        for (int j = 0; j<SZ(nxt[i]); ++j) {
            case1.pb({nxt[i][j].f * 2, j+1});
            if (i == 8) bug(nxt[i][j].f, nxt[i][j].s);
            if (j != SZ(nxt[i]) -1 && nxt[i][j+1].f < nxt[i][j].f)
                case1.pb({nxt[i][j+1].f * 2 + 1, j + 2});//, bug(nxt[i][j].f * 2 - 1, j+2);
        }
    }
    {
        int nb =0;
        sort(ALL(case1), greater<pii>());
        case1.pb({0,-1});
        int nat = n;
        for (pii & p : case1) {
            while (nat > p.f) {
                ans[nat--] = nb;
            }
            nb = max(nb, p.s);
        }
        for (int i = 1; i<=n; ++i) {
            bug(i, ans[i]);
        }
    }
    case1.clear();
    // case 2
    for (int v = 0; v<n; ++v) {
        vector<Ev> V; // negative who is v, params are (t,w)
        int IT = 0;
        map<int, int> tmpmp;
        for (int u : g[v]) {
            if (make_pair(SZ(g[u]), u) < make_pair(SZ(g[v]), v)) {
                tmpmp[u] = ++IT;
                for (pii pp : nxt[u]) {
                    if (pp.s != v) {
                        V.pb({pp.f, IT});
                    }
                }
            }
        }
        if (IT != 0) {
            for (pii p : nxt[v]) {
                if (tmpmp.count(p.s))
                    V.pb({p.f, -tmpmp[p.s]});
                else
                    V.pb({p.f, 0});
            }
            sort(ALL(V), [&](Ev a, Ev b) {return a.t != b.t? a.t > b.t : a.w < b.w;});
            int vval = 0, bst = 0;
            vector<int> nowv(IT+1);
            set<pii> hi;
            for (int tt = 1; tt<=IT; ++tt) hi.insert({0,tt});
            for (Ev & e : V) {
                if (e.w <= 0) {
                    ++vval;
                    hi.erase({nowv[-e.w],e.w});
                    hi.insert({--nowv[-e.w],e.w});
                }else{
                    hi.erase({nowv[e.w],e.w});
                    hi.insert({++nowv[e.w],e.w});
                }
                bst= (hi.rbegin()->f);
                case1.pb({e.t * 2, bst+vval});
            }
        }

    }

    {
        int nb =0;
        sort(ALL(case1), greater<pii>());
        case1.pb({0,-1});
        int nat = n;
        for (pii & p : case1) {
            while (nat > p.f) {
                if (nat % 2 == 0)
                    ans[nat] = max(ans[nat],nb);
                --nat;
            }
            nb = max(nb, p.s);
        }
        for (int i = 1; i<=n; ++i) {
            bug(i, ans[i]);
        }
    }
    // case 3: 1
    for (int i = 0; i<n; ++i) {
        ans[1] = max(ans[1], SZ(g[i]) + 1);
    }

    for (int i = 1; i<=n; ++i) {
        cout<<max(1,ans[i])<<' ';
    }
}
/*
5
1 2
2 3
1 4
4 5
*/