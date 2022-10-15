#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
//#define int ll
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

const int maxn = 2e3+5;

bool g[maxn][maxn];
int dp[maxn];
int n,m,k;
int R[maxn], C[maxn];

int gt(int up){
    REP(i,k) {
        if (i < up) {
            g[R[i]][C[i]] = 0;
        }else{
            g[R[i]][C[i]] = 1;
        }
    }
    memset(dp,0,sizeof dp);
    int re = 0;
    REP(i,n) {
        for (int j = m-1; j>=1; --j) {
            MN(dp[j], dp[j-1]);
        }
        dp[0]=g[i][0]==0?0:1;
        MX(re, dp[0]);
        REP1(j,m-1) {
            if( !g[i][j] ) dp[j] = 0;
            else dp[j] = min(dp[j], dp[j-1]) + 1;
//            bug(i,j,dp[j]);
            MX(re, dp[j]);
        }
    }
    return re;
}

int ans[maxn];

void yoink(int l, int r, int Lv, int Rv) {
    if (l > r) return;
    if (Lv == Rv) {
        for (int i = l; i<=r; ++i) {
            ans[i] = Lv;
        }
        return;
    }
    int mid = (l+r)/2;
    int hi = gt(mid);
    ans[mid] = hi;
    yoink(l,mid-1,Lv,hi);
    yoink(mid+1,r,hi,Rv);
}

int up[maxn][maxn], down[maxn][maxn];
int par[maxn][maxn];
int find(int col, int x) {
    if (x == par[col][x]) return x;
    return par[col][x] = find(col, par[col][x]);
}
void mrg(int col, int a, int b) {
    bug("yay", col, a, b);
    a = find(col, a); b=find(col,b);
    MN(up[col][a], up[col][b]);
    MX(down[col][a], down[col][b]);
    par[col][b] = a;
}

bool ok(int r, int c, int len) {
    multiset<int> upq, dpq;
    int i = max(0, c-len+1);
    int j = i; // j needs to be built
    for (; i <= c && i+len <= m; ++i) {
        while (j < i+len) {
            int yo = find(j,r);
            upq.insert(up[j][yo]); dpq.insert(down[j][yo]);
            ++j;
        }
        bug(i,j,*upq.rbegin(),*dpq.begin());
        if (!upq.empty() && !dpq.empty() && (*dpq.begin() - *upq.rbegin() + 1 >= len)) return 1;
        int ye = find(i,r);
        upq.erase(upq.find(up[i][ye]));
        dpq.erase(dpq.find(down[i][ye]));
    }
    return 0;
}

signed main(){
    IOS();

    cin>>n>>m>>k;
    REP(i,n) REP(j,m) {
        par[j][i] = up[j][i] = down[j][i] = i;
        char c; cin>>c;
        if (c == '.') {
            g[i][j] = 1;
        }
    }

    REP(i,k) {
        cin>>R[i]>>C[i]; --R[i]; --C[i];
        g[R[i]][C[i]] = 0;
    }
    REP(i,n) REP(j,m) {
        if (g[i][j]) {
            if (i && g[i-1][j]) mrg(j, i-1,i);
            if (i!=n-1 && g[i+1][j]) mrg(j,i+1,i);
        }
    }

//    bug(gt(0));
//    bug(gt(1000));

    int now = gt(k);
    bug(now);
    ans[k] = now;

    bug(now);

    for (int at = k-1; at>=1; --at) {
        // removing i
        int i = R[at]; int j =C[at];
        bug(i,j);
        g[i][j] = 1;
        if (i && g[i-1][j]) mrg(j, i-1,i);
        if (i!=n-1 && g[i+1][j]) mrg(j,i+1,i);

        while (1) {
//            bug("eff", now);
//            assert(ok(i,j,now));
            if (ok(i,j,now+1)) ++now;
            else break;
        }
        ans[at] = now;

    }

//    yoink(1+1, k-1, ans[1], ans[k]);

    REP1(i,k) {
        cout<<ans[i]<<endl;
    }


}

/*
5 5 2
.....
.....
.....
.....
.....
1 1
3 3


....X...
X.....X.
....X...
.....X..
.X......
...X....
........
*/