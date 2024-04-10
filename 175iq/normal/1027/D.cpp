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

int N = 2e5+10;
vvi gr(N);
vi  color(N,0);
vi  parent(N,-1);

int cycle_start , cycle_end;
int cycle = 0;

void cycle_detection(int u)
{
    debug(u);
    color[u]=1;
    FA(v, gr[u])
    {
        if(color[v]==0)
        {
            parent[v]=u;
            cycle_detection(v);
        }
        else if(color[v]==1)
        {
            //Cycle found if the  graph is directed.
            cycle_start = v; 
            cycle_end = u;
            cycle = 1;

            color[v] = 2;
            for(int v=cycle_end; v!=cycle_start; v=parent[v])
                color[v] = 2;
            
            return ;
        }
    }
    color[u]=2;
    return ;
}

int main()
{
    fastIO;
    cini(n);
    cinv(c,n);
    cinv(a,n);

    FE(i,1,n)
        gr[i].pb(a[i]);

    // debug(gr);

    int ans = 0, mini;
    // cout<<cycle_detection(2)<<"\n";
    FE(i,1,n)
    {
        if(color[i]==0)
        {
            debug(i);
            cycle = 0;
            cycle_detection(i);
            mini = 0;
            if(cycle)
            {
                debug(i, cycle_start);
                mini = c[cycle_start];
                for(int v=cycle_end; v!=cycle_start; v=parent[v])
                {
                    debug(v);
                    color[v] = 2;
                    mini = min(mini, c[v]);
                }
            }
            debug(mini);
            ans += mini;                
        }
    }
    cout<<ans;
    return 0;
}