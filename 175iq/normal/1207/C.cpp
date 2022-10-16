#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define clr(arr) memset((arr), 0, sizeof(arr))
#define setval(arr,value) memset(arr,value,sizeof(arr)) //set elements of array to some value
#define foreach(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) //traverse an STL data structure
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)[Lambda function]

//Constants
#define EPS 1e-8
#define PI 2*acos(0.0)
#define INF 0x3f3f3f3f
#define MOD 1000000007
 
//Printing
#define coutA(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutA(a,0,a.size()-1)
 
//Checking bound
#define IN(i,l,r)   (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r)  (l<=i&&i<r)
#define INR(i,l,r)  (l<i&&i<=r)
 
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
#define viwv(vecname, N, value) vector<int> vecname(N, value) 
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP 
#define vvig(vecname, N) vector<vector<int> > vecname(N) //For Graph 
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
//
//Input
//The fist line contains one integer T (1T100)  the number of queries. Next 2T lines contain 
//independent queries  one query per two lines.
//
//The first line contains three integers n, a, b (2n2105, 1a108, 1b108)  the length of the road, 
//the cost of one unit of the pipeline and the cost of one unit of the pillar, respectively.
//
//The second line contains binary string s (|s|=n, si{0,1}, s1=sn=0)  the description of the road.
//
//Its guaranteed that the total length of all strings s doesnt exceed 2105.
//

int main()
{   
    fastIO;
    cini(T);
    while(T--)
    {
        cinll(n);
        cinll(a);
        cinll(b);
        cins(s);
        viwv(road,n+1,1);
        road[0]=1;
        road[n]=1;
        ll cost= (n)*((ll)a);

        std::vector<std::vector<ll> > dp(n,std::vector<ll> (2,0));

        ll inf = (ll)1e17;

        dp[0][0]=b;
        dp[0][1]=inf;

        F(i,0,n+1)
        {
            if(s[i]=='1')
            {
                road[i]=2,road[i+1]=2;
            }
        }
        FE(i,1,n-1)
        {
            if(road[i]==1)
            {
                dp[i][0] = b + min(dp[i-1][0] + a , dp[i-1][1] + 2*a);
                dp[i][1] = 2*b + min(dp[i-1][0] + 2*a , dp[i-1][1] + a);
            }
            else if(road[i]==2)
            {
                dp[i][0] = inf;
                dp[i][1] = 2*b + min(dp[i-1][0] + 2*a , dp[i-1][1] + a);
            }
        }
        ll x = b + min(dp[n-1][0]+a,dp[n-1][1]+2*a); 
        cout<<x<<endl;
    }   
    return 0;
}