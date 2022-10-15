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

#define REP(i,n) for (int i = 0; i<n; ++i)

int a[maxn*2];
bool a2[maxn*2];
vector<int> at[maxn];
bool take[maxn*2];
ll sig = 0;
bool seen[maxn*2];

vector<int> g[maxn*2];

void dfs(int v, bool b) {
    seen[v] = 1;
    if (b) {
        take[v] = 1; sig +=v;
    }
    for (int u : g[v]) {
        if (!seen[u]) {
            dfs(u,b^1);
        }
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    if (n % 2 == 0) {
        cout<<"First"<<endl;
        for (int i = 1; i<=2*n; ++i) {
            cout<<(i%(n))+1<<' ';
        }
    }else{
        cout<<"Second"<<endl;
        for (int i = 1; i<=2*n; ++i) {
            cin>>a[i%(2*n)];
            a2[i%(2*n)] = SZ(at[a[i%(2*n)]]);
            at[a[i%(2*n)]] .pb(i%(2*n));
        }
        for (int i = 1; i<= n; ++i) {
            g[at[i][0]].pb(at[i][1]);
            g[at[i][1]].pb(at[i][0]);
            g[i-1].pb(i-1+n);
            g[i-1+n].pb(i-1);
        }
        for (int i = 0; i<n; ++i) {
            if (!seen[i]) {
                dfs(i,0);
            }
        }
        bug(sig, sig % n, sig % (2*n));
        sig %= 2*n;
        for (int i = 1; i<=2*n; ++i) {
            int j = i%(2*n);
            if (take[j] ^ (sig != 0)) {
                cout<<i<<' ';
            }
        }
    }
    cout<<endl;
    int xxx; cin>>xxx;
    return 0;

}