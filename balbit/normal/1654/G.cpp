#include <bits/stdc++.h>
//#define int ll
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

const int maxn = 2e5+5;

vector<int> g[maxn];
int H[maxn];
int n;
bool h0[maxn];

void bfs(){
    queue<int> q; fill(H, H+n, iinf);
    REP(i,n) {
        if (h0[i]) {
            q.push(i); H[i] = 0;
        }
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : g[v]) {
            if (H[u] > H[v] + 1) {
                H[u] = H[v] + 1; q.push(u);
            }
        }
    }
}

int Q[maxn];
int kin[maxn];
bool spec[maxn];  // special nodes
int rch[maxn];

void run(int h) {
    int qf = 0, qe = -1;
    memset(kin, 0x3f, sizeof kin);
    REP(i,n) {
        if (spec[i] && H[i] == h) {
            Q[++qe] = i;
            kin[i] = 0;
        }
    }
    while (qe >= qf) {
        int v = Q[qf++];
        for (int u : g[v]) {
            if (H[u] < H[v]) continue;
            int df = H[u] > H[v] ? -1 : 1;
            if (kin[u] > max(kin[v] + df, 0)) {
                kin[u] = max(kin[v] + df, 0); Q[++qe] = u;
            }
        }
    }
    REP(i,n) {
        bug(i, kin[i]);
        if (kin[i] <= 0) {
            MN(rch[i], h);
        }
    }
}



signed main(){
    IOS();
    cin>>n;
    REP(i,n) cin>>h0[i];
    REP(i,n-1) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    bfs();
//    REP(i,n) bug(i, H[i]);
    vector<int> hs;
    REP(i,n) {
        for (int u : g[i]) {
            if (H[u] == H[i]) {
                spec[i] = 1; bug("spec!", i);
                hs.pb(H[i]);
            }
        }
    }
    memset(rch, 0x3f, sizeof rch);
    SORT_UNIQUE(hs);
    for (int h : hs) {
        run(h); bug(h);
    }
//    run(0);
    REP(i,n) {
//        bug(i, rch[i]);
        if (rch[i] == 0x3f3f3f3f) {
            cout<<H[i]<<' ';
        }else{
            cout<<H[i] * 2 - rch[i]<<' ';
        }
    }
}