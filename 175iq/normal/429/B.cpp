#include "bits/stdc++.h"
using namespace std;

//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 

//Constants
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define MOD 998244353 //1000000007  

//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)

//For loops
#define F(i,a,b)   for(int i=a; i<b; i++)
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)

//For debug 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//Definitions
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }

int main()
{   
    fastIO; 
    cini2(n,m); 

    vvlwv(mat,n+2,m+2,0);

    FE(i,1,n)
        FE(j,1,m)
            cin>>mat[i][j];

    vvlwv(dp1to,n+2,m+2,0);
    vvlwv(dp1from,n+2,m+2,0);
    vvlwv(dp2to,n+2,m+2,0);
    vvlwv(dp2from,n+2,m+2,0);

    FE(i,1,n)
        FE(j,1,m)
            dp1to[i][j] = mat[i][j] + max(dp1to[i-1][j], dp1to[i][j-1]);

    FRE(i,n,1)
        FE(j,1,m)
            dp2to[i][j] = mat[i][j] + max(dp2to[i][j-1], dp2to[i+1][j]);
    
    FRE(i,n,1)
        FRE(j,m,1)
            dp1from[i][j] = mat[i][j] + max(dp1from[i+1][j], dp1from[i][j+1]);

    FE(i,1,n)
        FRE(j,m,1)
             dp2from[i][j] =  mat[i][j] + max(dp2from[i-1][j], dp2from[i][j+1]);

    ll ans = -1e18, temp;
    FE(i,2,n-1)
    {
        FE(j,2,m-1)
        {
            temp = dp1to[i][j-1] + dp2to[i+1][j] + dp1from[i][j+1] + dp2from[i-1][j] ;
            ans = max(temp, ans);
            temp = dp2to[i][j-1] + dp1to[i-1][j] + dp2from[i][j+1] + dp1from[i+1][j] ;        
            ans = max(temp, ans);
        }
    }    
    cout<<ans;
    
    return 0;
}