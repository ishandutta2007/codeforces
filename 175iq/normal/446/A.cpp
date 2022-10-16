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
    cini(n);
    if(n==1){
        cout<<1;
        return 0;
    }
    cinv(a,n);

    vi maxstart(n+2,1);
    vi maxend(n+2,1);

    FE(i,2,n)
    {
        if(a[i] > a[i-1])
            maxend[i] = maxend[i-1] + 1;
    }

    FRE(i,n-1,1)
    {
        if(a[i] < a[i+1])
            maxstart[i] = maxstart[i+1] + 1;
    }

    int ans = -INF;
    FE(i,1,n)
        ans = max({ans, maxstart[i], maxend[i]});

    if(a[1]>=a[2])
        ans = max(ans, 1 + maxstart[2]);

    if(a[n-1]>=a[n])
        ans = max(ans, 1 + maxend[n-1]);

    FE(i,2,n-1) 
    {
        if(a[i]>=a[i+1])
            ans = max(ans, 1 + maxstart[i+1]);

        if(a[i-1]>=a[i])
            ans = max(ans, 1 + maxend[i-1]);

        if(a[i-1] >= a[i] && a[i] <= a[i+1] && a[i-1]+1<a[i+1]){
            ans = max(ans, 1 + maxend[i-1] + maxstart[i+1]);
        }

        if(a[i-1] <= a[i] && a[i] >= a[i+1] && a[i-1]+1<a[i+1]){
            ans = max(ans, 1 + maxend[i-1] + maxstart[i+1]);
        }
    }
    cout<<ans;
    return 0;
}