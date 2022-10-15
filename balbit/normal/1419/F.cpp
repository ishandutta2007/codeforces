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

const int maxn = 1e5+5;

int x[maxn], y[maxn];
int n;
int col[maxn];
int has[maxn][4];
int cnt[maxn];

struct ev{
    int x, l, r, c;
    bool rem;
    bool operator < (ev &o) {
        return x != o.x?x<o.x: rem<o.rem; // add first, rem later
    }
};

void dfs(int v, int c, int R) {
    col[v] = c;
    REP(i,n) {
        if (col[i] == -1 &&
            (abs(x[i] - x[v]) + abs(y[i] - y[v]) <= R) && (x[i] == x[v] || y[i] == y[v])
            ) {
            dfs(i, c, R);
        }
    }
}

bool test(ll R) {
//    R *= 2; // transformation
    // remove first???? no add first, then remove
    int NCOL = 0;
    memset(col, -1, sizeof col);
    REP(i,n) {
        if (col[i] == -1) {
            dfs(i, NCOL++, R);
        }
//        if (col[i] == -1) col[i] = NCOL++;
        bug(i, R, col[i]);
    }
    if (NCOL <= 1) return 1;
    if (NCOL > 4) return 0; // this is my claim
    bug(R, NCOL);
    vector<ev> Events;

    vector<int> ho;

    REP(i,n) {
        int X = x[i], Y = y[i];
        Events.pb({X-R, Y, Y, col[i],0});
        Events.pb({X+R, Y, Y, col[i],1});
        Events.pb({X, Y-R, Y+R, col[i],0});
        Events.pb({X, Y-R, Y+R, col[i],1});
        ho.pb(Y-R); ho.pb(Y+R); ho.pb(Y);
    }

    sort(ALL(Events));

    SORT_UNIQUE(ho);

    memset(has, 0, sizeof has);
    memset(cnt, 0, sizeof cnt);
    for (ev e : Events) {
        int L = lower_bound(ALL(ho), e.l) - ho.begin();
        int Rar = lower_bound(ALL(ho), e.r) - ho.begin();
        for (int i = L; i<=Rar; ++i) {
            has[i][e.c] += (e.rem?-1:1);
            if (e.rem && has[i][e.c] == 0) {
                cnt[i]--;
            }
            if (!e.rem && has[i][e.c] == 1) {
                cnt[i]++;
                if (cnt[i] == NCOL) return 1;
            }
        }
    }
    return 0;

}

signed main(){
    IOS();
    cin>>n;
    REP(i,n) {
        cin>>x[i]>>y[i];
    }
    ll l = 0, r = 2e9+3;
    while (l!=r) {
        ll mid = (l+r)/2;
        if (test(mid)) {
            r = mid;
        }else l = mid+1;
    }
    if (l > 2e9+2) l = -1;
    cout<<l<<endl;



}