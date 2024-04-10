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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e6+5;

struct edge{
    int a,b,w;
};
vector<edge> Es;
int par[maxn*2];

int find(int x) {return x == par[x]? x : par[x] = find(par[x]);}

int Av[maxn], Bv[maxn];
signed main(){
    IOS();

    int m,n; cin>>m>>n;
    for (int i = 0; i<m; ++i) {
        cin>>Av[i];
    }
    for (int i = 0; i<n; ++i) {

        cin>>Bv[i];
    }
    ll sm= 0;
    for (int i = 0; i<m; ++i) {
        int k; cin>>k;
        for (int j = 0; j<k; ++j) {
            int X; cin>>X; --X;
            sm += Av[i] + Bv[X];
            Es.pb({i + n, X, Av[i] + Bv[X]});
        }
    }
    for (int i = 0; i<n+m+2; ++i) par[i] = i;
    sort(ALL(Es), [&](edge a, edge b){return a.w > b.w;});
    bug(sm);

    for (edge & e : Es) {
        int a = find(e.a), b = find(e.b);
        if (a != b) {
            par[a] = b;
            sm -= e.w;
            bug(e.w);
        }
    }
    cout<<sm<<endl;
}