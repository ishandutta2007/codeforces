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

//
//Input
//The first line of the input contains space-separated two integers  n and m (2n100,1m100),
//denoting the number of the vertices and the number of the edges, respectively.
//
//The next m lines contain space-separated three integers  ai, bi (1ai<bin) and ci (1cim). 
//Note that there can be multiple edges between two vertices. However, there are no multiple edges of the 
//same color between two vertices, that is, if ij, (ai,bi,ci)(aj,bj,cj).
//
//The next line contains a integer  q (1q100), denoting the number of the queries.
//
//Then follows q lines, containing space-separated two integers  ui and vi (1ui,vin). It is guaranteed 
//that uivi.
//
//Output
//For each query, print the answer in a separate line.
//

int N = 110;
vector<vector<pii> > gr(N);
vi visited(N,0);

void dfs(int u, int color, int V, int& mark)
{
	//debug(u,color,V,mark);
	visited[u] = 1;

	if(u==V)
	{
		mark=1;
		return;
	}
		
	int v, colorv;
	FA(pairv, gr[u])
	{
		v = pairv.fi;
		colorv = pairv.se;
		if(!visited[v])
		{
			if(colorv==color)
			{
				dfs(v,color,V,mark);
			}
		}
	}
	return; 
}

int main()
{
    fastIO;
    cini2(n,m);
    F(i,0,m)
    {
    	cini3(a,b,c);
    	gr[a].pb(mp(b,c));
    	gr[b].pb(mp(a,c));
    }
    cini(q);
    int count = 0, mark=0;


    //int mark=0;
    //dfs(1,100,2,mark);
    //debug(mark);
    //debug(visited);
    F(i,0,q)	
    {
    	cini2(u,v);
    	count=0;
    	FE(i,1,100)
    	{
    		mark=0;
    		fill(all(visited),0);
    		dfs(u,i,v,mark);
    		if(mark) 
    			count++; 
    	}
    	cout<<count<<endl;
    }
    return 0; 
}