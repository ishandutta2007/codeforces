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
#define INF INT_MAX
 
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
   
int main()
{
    cini(n);
    cinv(a,n);

    vviwv(dp, 1e5+10, 7, 0);
    vviwv(mark, 1e5+10, 7, 0);

    FE(k,1,5)
        dp[1][k] = 1;

    FE(i,2,n)
    {
        if(a[i]>a[i-1])
        {
            FE(j,1,5)
            {
                if(dp[i-1][j])
                {
                    FE(k,j+1,5)
                    {
                        dp[i][k] = 1;
                        mark[i][k] = j;
                    }
                    break;
                }
            }            
        }
        else if(a[i]<a[i-1])
        {
            FRE(j,5,1)
            {
                if(dp[i-1][j])
                {
                    FRE(k,j-1,1)
                    {
                        dp[i][k] = 1;
                        mark[i][k] = j;
                    }
                    break;
                }
            }
        }
        else if(a[i]==a[i-1])
        {
            FE(j,1,5)
            {
                if(dp[i-1][j])
                {
                    FE(k,1,5)
                    {
                        if(k!=j)
                        {
                            dp[i][k] = 1;
                            mark[i][k] = j;  
                        }
                    }
                }
            }
        }
    }

    int I;
    FE(i,1,5)
    {
        if(dp[n][i]==1)
        {
            I = i;
            goto f;
        }
    }
    cout<<-1;
    return 0 ;
    
    f:;
    vi ans;
    ans.pb(I);
    int cur = I;
    FRE(i, n, 2)
    {
        ans.pb(mark[i][cur]);
        cur = mark[i][cur] ;
    }
    reverse(all(ans));
    FE(i,0, ans.sz-1)
        cout<<ans[i]<<" ";
    return 0;
}