#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
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


void GG(){cout<<"REJECTED\n"; exit(0);}
void YES(){cout<<"ACCEPTED\n"; exit(0);}

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

const int maxn = 1e5+5;


vector<int> here[12];

clock_t T;

int n,m;

void dfs(int at, vector<int> now) { // -1 is unknown
    if (clock() - T > 0.9 * CLOCKS_PER_SEC) {
        YES();
    }
    if (at >= m) {
        // if 2 -1's exist, then die
        int neg = 0;
        bool seen1 = 0;
        REP(i,n) {
            if (now[i] == -1) {
                ++neg;
                if(neg >= 2 || seen1) GG();
            }
            if (now[i] == 0) {
                if (seen1) GG();
            }
            if (now[i] == 1) {
                seen1 = 1;
            }
        }
        return;
    }
    int already0 = 0;
    int free = 0;
    REP(it, SZ(here[at])) {
        int i = here[at][it];
        if (now[i] == -1) {
            free++;
        }else if (now[i] == 0) {
            already0++;
        }
    }
    REP(it, SZ(here[at])) {
        now[here[at][it]] = 1;
    }
    REP(it, SZ(here[at])+1) {
        if (it) now[here[at][it-1]] = 0;
        if ((it) >= already0) {
            if ((it) > (already0 + free)) break;
            dfs(at+1, now);
        }
    }
}

signed main(){
    IOS();
    T = clock();

    cin>>n>>m;
    REP(i,m) {
        int t; cin>>t;
        while (t--) {
            int y; cin>>y;
            here[i].pb(y-1);
        }
        sort(ALL(here[i]));
    }
    vector<int> now(n,-1);
    dfs(0, now);
    cout<<"ACCEPTED"<<endl;


}