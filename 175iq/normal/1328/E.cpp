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

int N = 2e5+10;
vvi gr(N);

int dfs_time=0;

vi color(N,0);
vi tin(N,0);  
vi tout(N,0);
vi parent(N,-1);
vi depth(N,0);

void dfs(int u, int dep)
{
    color[u]=1;
    depth[u]=dep;
    tin[u]=dfs_time++;
    FA(v, gr[u])
    {
        if(color[v]==0)
        {
            parent[v]=u;
            dfs(v,dep+1);
        }
    }
    tout[u]=dfs_time++;
    color[u]=2;
    return;
}

bool checkanc(int parent, int child )
{
    return tin[parent]<tin[child] && tout[parent]>tout[child];
}

int main()
{
    fastIO;
    cini2(n,m);
    F(i,0,n-1)
    {
        cini2(u,v);
        gr[u].pb(v);
        gr[v].pb(u);
    }
    parent[1]=1;
    dfs(1,0);

    F(i,0,m)
    {
        cini(k);
        cinv(vec,k);
        
        F(i,0,k)
        {
            vec[i]=parent[vec[i]];
        }
        int maxd=-INF;
        int maxe;
        debug(vec);
        debug(depth[9]);
        F(i,0,k)
        {
            debug(i,vec[i],depth[i]);
            if(depth[vec[i]]>maxd) 
            {
                maxd=depth[vec[i]];
                maxe=vec[i];
                //debug(maxe,maxd,vec[i],depth[i]);
            }
        }
        debug(maxe,maxd);
        int ans=1;
        F(i,0,k)
        {
            if(vec[i]!=maxe && !checkanc(vec[i],maxe))
            {
                ans = 0;
            }
        }
        ans ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    return 0;
}