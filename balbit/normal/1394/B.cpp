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

const int maxn = 2e5+5;

int n,m,k;
//vector< bitset<maxn> > poss[10];
int nof[10];
vector<bitset<maxn> > who;
vector<int> here[10];
bool bad[100][100];
vector<pii> g[maxn];
bitset<maxn> now;
vector<vector<int> > hv[10];
int re = 0;
vector<int> stk;
void dfs(int at) {
    if (at > k) {
        ++re; return;
    }
    for (int i = 0; i<SZ(here[at]); ++i) {
        bool flg = 1;
        for (int x : stk) {
            if (bad[x][here[at][i]]) {
                flg = 0; break;
            }
        }
//        if (!flg) bug("HI");
        if (!flg) continue;
        stk.pb(here[at][i]);
        dfs(at+1);
        stk.pop_back();
    }
}

signed main(){
    IOS();
    cin>>n>>m>>k;
    for (int i = 0; i<m; ++i) {
        int a,b,w; cin>>a>>b>>w;
        g[a-1].pb({w,b-1});
    }
    for (int i = 0; i<n; ++i) {
        sort(ALL(g[i]));
        vector<int> lst; for (auto &p : g[i]) lst.pb(p.s);
        hv[SZ(g[i])].pb(lst);
    }
    int NOW = 0;
    for (int i = 1; i<=k; ++i) {
        for (int j = 0; j<i; ++j) {
            bitset<maxn> tmp;
            bool flg = 1;
            for (int it = 0; it < SZ(hv[i]); ++it) {
                if (tmp[hv[i][it][j]]) {
                    flg = 0; break;
                }
                tmp[hv[i][it][j]] = 1;
            }
            if (flg) {
                who.pb(tmp);
                for (int it = 0; it < NOW; ++it) {
                    if ((tmp & (who[it])).any()) {
                        bad[it][NOW] = 1;
                        bug(NOW, it);
                    }
                }
                here[i].pb(NOW++);
            }
        }
    }
    dfs(1);
    cout<<re<<endl;

}