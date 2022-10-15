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

const int maxn = 2e5+5;

vector<int> g[maxn], gt[maxn];
int d[maxn];

signed main(){
    IOS();
    int n,m; cin>>n>>m;
    for (int i = 0 ; i<m; i++) {
        int a, b; cin>>a>>b;
        --a; --b;
        g[a].pb(b);
        gt[b].pb(a);
    }
    int k; cin>>k;
    vector<int> p(k);
    for (int i = 0;i<k; i++) {
        cin>>p[i]; --p[i];
    }
    int S = p[0], T = p[k-1];
    queue<int> q;
    fill(d, d+maxn, iinf);
    q.push(T);
    d[T]=0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : gt[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    for (int i = 0; i<n; i++) bug(i,d[i]);
    int mn = 0, mx = 0;
    for (int i = 0; i<k; i++) {
        int v = p[i];
        if (i != k-1) {
            int nok = 0;
            for (int u : g[v]) {
                if (d[u] == d[v] - 1) {
                    nok++;
                }
            }
            assert(nok!=0);
            if (nok > 1 || d[p[i]] != d[p[i+1]] +1) mx++;
            if (d[p[i]] != d[p[i+1]] +1) mn++;
        }
    }
    cout<<mn<<' '<<mx<<endl;
}