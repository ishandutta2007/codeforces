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
#define INF 0x3f3f3f3f
 
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
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

#define int ll

ll MOD = 998244353;

ll add(ll x, ll y)
{
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    x = (x + y)%MOD;

    return x;
}


bool full(ll mask){
    return (mask == 0 || mask == 3);
}


void solve()
{
    cini2(n, K);

    ll dp[1010][2020][4]; 
    memset(dp, -1, sizeof(dp));

    function<ll(ll, ll)> get = [&](ll msk, ll nmsk)
    {
        ll cnt = __builtin_popcount(msk^nmsk);
        if(cnt == 0)
            return 0;

        else if(cnt == 2)
        {
            if(__builtin_popcount(msk) == 2 or __builtin_popcount(msk) == 0)
                return 1;
            else
                return 2;
        }
        else
        {
            if(__builtin_popcount(msk) == 2 or __builtin_popcount(msk) == 0)
                return 0;
            else
                return 1;            
        }
    };

    function<ll(ll, ll, ll)> calc = [&](ll pos, ll k, ll msk)
    {
        debug(pos, k, msk);
        if(k < 0)
            return 0ll;

        if(pos == n)
        {
            if(full(msk))
            {
                return (k == 1 ? 1ll : 0ll);
            }
            else
            {
                return (k == 2 ? 1ll : 0ll);
            }
        }

        ll& ans = dp[pos][k][msk];
        if(ans!=-1)
           return ans;

        ans = 0;
        FE(nmsk, 0, 3)
            ans = add(ans, calc(pos+1, k-get(msk, nmsk), nmsk));
        return ans;
    };  

    ll ans = 0;
    FE(msk, 0, 3)
        ans = add(ans, calc(1, K, msk));

    cout<<ans;
    return; 
}

signed main()
{
    fastIO;
    int t = 1;
    // cin>>t;    
    while(t--){
        solve();
    }
    return 0;
}