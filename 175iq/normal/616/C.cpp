#include "bits/stdc++.h"
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define foreach(i,t) for (typeof(t.begin()) i=t.begbin(); i!=t.end(); i++) //traverse an STL data structure
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(c) (c).begin(),(c).end() //handy for function like "sort()" 
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)[Lambda function]
//sort(begin(v), end(v), [] (int a, int b) { return a > b; });
 
//Constants
#define EPS 1e-8
#define INF INT_MAX
#define MOD 1000000007//998244353 
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,0,a.size()-1)
 
//For loops
#define F(i,a,b)    for(int i=a; i<b; i++)
#define FE(i,a,b)   for(int i=a; i<=b; i++)
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
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
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
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n); F(i,0,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n); F(i,0,n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); F(i,0,n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); F(i,0,n) { cin>>a[i]; }

int N = 1000, M = 1000;
vector<vector<char> > field(N+2,vector<char> (M+2));
vviwv(vis,N+2,M+2,0);
vviwv(cc,N+2,M+2,0);
vviwv(ccno,N+2,M+2,0);
set<pii> st;
int cnt;
int n,m;

void dfs(int i, int j)
{
    if(i<1 || i>n || j<1 || j>m)
        return;

    if(field[i][j]=='*')
        return;

    vis[i][j]=1;
    cnt++;
    st.insert(mp(i,j));

    if(!vis[i+1][j])
        dfs(i+1,j);

    if(!vis[i-1][j])
        dfs(i-1,j);

    if(!vis[i][j+1])
        dfs(i,j+1);

    if(!vis[i][j-1])
        dfs(i,j-1);

    return;
}

int main()
{
    fastIO;
    cin>>n>>m;

    FE(i,1,n)
    {
        FE(j,1,m)
            cin>>field[i][j];
    }

    int no=0;
    FE(i,1,n)
    {
        FE(j,1,m)
        {
            if((field[i][j]=='.') && (vis[i][j]==0)){
                cnt=0;
                st.clear();
                dfs(i,j);
                no++;
                FA(ele, st)
                {
                    cc[ele.fi][ele.se] = cnt;
                    ccno[ele.fi][ele.se] = no;
                }
            }
        }
    }

    int ans;
    set<int> st1;
    FE(i,1,n)
    {
        FE(j,1,m)
        {
            if(field[i][j]=='*')
            {
                ans = 1+cc[i-1][j];
                st1.insert(ccno[i-1][j]);

                if(st1.count(ccno[i+1][j])==0){
                    ans+=cc[i+1][j];
                    st1.insert(ccno[i+1][j]);
                }

                if(st1.count(ccno[i][j-1])==0){
                    ans+=cc[i][j-1];
                    st1.insert(ccno[i][j-1]);
                }

                if( st1.count(ccno[i][j+1])==0){
                    ans+=cc[i][j+1];
                    st1.insert(ccno[i][j+1]);
                }
                st1.clear();
                ans%=10;
                cout<<ans;
            }
            else
                cout<<".";
        }
        cout<<endl;
    }

    /*
    FE(i,0,n+1)
    {
        FE(j,0,m+1)
        {
            cout<<cc[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    return 0;
}