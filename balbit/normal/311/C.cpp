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
#define pli pair<ll, int>
vector<pli > at[10005]; // distance, id
ll c[maxn];

auto cmp = [&](pli a, pli b) {
    if (a.f == b.f) return a.s > b.s;
    return a.f < b.f;
};

priority_queue<pli, vector<pli>, decltype(cmp)> hv (cmp); // which do i have
bool fine[maxn], over[maxn];
ll d[10005];
vector<pair<int, ll> > g[10005];
int n,m,k;
void dij(){
    fill(d, d+k, 1e18+333);
    d[0] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push({0,0});
    while (!pq.empty()) {
        int v = pq.top().s; ll w = pq.top().f; pq.pop();
        if (d[v] != w) {
            continue;
        }
        for (pair<int, ll> u : g[v]) {
            if (d[u.f] > w + u.s) {
                d[u.f] = u.s + w;
                pq.push({d[u.f],u.f});
            }
        }
    }
    for (int i = 0; i<k; i++) {
        bug(i, d[i]);
    }
    while (!hv.empty()) hv.pop();
    for (int i = 0; i<k; i++) {
        for (pli ele : at[i]) {
            if (!over[ele.s] && ele.f >= d[i]) {
                bug(c[ele.s],ele.s);
                fine[ele.s]=1;
                hv.push({c[ele.s],ele.s});
            }
        }
    }
}

signed main(){
    IOS();
    ll h; cin>>h;
     cin>>n>>m>>k;
    for (int i = 0; i<n; i++) {
        ll a; cin>>a; --a; at[a%k].pb({a,i}); cin>>c[i];
    }
    dij();
    for (int cnt = 0; cnt<m; cnt++) {
        int TP; cin>>TP;
        if (TP == 1) {
            // Destroy
            ll x; cin>>x;
            for (int i = 0; i<k; i++) {
                g[i].pb({(i+x)%k,x});
            }
            dij();
        }
        if (TP == 2) {
            int x,y; cin>>x>>y;
            --x;
            c[x] -= y;
            if (fine[x] && !over[x])
                hv.push({c[x],x});
        }
        if (TP == 3) {
            while (!hv.empty() && (c[hv.top().s]!=hv.top().f || over[hv.top().s] ) )  hv.pop();
            if (hv.empty()) {
                bug("wtf");
                cout<<0<<endl; continue;
            }
            else{
                cout<<hv.top().f<<endl;
                over[hv.top().s] = 1;
                hv.pop();
            }
        }
    }
}