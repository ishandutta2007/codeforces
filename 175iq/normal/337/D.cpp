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
vll in(N,0);
vll out(N,0);
int ans=0; 
unordered_set<int> s;

void dfs1(int u, int p=-1)
{
    s.count(u) ? in[u] = 0 : in[u] = -INF;
    int mx = -INF,x; 
    FA(v, gr[u])
    {
        if(v==p) continue;
        dfs1(v,u);
        in[u] = max(in[u],1+in[v]);
    }
}

void dfs2(int u, int p = -1)    
{
    int mx1(-INF), mx2(-INF);
    
    FA(v, gr[u])
    {
        if(v==p) continue;
        if(in[v]>=mx1)
        {   
            mx2=mx1, mx1 = in[v];
        }        
        else if(in[v]>mx2)
        {
            mx2=in[v];
        }
    }

    ll use; 
    FA(v, gr[u])
    {
        if(v==p) continue;
        use =  mx1;
        if(mx1==in[v])
        {
            use = mx2;
        }
        out[v] = 1 + max(out[u], 1+use); 
        if (s.count(v) && out[v]<0) out[v] = 0;
        dfs2(v,u);
    }   
    return;
}

int main()
{
    fastIO;
    cini3(n,m,d);
    cinv(p,m);
    FA(e,p)
    {
        s.insert(e);
    }
    F(i,0,n-1)
    {
        cini2(u,v);
        gr[u].pb(v);
        gr[v].pb(u);
    }
    out[1] = -INF;
    if (s.count(1)) out[1] = 0;
    dfs1(1);
    dfs2(1);
    //coutRV(in,1,n);
    //coutRV(out,1,n); 
    F(i,1,n+1)
    {
        if(in[i]<=d && out[i]<=d)
        {
            ans++;
        }
    }
    cout<<ans;
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