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

//Input
//The first line of the input contains integer n (1n200)  the number of reposts. 
//Next follow the reposts in the order they were made. Each of them is written on a single line 
//and looks as "name1 reposted name2". All the names in the input consist of lowercase or uppercase 
//English letters and/or digits and have lengths from 2 to 24 characters, inclusive.
//
//We know that the user names are case-insensitive, that is, two names that only differ in the letter
//case correspond to the same social network user.
//
//Output
//Print a single integer  the maximum length of a repost chain.
//

int N = 210;
vvi gr(N);
vi dp(N,-1);
unordered_map <string,int> m;

int dfs(int u, int p=-1)
{
    dp[u] = 1;
    int mx=0;
    FA(v,gr[u])
    {
        if(v==p) continue;
        mx = max(mx,dfs(v,u)); 
        debug(mx,v);
    }
    dp[u]+=mx;
    return dp[u];
}

int main()
{
    fastIO;
    cini(n);
    int x = 0;
    int a1,a3,start;
    F(i,0,n)
    {
        string f1,f2,f3;
        cin>>f1>>f2>>f3;
        transform(f1.begin(), f1.end(), f1.begin(), ::tolower); 
        transform(f3.begin(), f3.end(), f3.begin(), ::tolower); 
        if(m.count(f3))
        {
            a3 = m[f3];
        }
        else
        {
            m[f3]=x++;
            a3 = m[f3];
            if(i==0)
            {
                start = a3;
            }   
        }
        if(m.count(f1))
        {
            a1 = m[f1];
        }
        else
        {
            m[f1]=x++;
            a1 = m[f1];
        }
        debug(a1,a3);
        gr[a3].pb(a1);
        //gr[a1].pb(a3);
    }
    debug(gr);
    dfs(start);
    cout<<dp[start];
    return 0;
}




/*
int N = 2e5 + 100;
vvi gr(N);
vll dp(N,-1);
vll sum(N,-1);
vll a(N);
ll ans=0; 

pair<ll, ll> calcdp(int u, int p, int l)
{
    dp[u]  = l*a[u]; 
    sum[u] = a[u];
    pair<ll, ll> x;
    FA(v,gr[u]) 
    {
        if(v==p)
            continue;
        x = calcdp(v,u,l+1);
        dp[u]  += x.fi;
        sum[u] += x.se;
    }
    return mp(dp[u],sum[u]);
}

void reroot(int u, int p=-1)
{
    ans = max(ans,dp[u]);
    FA(v,gr[u])
    {
        if(v==p)
            continue;
        
        dp[u]  -= dp[v];
        sum[u] -= sum[v];
        dp[v]  += (dp[u]+a[u]+sum[u]);

        reroot(v,u);

        dp[v]  -= (dp[u]+a[u]+sum[u]);
        sum[u] += sum[v];
        dp[u]  += dp[v];
    }    
    return; 
}

int main()
{
    fastIO;
    
    cini(n);
    F(i,1,n+1)
    {
        cin>>a[i];
    }
    F(i,0,n-1)
    {
        cini2(u,v);
        gr[u].pb(v);
        gr[v].pb(u);
    }
    calcdp(1,-1,0);
    reroot(1);
    coutRV(sum,1,n);
    coutRV(dp,1,n);
    cout<<ans;
    return 0;
}
*/