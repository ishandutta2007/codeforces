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
#define INF (ll)2e9
 
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

#define int ll

void solve()
{
    cini(n);
    ll l, r;
    cin>>l>>r;

    vll vec(n);

    FE(i,1,n-1)
    {
        vec[i] = 2*(n-i);
        vec[i] += vec[i-1];
    }

    auto itl = lower_bound(1+all(vec), l);
    if(itl == vec.end())
    {
        cout<<1<<"\n";
        return;
    }
    int idxl = itl-vec.begin();

    auto itr = lower_bound(1+all(vec), r);
    int add1atlast = 0, idxr;
    if(itr == vec.end())
    {   
        idxr = n-1;    
        add1atlast = 1;
    }
    else
        idxr = itr-vec.begin();

    debug(idxl, idxr);
    vi vecans;
    vecans.pb(INF);

    FE(block, idxl, idxr)
    {
        int start = block;
        int sec = block+1;
        bool fi = 1;
        FE(i,1,2*(n-block))
        {
            if(fi)
                vecans.pb(start);
            else
            {
                vecans.pb(sec);
                sec++;
            }
            fi = 1-fi;
        }        
    }
    debug(vecans);
    if(add1atlast){
        r--;
    }
    ll covered = vec[idxl-1];
    debug(covered);
    FE(i,covered+1,r)
    {
        debug(i-covered, l, r);
        if(i>=l and i<=r)
            cout<<vecans[i-covered]<<" ";
    }

    if(add1atlast)
        cout<<1<<"\n";

    return;
}

signed main()
{
    fastIO;
    int t = 1;
    cin>>t;    
    while(t--)
        solve();
    return 0;
}