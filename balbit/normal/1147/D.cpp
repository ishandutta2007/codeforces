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
const ll mod = 998244353;


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

const int maxn = 2000+5;

ll re = 0;
string s; int n;
vector<int> a;
vector<pii> g[maxn];
bool seen[maxn];
int col[maxn];

void d(int v) {
    seen[v] = 1;
    for (pii u : g[v]) {
        if (!seen[u.f]) {
            d(u.f);
        }
    }
}

bool dfs(int v) {
    for (pii u : g[v]) {
        if (col[u.f] == -1) {
            col[u.f] = col[v] ^ u.s;
            if (!dfs(u.f)) return 0;
        }else{
            if (col[u.f]!=col[v]^u.s) return 0;
        }
    }
    return 1;
}
int N=0;
void go(int len) {
    memset(col,-1,sizeof col);
    memset(seen, 0, sizeof seen);
    int M = 0;
    for (int i = 0; i<maxn; i++) g[i].clear();
    int st = n-len;
    for (int i = 0; i<n; i++) {
        g[i].pb({n-i-1,0});
    }
    for (int i = st; i<n; i++) {
        g[i+n].pb({n+st-i-1+n,0});
    }
    for (int i = 0; i<n; i++) {
        if (s[i] != '?') {
            g[i].pb({i+n,s[i]-'0'});
            g[i+n].pb({i,s[i]-'0'});
        }
    }
    for (int i = 1; i<st; i++) {
        g[0+n].pb({i+n,0});
        g[i+n].pb({0+n,0});
    }
    g[0+n].pb({st+n,1});
    g[st+n].pb({0+n,1});

    for (int i = 0; i<n*2; i++) {
        bug(i);
        for (pii u : g[i]) {
            bug(u.f,u.s);
        }
    }

    int x = 0;
    for (int i = 0; i<n*2; i++) {
        if (!seen[i]) d(i), ++x;
    }
//    bug("OI");
    for (int i = 0; i<n*2; i++) {
        if (col[i] == -1) {
            col[i] = 0;
            if (!dfs(i)) return;
        }
    }

    bug(len, x);
    re += mpow(2,x); re %= mod;
}

signed main(){
    IOS();
    cin>>s; n = s.length();
    for (int i = 0; i<n; i++) {
        a.pb(min(n-i,i));
    }
    bug("HI");
    for (int i = 1; i<n; i++) {
        bug(i);
        go(i);
    }
    cout<<re*inv(2)%mod<<endl;
}