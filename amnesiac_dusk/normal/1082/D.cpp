//#define opti
#ifdef opti
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
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
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "<<endl
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[501];
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int sum=0;
	for(int i=1; i<=n; i++)
		sum+=a[i];
	if(sum<2*(n-1))
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES ";
		vector<int> leaves,nonleaf;
		for(int i=1; i<=n; i++)
			if(a[i]==1)
				leaves.pb(i);
			else
				nonleaf.pb(i);
		cout<<(n+1-max(2LL,(int)(leaves.size())))<<endl;
		cout<<n-1<<endl;
		for(int i=1; i<nonleaf.size(); i++)
		{
			cout<<nonleaf[i]<<" "<<nonleaf[i-1]<<endl;
			a[nonleaf[i]]--;
			a[nonleaf[i-1]]--;
		}
		vector<int> leaf;
		if(leaves.size()>=2)
		{
			cout<<nonleaf[0]<<" "<<leaves[0]<<endl;
			cout<<nonleaf[((int)nonleaf.size())-1]<<" "<<leaves[1]<<endl;
			a[nonleaf[0]]--;
			a[nonleaf[((int)nonleaf.size())-1]]--;
			for(int i=2; i<leaves.size(); i++)
				leaf.pb(leaves[i]);
		}
		else
			for(int i:leaves)
				leaf.pb(i);
		for(int i:leaf)
			for(int j:nonleaf)
				if(a[j]>0)
				{
					cout<<i<<" "<<j<<endl;
					a[j]--;
					break;
				}
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	clock_t clk = clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	clk = clock() - clk;
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}