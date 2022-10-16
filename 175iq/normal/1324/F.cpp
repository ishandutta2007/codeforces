#include <bits/stdc++.h>
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
#define INF 0x3f3f3f3f
#define MOD 998244353
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutA(a,0,a.size()-1)
 
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
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n); F(i,0,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n); F(i,0,n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); F(i,0,n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); F(i,0,n) { cin>>a[i]; }
 
int N = 2e5 + 100;
vvi gr(N);
vll dp(N,-1);
vi white(N,0);
vi black(N,0);
vi color(N);
vi consider(N,0);
vi ans(N);
 
pii calccolor(int u, int p=-1)
{
    int whit = 0;
    int blac = 0;
    color[u]==0 ? blac++ : whit++;
    pii x;
    FA(v,gr[u])
    {
        if(v==p)
            continue;
        x = calccolor(v,u);
        whit += x.fi;
        blac += x.se;
    }
    white[u]=whit;
    black[u]=blac;
    return mp(white[u],black[u]);
}
 
ll calcdp(int u, int p=-1)
{
    color[u]==0 ? dp[u]= -1: dp[u]= 1;
    int x ;
    FA(v,gr[u]) 
    {
        if(v==p)
            continue;
        x = calcdp(v,u);    
        if(x>0)
        {
            consider[v]=1;
            dp[u] += x;  
        }
    }
    return dp[u];
}
 
void reroot(int u, int p=-1)
{
    //ans = max(ans,dp[u]);
    //cout<<dp[u]<<" ";
    ans[u]=dp[u];
    FA(v,gr[u])
    {
        if(v==p)
            continue;
        ll befwhiteu = white[u], befblacku = black[u], befdpu = dp[u];
        
        white[u] -= white[v];
        black[u] -= black[v];
        if(consider[v])
        {
            dp[u] -= dp[v];
        }
 
        white[v] += white[u];
        black[v] += black[u];
        if(dp[u]>0)
        {
            dp[v] += dp[u]; 
        }
 
        reroot(v,u);

        white[u] = befwhiteu;
        black[u] = befblacku;
        dp[u] = befdpu;  
    }    
}
 
int main()
{
    fastIO;
    
    cini(n);
    F(i,1,n+1)
    {
        cin>>color[i];
    }
    debug(color);
    F(i,0,n-1)
    {
        cini2(u,v);
        gr[u].pb(v);
        gr[v].pb(u);
    }
    consider[1]=1;
    calccolor(1);
    calcdp(1);
    reroot(1);
    coutRV(ans,1,n);
    return 0;
}