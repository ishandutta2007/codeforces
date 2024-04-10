#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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

const int maxn = 1e5+5;

struct BIT{
    int s[maxn];
    void MO(int e, int v) {for (++e; e<maxn; e+=e&-e){s[e]+=v;}}
    int QU(int e) {int re = 0; for (++e; e>0; e-=e&-e){re += s[e];} return re; }
};

int g[11][maxn];
bool seen[11][maxn][4];
BIT b1, b2;

int mx, mn;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool ok = 0;

int tsig = 0;

void dfs(int r, int c, int d) {
    if (seen[r][c][d]) {ok = 1; return;}
    mx = max(mx, c); mn = min(mn, c);
    seen[r][c][d] = 1;
    for (int i = -1; i<3; ++i) {
        int j = (i+d+4)%4;
        if (r+dx[j] >=0 && c+dy[j] >=0 && g[r+dx[j]][c+dy[j]] == g[r][c]) {
            tsig += i;
            dfs(r+dx[j],c+dy[j],j); return;
        }
    }
}

vector<int> faces[maxn];

signed main(){
    IOS();
    int n,m,q; cin>>n>>m>>q;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            cin>>g[i][j];
        }
    }
    for (int j = 0; j<m; ++j) {
        for (int i = 0; i<n;++i) {
            for (int d = 0; d<4; ++d) {
                if (i-dx[d] >=0 && j-dy[d] >= 0 && g[i-dx[d]][j-dy[d]] == g[i][j] && !seen[i][j][d]) {
                    mx = -1; mn = 100000000; ok = 0;
                    tsig = 0;
                    dfs(i,j,d);
                    bug(ok);
                    if (ok && tsig == -4) { //assert(mx != mn); 
                        bug(tsig);
                        bug(i,j,d,mn,mx);
                        faces[mn].pb(mx);
                    }
                }
            }
        }
    }
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            if (i != n-1) {
                if (g[i][j] == g[i+1][j])
                    b1.MO(j,-1);
            }
            if (j!=m-1 && g[i][j] == g[i][j+1]) 
                b2.MO(j,-1);
        }
    }
    vector<pair<pii, int> > hi;
    for (int i = 0; i<q; ++i) {
        int l,r; cin>>l>>r;
        --l; --r;
        hi.pb({{l,r},i});
    }
    sort(ALL(hi), greater<pair<pii, int>>());
    int mo = m;
    vector<int> ans(q);
    for (int i =0 ; i<q; ++i) {
        int l = hi[i].f.f, r = hi[i].f.s;
        while (mo > l) {
            --mo; for (int rb : faces[mo]) b1.MO(rb,1);
        }
        int vef = n * (r-l+1) + b1.QU(r) - b1.QU(l-1) + b2.QU(r-1) - b2.QU(l-1);
        bug(vef);
        ans[hi[i].s] = vef;
    }
    for (int i = 0; i<q; ++i) {
        cout<<ans[i]<<endl;
    }
}

/*
1
4 5
RWWWW
WWBRW
WRWWW
WBWBW
*/