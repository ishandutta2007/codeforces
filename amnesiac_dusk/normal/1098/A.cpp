/*
 * RD
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long powm(long a, long b, long m);


vector<int> gra[100005];
int sum[100005];
int a[100005];
bool invalid=0;
void dfs(int fr, int at, int par)
{
	if(par&1)
	{
		a[at]=sum[at]-sum[fr];
		for(int i:gra[at])
			sum[i]=sum[at];
	}
	else
	{
		int mis=inf;
		for(int i:gra[at])
			mis=min(sum[i],mis);
		if(mis==inf)
			a[at]=0;
		else if(sum[at]>mis)
			invalid=1;
		else
		{
			sum[at]=mis;
			a[at]=sum[at]-sum[fr];
		}
	}
	for(int i:gra[at])
		dfs(at,i,par^1);
}
void solve()
{
	int n,u;
	cin>>n;
	for(int i=2; i<=n; i++) {
		cin>>u;
		gra[u].pb(i);
	}
	for(int i=1; i<=n; i++)
		cin>>sum[i];
	dfs(0,1,1);
	int sum=0;
	for(int i=1; i<=n; i++)
		sum+=a[i];
	if(invalid)
		cout<<-1<<endl;
	else
		cout<<sum<<endl;
}
signed main()
{
	auto clk=clock();
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC <<endl;
#endif
	return 0;
}
long powm(long a,long b, long m) {
	long te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}