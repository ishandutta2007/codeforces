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
#define INF 9e18
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R];
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

// #define int ll

void solve()
{            
    cini(n);
    vi a(n);
    FE(i,0,n-1)
        cin>>a[i];

    map<int, int> mp;
    set<int> comp_set;
    set<int> wrong;

    FE(i,0,n)   
        comp_set.insert(i);

    FE(i,0,n-1)
    {
        if(a[i] != i)
            wrong.insert(i);

        mp[a[i]]++;
        comp_set.erase(a[i]);
    }

    debug(wrong);
    debug(comp_set);
    debug(mp);

    int cur_mex;
    int nsteps = 0; 
    vi ans;
    while(wrong.sz) 
    {
        cur_mex = *comp_set.begin();
        debug(cur_mex);
        if(cur_mex == n)
        {
            int idx = *wrong.begin();      
            mp[a[idx]]--;
            if(mp[a[idx]] == 0)
                comp_set.insert(a[idx]);

            a[idx] = n;       
            comp_set.erase(n);     
            mp[n]++;
            ans.pb(idx);
        }
        else
        {
            mp[a[cur_mex]]--;
            if(mp[a[cur_mex]] == 0)
                comp_set.insert(a[cur_mex]);

            a[cur_mex] = cur_mex;
            ans.pb(cur_mex);
            mp[cur_mex]++;
            comp_set.erase(cur_mex);
            wrong.erase(cur_mex);
        }
        debug(a);
        nsteps++;
    }
    debug(a);
    cout<<nsteps<<"\n";
    FA(x, ans)
        cout<<x+1<<" ";
    cout<<"\n";
    return;
}

signed main()
{
    fastIO;
    int t = 1;
    cin>>t; 

    FE(i, 1, t)
        solve();

    return 0;
}