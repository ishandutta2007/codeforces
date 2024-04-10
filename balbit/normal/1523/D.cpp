#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
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

bitset<maxn> B[61];
bool worth[61];

vector<int> ok;
vector<int> tk;
int half;
vector<int> re;

bitset<maxn> tmp;

void dfs(int at) {
    if (SZ(tk) + SZ(ok) - at <= SZ(re)) return;
    if (at == SZ(ok)) {
        assert(SZ(tk) > SZ(re));
        re = tk;
        return;
    }
    // try no
    dfs(at+1);
    bitset<maxn> bk = tmp;
    tmp &= B[ok[at]];
    tk.pb(ok[at]);
    if ((tmp.count()) >= half) {
        dfs(at+1);
    }
    tk.pop_back();
    tmp = bk;
}

signed main(){
    IOS();
    clock_t t = clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n,m,p; cin>>n>>m>>p;
    REP(i,n) {
        REP(j,m) {
            char c; cin>>c;
            B[j][i] = c=='1';
        }
    }
     half = (n+1)/2;
    REP(j,m) {
        worth[j] = (int)(B[j].count()) >= half;
    }
    REP(i,n) tmp[i] = 1;
    while ((double)(clock() - t) < 2.5 * CLOCKS_PER_SEC) {
        int x = rng() % n;
//        bug(x);
        ok.clear();
        tk.clear();
        REP(j,m) {
            if (worth[j] && B[j][x]) {
                ok.pb(j);
            }
        }
        if (SZ(ok) <= SZ(re)) continue;
        dfs(0);
    }
    vector<int> ret(m);
    for (int y : re) {
        ret[y] = 1;
    }
    for( int tt : ret) cout<<tt;
    cout<<endl;

}