#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 2005;

bool grid[maxn][maxn];
int ps[maxn][maxn];

int n, k;

void upd(int r1, int r2, int c1, int c2){
    MXTO(r1, 0); MXTO(c1,0); MNTO(r2,n-1); MNTO(c2,n-1);
    ps[r1+1][c1+1]++;
    ps[r1+1][c2+2]--;
    ps[r2+2][c1+1]--; 
    ps[r2+2][c2+2]++;  
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
     cin>>n>>k;
    REP(i,n) REP(j,n){
        char c; cin>>c; grid[i][j] = c=='B';
    }
    REP(i,n) {
        int mn = 10000, mx = -1; 
        REP(j,n){
            if (grid[i][j]) {
                MNTO(mn,j); MXTO(mx,j);
            }
        }
        if (mx==-1) continue;
        if (mx-mn+1<=k){
            int df = k-(mx-mn+1);
            upd(i-(k-1), i, mn-df, mn);
        }
    }
    int add = 0;
    REP(i,n){
        bool fg = 1;
        REP(j,n) {
            if (grid[i][j]==1) fg=0;
        }add+=fg;
    }
    REP(j,n){
        bool fg = 1;
        REP(i,n) {
            if (grid[i][j]==1) fg=0;
        }add+=fg;
    }
    REP(j,n) {
        int mn = 10000, mx = -1; 
        REP(i,n){
            if (grid[i][j]) {
                MNTO(mn,i); MXTO(mx,i);
            }
        }
        if (mx==-1) continue;
        if (mx-mn+1<=k){
            int df = k-(mx-mn+1);
            upd(mn-df, mn, j-(k-1), j);
        }
    }
    ll re = 0;
    FOR(i,1,n+1) FOR(j,1,n+1){
        ps[i][j] += ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1];
        MXTO(re, ps[i][j]);
        // cout<<ps[i][j]<<" \n"[j==n];
    }
    cout<<re+add<<endl;
}