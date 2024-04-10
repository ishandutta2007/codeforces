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

const int maxn = 1e2+5;

vector<pii> g[maxn]; // xor of the two values
int val[maxn]; // which ones i already know
bool know[maxn], done[maxn];
int cnt[maxn][26];

void build(int l, int r) {
    if (l > r) return;
    int n = r-l+1;
    cout<<"? "<<l+1<<' '<<r+1<<endl<<flush;
    vector<string> s;
    memset(cnt, 0, sizeof cnt);
    REP(i, n * (n+1) / 2) {
        string r; cin>>r; s.pb(r);
        for (char c: r) {
            cnt[SZ(r)][c-'a'] ++;
        }
    }
//    sort(ALL(s));
    REP(j,26) cnt[(n+3)/2][j] = 0;
    for (int i = (n+1)/2; i>=1; --i) {
        REP(j,26) {
            cnt[i][j] -= cnt[i-1][j];
        }
    }

    for (int i = 1; i<=(n+1)/2; ++i) {
        int chg = 0;
        int df = 0;
        for (int j = 0; j<26; ++j) {
            if (cnt[i][j] > cnt[i+1][j]) {
                df += cnt[i][j] - cnt[i+1][j];
                REP(t, cnt[i][j] - cnt[i+1][j]) chg ^= j;
            }
        }
        assert (df >= 0 && df <= 2);
        int p1 = l + (i-1), p2 = r - (i-1);
        bug(p1, p2, chg);
        if (df == 2) {
            assert(p1 != p2);
            g[p1].pb({p2, chg});
            g[p2].pb({p1, chg});
        }else{
            bug(df, p1, p2);
            assert(p1 == p2);
            know[p1] = 1; val[p1] = chg;
        }
    }

}

void dfs(int v) {
    done[v] = 1;
    for (pii u : g[v]) {
        if (!done[u.f]) {
            val[u.f] = val[v] ^ u.s;
            dfs(u.f);
        }
    }
}

signed main(){
    IOS();

//    int n; cin>>n;
//    for (int i = n; i>=1; --i) {
//        REP(j,n) {
//            cout<<(min(j, n-i) - max(-1ll, j-i));
//        }
//        cout<<endl;
//    }
    int n; cin>>n;
    if (n % 2 == 1) {
        build(0,n-1);
        build(0,n/2);
        build(n/2+1,n-1);
    }else{
        build(0,n-2);
        build(0,(n-1)/2);
        build((n-1)/2+1,n-1);
    }

    REP(i,n) {
        if (know[i] && !done[i]) {
            dfs(i);
        }
    }

    REP(i,n) {
        assert(done[i]);
    }

    cout<<"! ";
    REP(i,n) cout<<(char)('a'+val[i]);
    cout<<endl<<flush;

}