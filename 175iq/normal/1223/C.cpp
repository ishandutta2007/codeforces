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
#define MOD 998244353 //1000000007  

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
                                                                        
bool f(ll x, ll y, ll len, ll a, ll b, ll k, vll& p, vll& prefix)
{
    ll cxy = 0, cx = 0, cy = 0; 

    if(x<y){
        swap(x,y);
        swap(a,b);
    }

    ll lcmab = (a/__gcd(a,b))*b ; 
    ll ocx, ocy ;

    cxy = len/lcmab ;
    cx  = len/a ;
    ocx = cx - cxy ;
    cy  = len/b ;
    ocy = cy - cxy ;

    ll get = ((prefix[cxy] - prefix[0])/100)*(x+y);    
    get += ((prefix[cxy+ocx] - prefix[cxy])/100)*x;
    get += ((prefix[cxy+ocx+ocy] - prefix[cxy+ocx])/100)*y;  

    if(get>=k){
        return 1;
    }
    
    return 0;   
}

int main()
{   
    fastIO;
    cini(q);
    while(q--)
    {
        cinll(n);        
        cinvll(p,n);             
        sort(1+all(p), [](int a, int b){return a>b;});

        vll prefix(n+1,0);

        FE(i,1,n)
            prefix[i] = prefix[i-1] + p[i];

        ll x ,a;
        cin>>x>>a;

        ll y, b;
        cin>>y>>b;

        cinll(k);

        int left = 0, right = n, ans=-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;

            if( f(x,y,mid,a,b,k,p,prefix) )
            {
                ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        cout<<ans<<endl;
    }

    return 0;
}