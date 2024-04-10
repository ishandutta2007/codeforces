#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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

const int maxn = 1e3+5;

vector<pii> g[maxn];
int d[maxn][maxn];

void go(int v) {
    memset(d[v], 0x3f, sizeof d[v]);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0,v});
    d[v][v] = 0;
    while (!pq.empty()) {
        pii X = pq.top(); pq.pop();
        int x = X.s;
        if (X.f != d[v][x]) continue;
        for (pii u : g[x]) {
            if (d[v][u.f] > d[v][x] + u.s) {
                d[v][u.f] = d[v][x] + u.s;
                pq.push({d[v][u.f], u.f});
            }
        }
    }
}


signed main(){
    IOS();

    int n,m,k; cin>>n>>m>>k;
    vector<pii> E;
    for (int i = 0; i<m; ++i) {
        int a,b,w; cin>>a>>b>>w;
        --a; --b;
        g[a].pb({b,w});
        g[b].pb({a,w});
        E.pb({a,b});
    }
    for( int i = 0; i < n;++i) {
        go(i);
    }
    ll re = 1000000000000000ll;
    vector<pii> R;
    for (int i = 0; i<k; ++i) {
        int a,b; cin>>a>>b; R.pb({a-1,b-1});
    }
    for (int i = 0; i<m; ++i) {
        int ts = 0;
        for (int j = 0; j<k; ++j) {
            ts += min({d[R[j].f][R[j].s], d[R[j].f][E[i].f] +  d[R[j].s][E[i].s], d[R[j].f][E[i].s] +  d[R[j].s][E[i].f]});
        }
        re = min(re, ts);
    }
    cout<<re<<endl;

}