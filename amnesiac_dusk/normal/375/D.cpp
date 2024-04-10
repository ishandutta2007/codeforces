//#define opti
#ifdef opti
#define min(x, y) (y ^ ((x ^ y) & -(x < y)))
#define max(x, y) (x ^ ((x ^ y) & -(x < y)))
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif
#ifndef opti
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

struct node
{
	node *left,*right;
	int lb,rb,size;
	node(int le=1,int ri=100000)
	{
		lb=le;
		rb=ri;
		size=0;
		left=NULL;
		right=NULL;
	}
	void add(int i)
	{
		if(lb>i||rb<i)
			return;
		size++;
		if(lb==rb)
			return;
		if(left==NULL)
			left=new node(lb,(lb+rb)/2);
		left->add(i);
		if(right==NULL)
			right=new node((lb+rb)/2+1,rb);
		right->add(i);
	}
	void remove(int i)
	{
		if(lb>i||rb<i)
			return;
		size--;
		if(left!=NULL)
			left->remove(i);
		if(right!=NULL)
			right->remove(i);
	}
	int count(int i)
	{
		if(lb>=i)
			return size;
		if(rb<i)
			return 0;
		int su=0;
		if(left!=NULL)
			su+=left->count(i);
		if(right!=NULL)
			su+=right->count(i);
		return su;
	}
};
int col[100001];
vector<int> gra[100001];
vector<pii> queries[100001];
int anses[100001];
map<int,int> tol[100001];
node temp[100001];
int dfs(int fr, int at)
{
	tol[at][col[at]]=1;
	vector<int> lol;
	temp[at].add(1);
	lol.pb(at);
	int msz=1,lolol,mind=at;
	for(int i:gra[at])
		if(i!=fr)
		{
			lolol=dfs(at,i);
			lol.pb(lolol);
			if(tol[lolol].size()>msz)
			{
				mind=lolol;
				msz=tol[lolol].size();
			}
		}
	for(int i:lol)
		if(i!=mind)
			for(auto j:tol[i])
			{
				int tec=0;
				if(tol[mind].count(j.fi))
				{
					tec=tol[mind][j.fi];
					temp[mind].remove(tec);
				}
				tec+=j.se;
				temp[mind].add(tec);
				tol[mind][j.fi]=tec;
			}
	for(auto i:queries[at])
		anses[i.second]=temp[mind].count(i.fi);
	return mind;
}
void solve()
{
	int n,m,te;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>te;
		col[i]=te;
	}
	for(int i=1,u,v; i<n; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	int vj,kj;
	for(int i=1; i<=m; i++) {
		cin>>vj>>kj;
		queries[vj].pb({kj,i});
	}
	dfs(1,1);
	for(int i=1; i<=m; i++)
		cout<<anses[i]<<endl;
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifdef rd
		clock_t clk = clock();
	#endif
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	#ifdef rd
		clk = clock() - clk;
		cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
	#endif
	return 0;
}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}