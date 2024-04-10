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

const int maxn = 1e6+5;

vector<int> g[maxn];
bool seen[maxn];
bool col[maxn];
vector<int> re;
inline void add(int v) {
    re.pb(v); col[v] ^= 1;
}

void dfs(int v, int p=-1) {
    add(v); seen[v] = 1;
    for (int u : g[v]) {
        if (!seen[u]) {
            dfs(u,v);
            add(v);
        }
    }
    if (col[v]) {
        if (p != -1) {
            add(p);
            add(v);
        }else{
            re.pop_back();
        }
    }
}

signed main(){
    IOS();
    int n,m; cin>>n>>m;
    for (int i = 0; i<m; ++i) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    vector<int> c1;
    for (int i = 0; i<n; ++i) {
        cin>>col[i];
        if (col[i] == 1) {
            c1.pb(i);
        }
    }
    if (SZ(c1) == 0) {
        cout<<0<<endl; return 0;
    }
    dfs(c1[0]);
    for (int x : c1) if (!seen[x]) {
        cout<<-1<<endl; return 0;
    }
    cout<<SZ(re)<<endl;
    for (int x : re) cout<<x+1<<' ';

}