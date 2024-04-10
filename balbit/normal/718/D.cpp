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

const int maxn = 1e6+5;

vector<int> g[maxn];
int sz[maxn];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u,v);
            sz[v] +=sz[u];
        }
    }
}

int tot = 0;
int par[maxn];
int findcen(int v, int p) {
    par[v] = p;
    for (int u : g[v]) {
        if (u != p) {
            if (sz[u]*2 >= tot ) {
                return findcen(u,v);
            }
        }
    }
    return v;
}

map<vector<int>, int> mp;
set<int> have;
int myval[maxn];
int dp[maxn];
int IT = 1;
//    map<int, int> tmp;
void dd(int v, int p) {
    vector<int> fren;
    vector<pii> stuff;
//    tmp.clear();

    for (int u : g[v]) {
        if (u != p) {
            dd(u,v);
            fren.pb(myval[u]);
            stuff.pb({myval[u],u});
        }
    }
    sort(ALL(fren));
    sort(ALL(stuff));
    if (!mp.count(fren)) mp[fren] = IT++;
    myval[v]=mp[fren];

    bug(v, myval[v]);
    REP(i, SZ(stuff)) {
        if (i == 0 || fren[i] != fren[i-1]) {
            dp[v] += dp[stuff[i].s];
        }
    }
    if (SZ(g[v]) != 4){
        ++dp[v];
    }
    bug(v, myval[v], dp[v]);
//    if ()
}

signed main(){
    IOS();

    int n; cin>>n;
    REP(i,n-1) {
        int a,b; cin>>a>>b; --a;--b;
        g[a].pb(b); g[b].pb(a);
    }
    tot = n;
    dfs(0, -1);
    int c1 = findcen(0,-1);
    int c2 = -1;
    bug(sz[c1]);

    if (sz[c1] *2 == tot) {
        c2 = par[c1];
    }
    bug(c1,c2);
    dd(c1, c2);
    if (c2 != -1)
        dd(c2, c1);
    if (c2 == -1) {
        cout<<dp[c1]<<endl;
    }else{
        if (myval[c1] == myval[c2]) {
            cout<<dp[c1]<<endl;
        }else{
            cout<<dp[c1]+dp[c2]<<endl;
        }
    }
//    cout<<SZ(have)<<endl;
}