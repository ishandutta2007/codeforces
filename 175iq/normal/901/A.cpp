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

//
//Input
//The first line contains single integer n (3n2105)  the number of squares in the park.
//
//Each of the next (n-1) lines contains two integers x and y (1x,yn)  the indices of two
//squares directly connected by a path.
//
//It is guaranteed that any square is reachable from any other using the paths.
//
//Output
//In the first line print single integer k  the minimum number of colors Andryusha has to use.
//
//In the second line print n integers, the i-th of them should be equal to the balloon color on the i-th 
//square. Each of these numbers should be within range from 1 to k.
//

//int N = 2e5+10;
//vvi gr(N);
//vi deg(N,0);
//int cnt=1;
//vi color(N,0);
//vi parent(N,-1);
//
//void dfs(int u)
//{
//	FA(v, gr[u])
//	{
//		if(v==parent[u])
//			continue;
//		int pcolor = color[parent[u]];
//		int gcolor = color[parent[parent[u]]];
//		int mini   = min(pcolor, gcolor);	
//		if(pcolor!=1)
//			color[v] = 1;
//		else if(gcolor!=2)
//			color[v] = 2;
//		else
//			color[v] = 3;		
//		dfs(v);
//	}
//	return;
//}
//
//int main()
//{
//    fastIO;
//    cini(n);
//    F(i,0,n-1)
//    {
//    	cini2(u,v);
//    	gr[u].pb(v);
//    	gr[v].pb(u);
//    	deg[u]++;
//    	deg[v]++;
//    }
//
//    int k = *max_element(all(deg)) + 1;
//    cout<<k<< endl;
//    color[1]=cnt++;
//    parent[1] = -1;
//
//    FA(v, gr[1])
//    {
//    	color[v] = cnt++ ;
//    	parent[v] = 1; 
//    }
//    
//    FA(v, gr[1])
//    {
//    	FA(z, gr[v])
//    	{
//    		parent[z] = v;
//    		dfs(z);
//    	}
//    }
//    
//    return 0; 
//} 
// 
//    	

int N = 2e5+10;
vi par1(N,0);
vi par2(N,0);

int main()
{
	cini(h);
	cinv(a,h+1);
	int n = accumulate(all(a),0);
	
	int mark1=0,cut;
	FE(i,0,h-1)
	{
		if(a[i]>1 && a[i+1]>1)
		{
			cut=i;
			mark1=1;
		}
	}
	if(!mark1)
	{
		cout<<"perfect";
		return 0;		
	}	

	cout<<"ambiguous"<<endl;
	par1[1] = 0;
	int till = 1;
	int lefti = 1;
	FE(i,1,h)
	{
		int x = a[i];
		debug(i,x,till,lefti);
		FE(j,till+1, till+x)
		{
			par1[j] = lefti;; 
		}
		lefti = till+1;
		till = till+x; 
		debug(lefti, till);
	}

	par2[1] = 0;
	till = 1;
	lefti = 1;
	F(i,1,h+1)
	{
		int x = a[i];
		debug(i,x);

		if(i==cut+1)
		{
			FE(j,till+1, till+x-1)
			{
				par2[j] = lefti; 
			}
			par2[till+x] = lefti+1;
			lefti = till+1;
			till = till+x; 
			debug(lefti, till);
			continue;
		}
	
		FE(j,till+1, till+x)
		{
			par2[j] = lefti; 
		}
		lefti = till+1;
		till = till+x; 
		debug(lefti, till);
	}

	coutRV(par1,1,n);
	coutRV(par2,1,n);
}