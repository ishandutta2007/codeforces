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
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug `
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
#define cins(s) string s; cin>>s; s = "#"+s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

int N = 1e3+10;
vvi gr(N);
 
vi color(N,0);
vi comp, last;
int dp[2000][1010];  
vi actual_w, actual_b;

void dfs(int u)
{
    comp.pb(u);
    color[u]=1;
    FA(v, gr[u])
    {
        if(color[v]==0)
        {
            dfs(v);
        }
    }
    color[u]=2;
    return;
}

int aux(int n, int W)
{
    if(n==0||W==0)
        return 0;
    if(W<0)
        return -INF;

    int& ans = dp[n][W];
    if(ans!=-1)
        return ans;

    int takeit = -INF;
    if(W>=actual_w[n])
        takeit  = actual_b[n] + aux(last[n], W-actual_w[n]);
    int leaveit = aux(n-1, W);
    return ans = max(takeit, leaveit); 
}

int main()
{    
    cini3(n,m,W);
    cinv(w,n);
    cinv(b,n);  
    
    FE(i,1,m)
    {
        cini2(x,y);
        gr[x].pb(y);
        gr[y].pb(x);
    }

    vvi con_comp;
    FE(i,1,n)
    {
        comp.clear();
        if(!color[i])
        {
            dfs(i);
            con_comp.pb(comp);
        }
    }

    actual_w.pb(INF);
    actual_b.pb(INF);
    last.pb(INF);

    int x = con_comp.sz, idx = 0;
    FE(i,0,x-1)
    {
        int sumw = 0, sumb = 0;
        int y = con_comp[i].sz;
        FE(j,0,y-1)
        {
            sumw += w[con_comp[i][j]];
            sumb += b[con_comp[i][j]];    
            if(y>1)
            {
                actual_w.pb(w[con_comp[i][j]]);
                actual_b.pb(b[con_comp[i][j]]);
                last.pb(idx);                
            } 
        } 
        actual_w.pb(sumw);
        actual_b.pb(sumb);
        last.pb(idx);
        idx = last.sz - 1;         
        
    }

    debug(actual_w);
    debug(last);
    debug(actual_b);

    memset(dp, -1, sizeof(dp));

    cout<<aux(actual_b.sz-1,W);
    return 0;
}