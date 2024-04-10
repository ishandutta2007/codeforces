/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#else
#define deb cout<<"Line: "<<__LINE__<<" plz "
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

const int N=1000005;
int parent[N],val[N],max1[N],max2[N];
void propogate(int i)
{
	if(i==1)
		return;
	int p=parent[i];
	int te=val[p];
	if(max1[p]==i||max2[p]==i)
	{
		if(val[max1[p]]<val[max2[p]])
			swap(max1[p],max2[p]);
	}
	else
	{
		if(val[max1[p]]<val[i])
		{
			max2[p]=max1[p];
			max1[p]=i;
		}
		else if(val[max2[p]]<val[i])
			max2[p]=i;
	}
	if(p!=1)
		val[p]=max(val[max1[p]],val[max2[p]]+1);
	else
		val[p]=max(val[max1[p]],val[max2[p]]);
	if(val[p]!=te)
		propogate(p);
}
void solve()
{
	int n,p;
	cin>>n;
	for(int i=2; i<=n+1; i++)
	{
		cin>>p;
		parent[i]=p;
		val[i]=1;
		propogate(i);
		cout<<val[1]<<" ";
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC <<endl;
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