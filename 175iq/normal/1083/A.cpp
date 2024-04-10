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
#define INF 2e9
 
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

void solve()
{
    cini(n);
    cinvll(w, n);

    vvpi gr(n+1);
    FE(i,1,n-1)
    {
        cini3(u, v, c);
        gr[u].pb({c, v});
        gr[v].pb({c, u});        
    }

    vll in(n+1,0);
    function<ll(int, int)> dfs = [&](int u, int parent)
    {
        in[u] = w[u];
        ll maxi = 0;
        
        FA(curp, gr[u])
        {   
            int v = curp.se;
            ll edgewt = curp.fi;
            
            if(v == parent)
                continue;

            ll fromgoingdown = dfs(v, u);
            maxi = max(maxi, fromgoingdown - edgewt);
        }

        debug(u, in[u], maxi);
        in[u] += maxi;

        return in[u];
    };

    dfs(1, -1);

    debug(in);

    vll out(n+1, 0);
    FE(i,1,n)
        out[i] = w[i];

    debug(out);
    function<void(int, int)> dfs2 = [&](int u, int parent)
    {
        ll mx1 = -INF, mx2 = -INF;
        FA(curp, gr[u])
        {
            int v = curp.se;
            ll edgewt = curp.fi;
            
            if(v == parent)
                continue;

            if(in[v] - edgewt >= mx1)
            {
                mx2 = mx1;
                mx1 = in[v] - edgewt;
            }
            else if(in[v] - edgewt > mx2)
            {
                mx2 = in[v] - edgewt;
            }

            // if(in[v] >= mx1)  //Equal to sign here is very imp.
            // {
            //     mx2 = mx1;
            //     mx1 = in[v];
            // }
            // else if(in[v] > mx2) 
            // {
            //     mx2 = in[v];
            // }

            debug(u, v, mx1, mx2);
        }

        FA(curp, gr[u])
        {
            int v = curp.se;
            ll edgewt = curp.fi;
            
            if(v == parent)
                continue;
                
            ll maxileavcur = mx1;
            if(mx1 == in[v] - edgewt)
                maxileavcur = mx2;

            debug(v, mx1, mx2, maxileavcur);
            // out[v] += max(0ll, -edgewt + max(out[u], maxileavcur));
            if(-edgewt + w[u] + maxileavcur >= -edgewt + out[u])
            {
                debug(v, out[v], u, -edgewt + w[u] + maxileavcur);
                out[v] += max(0ll, -edgewt + w[u] + maxileavcur);
                debug(out[v]);
            } 
            else
            {
                debug(v, out[v], u, -edgewt + out[u]);
                out[v] += max(0ll, -edgewt + out[u]);
                debug(out[v]);                
            }

            dfs2(v, u);
        }                
        return;
    };

    dfs2(1, -1);
    debug(out);
    ll ans = 0;
    FE(i,1,n)
        ans = max(ans, in[i] + out[i] - w[i]);

    cout<<ans;
    return; 
}

signed main()
{
    fastIO;
    int t = 1;
    // cin>>t;    
    while(t--)
        solve();
    return 0;
}