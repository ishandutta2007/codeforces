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

const int maxn = 2e5+5;

vector<int> g[maxn];
int par[maxn], d[maxn], ch[maxn], sz[maxn];

void dfs(int v, int p=-1) {
    par[v] = p;
    sz[v] = 1;
    for (int u : g[v]) {
        if (u != p) {
            ch[v] ++;
            d[u] = d[v] + 1;
            dfs(u,v);
            sz[v] += sz[u];
        }
    }
}

signed main(){
    IOS();
    int n,k; cin>>n>>k;
    for (int i = 0; i<n-1; ++i ){
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0);
    priority_queue<pii> pq;
    for (int i = 0; i<n; ++i) {
        if (ch[i] == 0) {
            pq.push({d[i] - sz[i] + 1, i});
        }
    }

    ll re = 0;

    for (int i = 0; i<k; ++i) {
        int v = pq.top().s;
        re += pq.top().f;
        pq.pop();
        if (v != 0) {
            ch[par[v]] --;
            if (ch[par[v]] == 0) {
                int pp = par[v];
                pq.push({d[pp] - sz[pp] + 1, pp});
            }
        }
    }

    cout<<re<<endl;


}