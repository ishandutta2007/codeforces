#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
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

int d[maxn];
int tk[maxn];
vector<int> g[maxn];
signed main(){
    IOS();
    int n, m; cin>>n>>m;
    int h, t; cin>>h>>t;
    int ND = h+t+1;
    REP(i,m) {
        int a, b; cin>>a>>b; g[a].pb(b); g[b].pb(a); d[a]++; d[b]++;
    }
    REP1(i,n) {
#ifdef BALBIT
    assert(*max_element(tk,tk+n)==0);
#endif // BALBIT
        if (d[i]<h+1) continue;
        for (int v : g[i]) {
            if (d[v]<t+1) continue;
            vector<int> hd, td;
            for (int u : g[i]) {
                if (u!=v) tk[u] = 1;
            }
            for (int u : g[v]) {
                if (u==i) continue;
                if (!tk[u]) td.push_back(u);
                else tk[u]++;
            }
            vector<int> both;
            for (int u : g[i]) {
                if (tk[u]==1) hd.push_back(u);
                if (tk[u]==2) both.push_back(u);
                tk[u]=0;
            }
            while (SZ(both) && SZ(hd)<h) hd.push_back(both.back()),both.pop_back();
            while (SZ(both) && SZ(td)<t) td.push_back(both.back()),both.pop_back();
            if (SZ(hd)>=h && SZ(td)>=t) {
                cout<<"YES"<<endl;
                cout<<i<<' '<<v<<endl;
                REP(j,h) cout<<hd[j]<<' ';
                cout<<endl;
                REP(j,t) cout<<td[j]<<' ';
                cout<<endl; return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}