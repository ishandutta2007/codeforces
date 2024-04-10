#include "bits/stdc++.h"
using namespace std;

//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define foreach(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) //traverse an STL data structure
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)[Lambda function]
//sort(begin(v), end(v), [] (int a, int b) { return a > b; });

//Constants
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define MOD 998244353
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,0,a.size()-1)

//For loops
#define F(i,a,b)    for(int i=a; i<b; i++)
#define FE(i,a,b)   for(int i=a; i<=b; i++)
#define FR(i,b,a)   for(int i=b; i>a; i--)
#define FRE(i,b,a)  for(int i=b; i>=a; i--)
#define FA(n,container)   for(auto n : container)

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
#define vb vector<bool> 
#define vvi vector<vector<int> > 
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP 
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Directions
const int fx[4][2]  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n); F(i,0,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n); F(i,0,n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); F(i,0,n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); F(i,0,n) { cin>>a[i]; }

vviwv(dp, 110, 3, -1);
vi a(110);

//
//Input
//The first line contains a positive integer n (1n100)  the number of days of Vasyas vacations.
//
//The second line contains the sequence of integers a1,a2,...,an (0ai3) separated by space, where:
//
//ai equals 0, if on the i-th day of vacations the gym is closed and the contest is not carried out;
//ai equals 1, if on the i-th day of vacations the gym is closed, but the contest is carried out;
//ai equals 2, if on the i-th day of vacations the gym is open and the contest is not carried out;
//ai equals 3, if on the i-th day of vacations the gym is open and the contest is carried out.
//

int calc(int i, int prevact, int n)
{
    if(i==n)
    {
        if(a[i]==0)
        {
            return 1;
        }
        else if(a[i]==1)
        {
            if(prevact==0)
                return 0;
            else if(prevact==1)
                return 0;
            else if(prevact==2)
                return 1;
        }
        else if(a[i]==2)
        {
            if(prevact==0)
                return 0; 
            else if(prevact==1)
                return 1;
            else if(prevact==2)
                return 0;
        }
        else if(a[i]==3)
        {
            if(prevact==0)
                return 0;
            else if(prevact==1)
                return 0;
            else if(prevact==2)
                return 0;
        }
    }
    int& ans = dp[i][prevact];
    if(ans!=-1) 
        return ans;
    if(a[i]==0)
    {
        return ans = 1+calc(i+1,0,n);
    }
    else if(a[i]==1)
    {
        if(prevact==0)
            return ans = min(1+calc(i+1,0,n),calc(i+1,2,n));
        else if(prevact==1)
            return ans = min(1+calc(i+1,0,n),calc(i+1,2,n));
        else if(prevact==2)
            return ans = 1+calc(i+1,0,n);
    }
    else if(a[i]==2)
    {
        debug(i,prevact);
        if(prevact==0)
            return ans = min(1+calc(i+1,0,n),calc(i+1,1,n));  
        else if(prevact==1)
            return ans = 1+calc(i+1,0,n);
        else if(prevact==2)
            return ans = min(1+calc(i+1,0,n),calc(i+1,1,n));
    }
    else if(a[i]==3)
    {
        if(prevact==0)
            return ans = min({1+calc(i+1,0,n),calc(i+1,1,n),calc(i+1,2,n)});
        else if(prevact==1)
            return ans = min(1+calc(i+1,0,n),calc(i+1,2,n));
        else if(prevact==2)
            return ans = min(1+calc(i+1,0,n),calc(i+1,1,n));
    }
}

int main()
{
    fastIO;
    cini(n); 
    FE(i,1,n)
    {
        cin>>a[i];
    }

    cout<<calc(1,0,n);

    return 0;
}