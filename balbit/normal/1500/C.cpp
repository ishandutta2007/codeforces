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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1502;

//bool cut[maxn]; // cut line below it
int a[maxn][maxn], b[maxn][maxn];
bitset<maxn>need[maxn];
bitset<maxn> fee;
bool done[maxn];
int c[maxn][maxn], d[maxn][maxn];
int n,m;
vector<int> whoa[maxn], whob[maxn];

void chk(int A, int B) {
    REP(j,m) {
        if (a[A][j] != b[B][j]) GG();
    }
}

signed main(){
    IOS();
    cin>>n>>m;
    REP(i,n) REP(j,m) {
        cin>>a[i][j];
    }
    REP(i,n) REP(j,m){
        cin>>b[i][j];
        if (i && b[i][j] < b[i-1][j]) {
            need[j][i-1] = 1;
        }
    }
    vector<int> re;
    bool any = 1;
    while(any) {
        any = 0;
        REP(j,m) {
            if (!done[j] && ((need[j] & fee) == need[j])) {
                // take j
                any = 1;
                done[j] = 1; re.pb(j);
                REP(i,n-1) {
                    if (b[i][j] != b[i+1][j]) {
                        fee[i] = 1;
                    }
                }
            }
        }
    }
    bug(SZ(re)); for (int x : re) bug(x+1);
    int IT = 0;
    for (int C : re) {
        ++IT;
        map<pii, int> mp;
        int cid = 0;
        REP(i,n) {
            pii tt = {c[IT-1][i], a[i][C]};
            if (!mp.count(tt)) {
                mp[tt] = cid++;
            }
            c[IT][i] = mp[tt];
        }
        REP(i,n) {
            pii tt = {d[IT-1][i], b[i][C]};
            if (!mp.count(tt)) {
                GG();
            }
            d[IT][i] = mp[tt];
        }
    }

    REP(i,n) {
        whoa[c[IT][i]].pb(i);
        whob[d[IT][i]].pb(i);
    }
//    return 0;
    REP(i, n) {
        if (SZ(whoa[i]) != SZ(whob[i])) GG();
        bug("HI");
        REP(j, SZ(whoa[i])) {
            chk(whoa[i][j], whob[i][j]);
        }
    }

    cout<<SZ(re)<<endl;
    reverse(ALL(re));
    for (int x : re) cout<<x+1<<' ';
}