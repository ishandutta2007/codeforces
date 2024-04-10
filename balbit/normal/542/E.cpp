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

const int maxn = 3e5+5;

vector<int> g[maxn];
bool done[maxn], seen[maxn], col[maxn];
int dst[maxn];
vector<int> cc;
void filldfs(int v){
    done[v]=1;
    cc.pb(v);
    for (int u : g[v]) {
        if (!done[u]) filldfs(u);
    }
}

bool bip(int v){
    seen[v]=1;
    for (int u : g[v]) {
        if (!seen[u]) {
            col[u] = col[v]^1;
            if (!bip(u)) return 0;
        }else{
            if (col[u] == col[v]) return 0;
        }
    }
    return 1;
}

int far(int v) {
    for (int x : cc) dst[x] = iinf;
    dst[v]=0;
    queue<int> q ({v});
    int mxd = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : g[v]) {
            if (dst[u] > dst[v]+1) {
                dst[u] = dst[v]+1;
                MX(mxd,dst[u]);
                q.push(u);
            }
        }
    }
    return mxd;
}

signed main(){
    IOS();
    int n, m; cin>>n>>m;
    for (int i = 0; i<m; i++) {
        int a,b; cin>>a>>b; g[a-1].pb(b-1); g[b-1].pb(a-1);
    }
    int re = 0;
    for (int i = 0; i<n; i++) {
        if (! done[i]) {
            cc.clear();
            filldfs(i);
            bug(i);
            if (!bip(i)) GG();
            int ans = 0;
            for (int x : cc) {
                MX(ans, far(x));
            }
            re += ans;
        }
    }
    cout<<re<<endl;
}