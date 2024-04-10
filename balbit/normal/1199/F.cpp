
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

const int maxn = 1e5+5;

char g[51][51];
int ps[51][51];
int dp[51][51][51][51];
bool ok[51][51][51][51]; 

int sum(int l1, int l2, int r1, int r2){
    swap(l1,r1); swap(l2,r2);
    int re =  ps[l2+1][r2+1] - ps[l1][r2+1] - ps[l2+1][r1] + ps[l1][r1];
    // if (re<0) {
    //     cout<<re<<' ';
    //     cout<<l1<<' '<<l2<<' '<<r1<<' '<<r2<<endl;
    //     debug(ps[l2+1][r2+1]);
    //     debug(ps[l1][r2+1]);
    //     debug(ps[l2+1][r1]);
        
    //     assert(0);
    // }
    // assert(re>=0); 
    // assert(re>=0);
    return re;
}

int n;

ll f(int l1, int l2, int r1, int r2){
    // assert(l2>=l1); assert(r2>=r1);
    //  // if (sum(l1,l2,r1,r2)==0) {
    //  //    cout<<l1<<' '<<l2<<' '<<r1<<' '<<r2<<endl;
        
    //  // }
    //  // cout<<"RUN"<<endl;
     if (ok[l1][l2][r1][r2]) return dp[l1][l2][r1][r2];
     
     dp[l1][l2][r1][r2] = max(r2-r1, l2-l1)+1;
     FOR(i,l1,l2+1) {
        int M = 0; 
        
        if (sum(i,i,r1,r2)!=0) {
            continue;
        }
        if (i!=l1){
            M += f(l1,i-1,r1,r2); 
        }
        if (i!=l2) {
            M += f(i+1,l2,r1,r2); 
        }
        // if (M == 0 && l1 ==0 && l2 == n-1 && r1 == 0 && r2 == n-1) {
        //     cout<<"CUT "<<i<<endl;
        // }
        MNTO(dp[l1][l2][r1][r2], M);
     }
     FOR(i,r1,r2+1) {
        int M = 0; 
        
        if (sum(l1,l2,i,i)!=0) {
            continue;
        }
        if (i!=r1){
            M += f(l1,l2,r1,i-1);
        }
        if (i!=r2) {
            
            M += f(l1,l2,i+1,r2);
        }
        // if (M == 0 && l1 ==0 && l2 == n-1 && r1 == 0 && r2 == n-1) {
        //     cout<<"CUTE "<<i<<endl;
        // }
        MNTO(dp[l1][l2][r1][r2], M);
     }
     ok[l1][l2][r1][r2] = 1;
     return dp[l1][l2][r1][r2];
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    REP(i,n) REP(j,n) cin>>g[i][j];
    REP(i,n) REP(j,n){
        if (g[i][j]=='#') ps[i+1][j+1]++;
        ps[i+1][j+1] += ps[i+1][j] + ps[i][j+1] - ps[i][j];
        // cout<<ps[i+1][j+1]<<" \n"[j==n-1];
        // debug(ps[i+1][j+1]);
    }
    REP(i,51)REP(j,51)REP(k,51)REP(mm,51){
        dp[i][j][k][mm]=iinf;
    }
    // REP(i,n)REP(j,n)REP(k,n)
    // debug(f(0,0,0,0));
    cout<<f(0,n-1,0,n-1)<<'\n';

    
} 

/*
4
#...
....
....
#...
*/