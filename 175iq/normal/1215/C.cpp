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
#define INF 2e18
 
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

void solve()
{   
    cini(n);
    cins(s1);
    cins(s2);

    if(n==1)
        if(s1!=s2){
            cout<<-1;
            return;
        }   

    vi zero, one;
    FE(i,1,n)
    {
        if(s1[i] != s2[i])
        {
            if(s1[i] == 'a')
                zero.pb(i);
            else
                one.pb(i);
        }
    }

    vector<pii> ans;
    
    int n0 = zero.sz, I1 = -1;
    for(int i = 0; i < n0; i+=2)
    {
        if(i+1 <= n0-1)
        {
            ans.pb({zero[i], zero[i+1]});
            I1 = i+1;            
        }
    }

    int n1 = one.sz, I2 = -1;
    for(int i = 0; i < n1; i+=2)
    {
        if(i+1 <= n1-1)
        {
            ans.pb({one[i], one[i+1]});    
            I2 = i+1;
        }
    }

    debug(zero, one);
    int yes = 0;
    if(I1 == n0-1 && I2 == n1-1)
        yes = 1;
    else if((I1 == n0-2 && I2 == n1-2) or (n0==1 and n1==1))
        yes = 2;   

    if(yes == 1)
    {
        cout<<ans.sz<<"\n";
        int nx = ans.sz-1; 
        FE(i,0,nx)
            cout<<ans[i].fi<<" "<<ans[i].se<<"\n";
            return ;
    }
    if(yes == 2)
    {
        debug(I1, I2);
        cout<<ans.sz+2<<"\n";
        int nx = ans.sz-1; 
        FE(i,0,nx)
            cout<<ans[i].fi<<" "<<ans[i].se<<"\n";
        cout<<zero[I1+1]<<" "<<zero[I1+1]<<"\n";
        cout<<zero[I1+1]<<" "<<one[I2+1]<<"\n";         
        return;
    }

    cout<<-1;
    return; 
}
 
int main()
{
    fastIO;
    int t = 1;
    // cin>>t;    
    while(t--)
        solve();
    return 0;
}