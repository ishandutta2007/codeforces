#include <bits/stdc++.h>
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
#define MOD 1000000007 //998244353
 
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
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

struct val
{
    ll nleaves, w;
    val()
    {
        nleaves = 0, w = 0;
    }
    val(ll l, ll wt)
    {
        nleaves = l;
        w = wt;
    }
    bool operator<(const val& b) const
    {
        return nleaves*(w-w/2) < b.nleaves*(b.w-b.w/2);
    }
};

void solve()
{
    cini(n);
    cinll(S);

    vvpi gr(n+1);
    FE(i,1,n-1)
    {
        cini3(u,v,w);
        gr[u].pb({w,v});
        gr[v].pb({w,u});
    }

    vi dp(n+1, 0);
    ll glsum = 0;
    multiset<val> m;
    function<void(int, int, ll)> dfs = [&](int u, int parent, ll sum)
    {   
        dp[u] = 0;
        if(gr[u].sz == 1){
            glsum += sum;
            dp[u] = 1;
        }
        
        FA(v, gr[u])
        {
            if(v.se == parent)
                continue;
            
            dfs(v.se, u, sum+v.fi);
            dp[u] += dp[v.se];
            m.insert(val(dp[v.se], v.fi));
        }
        return;
    };  

    dfs(1,-1,0);
    
    int move = 0;
    val maxi ;
    while(glsum>S)
    {
        auto it = m.rbegin(); 
        maxi = *it;

        glsum -= (maxi.w-maxi.w/2)*maxi.nleaves;

        move++;

        auto it2 = --m.end();

        m.erase(it2);
        m.insert(val(maxi.nleaves, maxi.w/2)); 
    }
    cout<<move<<endl;
    return;   
}   

int main()
{
    cini(t);
    while(t--)
        solve();
    return 0;
}