#include <bits/stdc++.h>
using namespace std;
        
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
 
//Constants
#define EPS 1e-6
#define INF 2e9+7
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
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
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s; s = "#"+s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

void solve()
{
    cini(n);    
    vector<vector<ld> > p(n, vector<ld> (n,0));

    FE(i,0,n-1)
        FE(j,0,n-1)
            cin>>p[i][j];    

    // FE(i,0,n-1)
    //     FE(j,0,n-1)
    //         cout<<p[i][j]<<" \n"[j==n-1];    

    ld dp[1<<n];
    // memset(dp, (ld)(-1), sizeof(dp));

    FE(i,0,(1<<n)-1)
        dp[i] = (ld)(-1.0) ;

    // FE(i,0,(1<<n)-1){
    //     debug(i, dp[i]);
    // }

    // cout<<"\n";

    function<ld(int, int)> sumprob = [&](int prevmask, int pos)
    {
        ld temp = 0;

        ld alive = __builtin_popcount(prevmask);
        // debug(alive);
        // if(alive <= 1)
        //     return 
        FE(i,0,n-1)
            if( prevmask&(1<<i) ) 
                temp += p[i][pos];

        temp *= 2.0/(alive*(alive-1));
        return temp;
    };

    function<ld(int)> calc = [&](int curmask)
    {
        int k = __builtin_popcount(curmask);
        if(k == n)
            return (ld)1;

        ld& ans = dp[curmask];
        if(ans > -0.9)
            return ans;

        ans = (ld)0;
        FE(pos, 0, n-1)
        {
            if(!(curmask & (1<<pos)))
            {
                int prevmask = curmask^(1<<pos); 
                ld prevprob  = calc(prevmask);
                ans += (prevprob*sumprob(prevmask, pos));
            }
        }
        // debug(ans);
        return dp[curmask] = ans; 
    };

    cout<<fixed;
    cout<<setprecision(6);
    FE(pos, 0, n-1)
    {
        cout<<calc(1<<pos)<<" ";
        debug(1<<pos, calc(1<<pos));
    }

    return; 
}
 
int main()
{
    fastIO;
    int t = 1;
    // cin>>t;    
    while(t--)
        solve();
    return 0;
}