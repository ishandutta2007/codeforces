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

const int maxn = 2e5+5;

pii s[maxn*4];
ll tg[maxn*4];
bool rem[maxn];
vector<int> g[maxn];
int dep[maxn];

void push(int o, int l, int r){
    if (tg[o]) {
        s[o].f += tg[o];
        if (l!=r) {
            tg[o*2] += tg[o];
            tg[o*2+1] += tg[o];
        }
        tg[o] = 0;
    }
}
void MO(int L, int R, ll v, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l>R || r<L) return;
    if (l >= L && r <= R) {
        tg[o] += v;
        push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid);
    MO(L,R,v,o*2+1,mid+1,r);
    s[o] = max(s[o*2], s[o*2+1]);
}


void MOpt(int p, pii v, int o=1, int l=0, int r=maxn-1) {
    if (l>p || r<p) return;
    if (l == r) {
        s[o] = v;
        return;
    }
    int mid = (l+r)/2;
    MOpt(p,v,o*2,l,mid);
    MOpt(p,v,o*2+1,mid+1,r);
    s[o] = max(s[o*2], s[o*2+1]);
}

int IT = 0;

int L[maxn], R[maxn], par[maxn];
void dfs4(int v, int p) {
    par[v] = p;
    L[v] = R[v] = IT++;
    for (int u : g[v]) {
        if (u != p) {
            dfs4(u,v);
            R[v] = R[u];
        }
    }
}

void dfs1(int v, int p) {
    for (int u : g[v]) {
        if (u == p) continue;
        dep[u] = dep[v] + 1;
        dfs1(u, v);
    }
}

ll ans[maxn];

int cov = 0;

void clr(int v) {
    while (v!=-1 && !rem[v] ) {
        ++cov;
        rem[v] = 1;
        int p = par[v];
        bug(v, p);
        MO(L[v], R[v], -1);
        if (v == 0) break;
        v = p;
    }
}

signed main(){
    IOS();

    int n,k; cin>>n>>k;

    REP(i,n-1) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }

    dfs1(0, -1);
    dfs4(0, -1);

    REP(i,n) {
        bug(i, L[i], dep[i]);
        MOpt(L[i], {dep[i]+1, i});
    }

    int yum = 0;

    while (k) {
        pii hi = s[1];
        bug(hi.f, hi.s);
        if (hi.f == 0) {
            break;
        }
        ++yum;
        --k;
        bug(hi.s);
        clr(hi.s);
    }

    bug(cov, k, yum);
    while(k) {
        if ((yum+1) * (n-yum-1) > (yum) * (n-yum)) {
            --k; ++yum;
        }else break;
    }

    int b = n - cov;
    bug(b);

    while (b) {
        if ((n-yum-b) * (yum-b) > ((n-yum-(b-1)) * (yum-(b-1)))) {
            --b;
        }else break;

    }

    cout<<(n-yum-b) * (yum-b)<<endl;



}