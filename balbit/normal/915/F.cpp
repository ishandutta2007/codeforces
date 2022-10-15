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

const int maxn = 1e6+5;

ll par[maxn], sz[maxn];
ll V[maxn];
vector<int> g[maxn];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int a, int b){
    a = find(a); b = find(b);
    if (a == b) return;
    sz[a] += sz[b];
    par[b] = a;
}
bool done[maxn];
void reset(){
    for (int i = 0; i<maxn; i++) {
        par[i] = i;sz[i]=1;done[i] = 0;
    }

}

vector<int> vat;

signed main(){
    IOS();
    int n; cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>V[i];
        vat.pb(i);
    }
    sort(ALL(vat),[&](int a, int b) {return V[a] < V[b]; });
    for (int i = 0; i<n-1; ++i) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    reset();
    ll re = 0;
    for (int i = 0; i<n; i++) {
        int v = vat[i]; // from smallest to biggest

        for (int u : g[v]) {
            if (done[u]) {
                int psz = sz[v];
                merge(v,u);
                re += (sz[v] - psz) * (psz) * V[v];
            }
        }
        bug(v, V[v], sz[find(v)]);
//        re += (sz[find(v)]-1) * V[v];
        done[v] = 1;
    }
    bug(re);
    reverse(ALL(vat));

    reset();
    for (int i = 0; i<n; i++) {
        int v = vat[i]; // from smallest to biggest
        for (int u : g[v]) {
            if (done[u]) {
                int psz = sz[v];
                merge(v,u);
                re -= (sz[v] - psz) * (psz) * V[v];
            }
        }
        bug(v, V[v], sz[find(v)]);
//        re -= (sz[find(v)]-1) * V[v];
        done[v] = 1;
    }
    cout<<re<<endl;
}