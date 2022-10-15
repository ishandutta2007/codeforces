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
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

ll dst[maxn];

vector<pii> g[maxn], tg[maxn]; // beware, multiple edges are a thing!!!!!

int blockc[maxn];
int best[maxn];
ll maybeno[maxn];
ll fardst[maxn];
bool ok[maxn];

signed main(){
    IOS();

    int n,m; cin>>n>>m;
    map<pii, int> mp;
    REP(i,m) {
        int a,b; cin>>a>>b; --a; --b;
        if (a == n-1) continue;
        mp[{a,b}]++;
        ++blockc[a];
//        bug(a,b);
    }
    for (auto u : mp) {
        int a = u.f.f, b = u.f.s, c = u.s;
        g[a].pb({b,c}); tg[b].pb({a,c});
        bug(a,b,c);
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push({0,n-1});

    memset(dst, 0x3f, sizeof dst);
    memset(best, 0x3f, sizeof best);
    dst[n-1] = 0;

    while (!pq.empty()) {
        int v = pq.top().s; ll w = pq.top().f; pq.pop();

        if (dst[v] != w) {
            continue;
        }
        bug(v,w);
        for (pii P : tg[v]) {
            int u = P.f; ll c = P.s;
            bug(v,u,c);
            maybeno[u] += c;
            MX(fardst[u], dst[v] + 1);

//            if (dst[v] + 1 < c) {
//                blockc[u] -= c; blockc[u] += dst[v] + 1; ok[u] = 1;
//            }else{
//                MN(best[u], dst[v] + 1 - c);
//            }



//            ll cu = ok[u]?blockc[u] : blockc[u] + best[u];
            ll cu = blockc[u] + fardst[u] - maybeno[u];
            if (cu < dst[u]) {
                dst[u] = cu;
                pq.push({dst[u], u});
            }
        }
    }

    cout<<dst[0]<<endl;
}