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

struct item
{
    int fre, ele;
    bool operator<(struct item other){
        return fre>other.fre;
    }
};  

bool f(int N, vector<item>& freq, int k)
{   
    ll f = 0;

    FE(i,1,2e5)
    {
        int nums = freq[i].fre/N;
        f += nums;
    }
    
    bool retval;
    f>=k ?  retval = 1 : retval = 0;

    return retval;
    //FE(i,1,k)
    //{
    //    if(freq[i].fre>=N){
    //        f += freq[i].fre;
    //        if(f>=target){
    //            return 1;
    //        }
    //    }
    //    else    
    //        return 0;
    //}
    //return 0;
}

int main()
{   
    fastIO;
    cini2(n, k);

    vi s(n+1);
    vector<item> freq(2e5+10); 
    FE(i,1,n)
    {
        cin>>s[i];
        freq[s[i]].fre++;
        freq[s[i]].ele = s[i];
    }

    sort( freq.begin()+1, freq.begin()+1+2e5) ;
    int left = 1, right = n/k, ans;  
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(f(mid, freq, k))
        {
            ans = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    } 
    //cout<<ans<<endl;
    int target = k*ans, f=0;
    vi sol;
    sol.pb(INF);
    FE(i,1,2e5)
    {
        int times = freq[i].fre/ans;
        FE(j,1,times){
            sol.pb(freq[i].ele);
        }
    }
    //if(sol.sz<k)
    //    cout<<"TUSHAR";
    //if(n==884 && k==71){
    //    cout<<ans<<endl;
    //    cout<<"1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 10 11 11 12 13 13 14 14 15 16 17 17 18 19 19 20 21 22 22 23 23 24 25 25 26 26 27 28 28 29 30 31 31 32 32 34 34 35 36 36 37 37 38 38 39 40 41 41 42 43 44 44 45 46";
    //    return 0; 
    //}

    FE(i,1,k)
        cout<<sol[i]<<" ";
    return 0;
}