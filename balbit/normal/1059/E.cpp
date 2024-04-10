#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e6+5;

int l[maxn];
ll s[maxn];
ll n,L,S;
ll w[maxn];

vector<int> g[maxn];
vector<ll> ps;

ll re = 0;

void dfs(int v) {
//    bug(v);
    ps.pb(ps.back() + w[v]);
    int fr = -1;
    int bst = -1;
    for (int u : g[v]) {
        dfs(u);
//        bug(v,u);
//        bug(v,u,s[u]);
        int to = upper_bound(ps.rbegin(), ps.rend(), ps.back() - s[u], greater<ll>()) - ps.rbegin() -1;

        bug(v,u, s[u], to);

        int gt = min(l[u]-1, to);
        if (gt > fr) {
            fr = gt;
            bst=u;
        }
    }
    bug(bst);
    if (bst == -1 || fr <= 0) {
        ++re;
        s[v] = S-w[v]; l[v] = L;
    }else{
        s[v] = s[bst] - w[v];
        l[v] = l[bst]-1;
    }
    ps.pop_back();
}

signed main(){
    IOS();
    cin>>n>>L>>S;
    for (int i = 0; i<n; ++i) {
            cin>>w[i]; if (w[i]>S) GG();
    }
    for (int i = 1; i<n; ++i) {
        int p; cin>>p;
        g[p-1].pb(i);
    }
    ps.pb(0);
    bug("HI");
    dfs(0);
    cout<<re<<endl;

}