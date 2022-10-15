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

const int maxn = 1e5+5;

vector<int> g[maxn];
int dp[maxn], l[maxn], mx1[maxn], mx2[maxn];
//int K = 0;

int ans[maxn], par[maxn];
vector<int> ord;

void dfs(int v, int p) {
    par[v] = p;
    for (int u : g[v]) {
        if (u!=p) {
            dfs(u,v);
        }
    }
    ord.pb(v);
}

//void dfs(int v, int p) {
//    dp[v] = 0;
//    int mx1 = 0, mx2 = 0;
//    for (int u : g[v]) {
//        if (u != p) {
//            dfs(u,v);
//            dp[v] += dp[u];
//            if (l[u] > mx2) {
//                mx2 = l[u];
//                if (mx2 > mx1) swap(mx2, mx1);
//            }
//        }
//    }
//    if (mx1 + mx2 >= K) {
//        dp[v] ++; l[v] = 0;
//    }else{
//        l[v] = mx1+1;
//    }
//}

inline int ansof(int k) {
    memset(mx1, 0, sizeof mx1);
    memset(mx2, 0, sizeof mx2);
    memset(dp, 0, sizeof dp);
    memset(l, 0, sizeof l);
    for (int v : ord) {
        int p = par[v];
        if (mx1[v] + mx2[v] >= k) {
            ++dp[v];
        }else{
            l[v] = mx1[v]+1;
            if (l[v] > mx1[p]) {
                mx2[p] = mx1[p]; mx1[p] = l[v];
            }else if (l[v] > mx2[p]) {
                mx2[p] = l[v];
            }
        }
        if (v) dp[p] += dp[v];
    }
    return dp[0];
}

void go(int l, int r) {
    // range is [l,r]
    if (l >= r-1) return;
    if (ans[l] == ans[r]) {
        for (int i = l+1; i<=r-1; ++i) ans[i] = ans[l];
        return;
    }
    int mid = (l+r)/2;
    ans[mid] = ansof(mid-1);
    go(l,mid);
    go(mid,r);
}

signed main(){
    IOS();
    int n; cin>>n;
    for (int i = 0; i<n-1; ++i) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0,0);
    ans[0] = 1000000000;
    ans[n+1] = -1;
    go(0,n+1);
    for (int i = 1; i<=n; ++i) {
        cout<<ans[i]<<"\n";
    }

}