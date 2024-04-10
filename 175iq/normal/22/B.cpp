#include "bits/stdc++.h"
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
#define F(i,a,b)   for(int i=a; i<b; i++)
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
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }

int maxperi(vi& rone)
{
    int ans = 0;
    int n = rone.sz;

    vi leftsmall(n), rightsmall(n);
    leftsmall[0] = -1;
    rightsmall[n-1] = n;

    FE(i,1,n-1)
    {
        int ptr = i-1;
        while(ptr>=0 && rone[ptr]>=rone[i])
            ptr = leftsmall[ptr];

        leftsmall[i] = ptr; 
    }

    FRE(i,n-2,0)
    {
        int ptr = i+1;
        while((ptr<=n-1) && rone[ptr]>=rone[i])
            ptr = rightsmall[ptr];

        rightsmall[i] = ptr;
    }

    FE(i,0,n-1)
        ans = max(ans, 2*(rone[i] + rightsmall[i]-leftsmall[i]-1));

    return ans;
}

int main()
{   
    fastIO; 
    cini2(n,m); 
    
    vviwv(mat,n+2,m+2,0); 
  
    FE(i,1,n)
    {
        cins(s);
        F(j,0,m)
            mat[i][j+1] = !(s[j] - '0');
    }
 
    vviwv(rone,n+2,m+2,0);
 
    FE(i,1,n)
        FRE(j,m,1)
        {
            if(mat[i][j]==0)
                rone[i][j] = 0;
            else
                rone[i][j] = rone[i][j+1] + 1;
        }
     
    vi vec;
    int ans = 0, mini, start, mark = 1;
    FE(j,1,m)
    {
        mark = 1;
        mini = INF;
        for (int i = 1; i <= n; i++)
        {
            if(rone[i][j]>0)
            {
                if(mark)    
                {
                    debug(i,j);
                    mark = 0;
                    vec.clear();
                }
                vec.pb(rone[i][j]);
                if(i==n){
                    ans = max(ans, maxperi(vec)) ;
                    vec.clear();
                }
            }
            else
            {
                mark = 1;
                if(vec.sz){
                    debug("lower",i,j,vec);
                    ans = max(ans, maxperi(vec));
                }
            }
        }
    }

    cout<<ans;
 
    return 0;
}