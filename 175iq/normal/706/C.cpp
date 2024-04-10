#include "bits/stdc++.h"
using namespace std;

//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define foreach(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) //traverse an STL data structure
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)[Lambda function]
//sort(begin(v), end(v), [] (int a, int b) { return a > b; });

//Constants
#define EPS 1e-8
//#define INF 1e18
#define MOD 998244353
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,0,a.size()-1)

//For loops
#define F(i,a,b)    for(int i=a; i<b; i++)
#define FE(i,a,b)   for(int i=a; i<=b; i++)
#define FR(i,b,a)   for(int i=b; i>a; i--)
#define FRE(i,b,a)  for(int i=b; i>=a; i--)
#define FA(n,container)   for(auto n : container)

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
#define vb vector<bool> 
#define vvi vector<vector<int> > 
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP 
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Directions
const int fx[4][2]  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n); F(i,0,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n); F(i,0,n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); F(i,0,n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); F(i,0,n) { cin>>a[i]; }

//Input
//The first line of the input contains a single integer n (2n100000)  the number of strings.
//
//The second line contains n integers ci (0ci109), the i-th of them is equal to the amount of energy 
//Vasiliy has to spent in order to reverse the i-th string.
//
//Then follow n lines, each containing a string consisting of lowercase English letters. The total length of 
//these strings doesnt exceed 100000.
//
//Output
//If it is impossible to reverse some of the strings such that they will be located in lexicographical order,
//print -1. Otherwise, print the minimum total amount of energy Vasiliy has to spent.

//int n = 1e5+10; 
ll INF = 1e18;
int main()
{
    fastIO;
    cini(n);
    cinvll(c,n);
    vector <string> vec(n);
    vector<vector<ll> > dp(n, vector<ll> (2,INF)); 

    string s; 
    F(i,0,n)
    {
        cin>>vec[i];
    }   

    dp[0][0] = 0 ; 
    dp[0][1] = c[0] ; 

    vector<string> revvec;
    revvec = vec;
    F(i,0,n)
    {
        reverse(all(revvec[i]));
    }
    F(i,1,n)
    {
        if(vec[i-1] <= vec[i]){
            dp[i][0] = dp[i-1][0];
            debug(0,0,i,i-1,dp[i][0]);
        }
        else if(vec[i-1] > vec[i]){
            dp[i][0] = INF;
            debug(0,1,i,i-1,dp[i][0]);
        }

        if(vec[i-1] <= revvec[i]){
            dp[i][1] = c[i] + dp[i-1][0];
            debug(1,0,i,i-1,dp[i][1]);
        }
        else  if(vec[i-1] > revvec[i]){
            dp[i][1] = INF;
            debug(1,1,i,i-1,dp[i][1]);
        }

        if(revvec[i-1] <= vec[i]){
            dp[i][0] = min(dp[i][0],dp[i-1][1]); 
            debug(2,0,i,i-1,dp[i][0]);
        }
        else if(revvec[i-1] > vec[i]){
            dp[i][0] = min(dp[i][0], INF );
            debug(2,1,i,i-1,dp[i][0]);
        }

        if(revvec[i-1] <= revvec[i]){
            dp[i][1] = min(dp[i][1], c[i]+dp[i-1][1]);
            debug(3,0,i,i-1,dp[i][1]);
        }
        else if(revvec[i-1] > revvec[i]){
            dp[i][1] = min(dp[i][1], INF );
            debug(3,1,i,i-1,dp[i][1]);
        }
    }
    ll ans = min(dp[n-1][0], dp[n-1][1]);
    if (ans>=INF)
        cout<<-1;
    else
        cout<<ans;
    debug(dp);
    return 0; 
}