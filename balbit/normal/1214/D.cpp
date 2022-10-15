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

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"0\n"; exit(0);}

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

const int maxn = 1e5+5;



main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<vector<char> > g(n+1);
    vector<vector<int> > dp(n+1);
    vector<vector<int> > dd(n+1);
    REP(i,n+1){ 

        g[i].resize(m+1); dp[i].resize(m+1); dd[i].resize(m+1);
    }
    dp[0][0] = 1;
    REP(i,n){
        REP(j,m){
            cin>>g[i][j]; 
            if (g[i][j] =='#') dp[i][j] = 0;
            if (g[i][j]=='.') {
                dp[i][j+1] |= dp[i][j]; dp[i+1][j] |= dp[i][j];
            }
        }
    }
    if (dp[n-1][m-1]==0){
        GG();
    }
    dd[n-1][m-1] = 1;
    vector<int> nin(n+m+1);
    RREP(i,n) RREP(j,m){
        if (i==n-1 && j==m-1) continue;
        if (i==0 && j==0) continue;
        if (g[i][j] == '.') {
            dd[i][j] = dd[i+1][j] | dd[i][j+1];
            // cout<<x<<endl;
            if (dd[i][j] && dp[i][j]) nin[i+j]++;
        }
    }
    FOR(i,1,n-1+m-1){
        if (nin[i]==1){
            cout<<1<<endl; return 0;
        }
    }
    cout<<2<<endl;
}