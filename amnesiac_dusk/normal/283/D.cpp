/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
//typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[5001];
vector<int> sad[2][5001];
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sad[0][0].pb(1);
	for(int i=n; i>0; i--)
	{
		bool lol=1;
		for(int j=0; j<=5000&&lol; j++)
			for(auto te:sad[0][j])
			{
				if((te&1))
				{
					if(a[i]%te==0)
					{
						sad[1][j].pb(a[i]);
						lol=0;
						break;
					}
				}
				else
					if(a[i]%(te>>1)==0&&((a[i]/(te>>1))&1))
					{
						sad[1][j].pb(a[i]);
						lol=0;
						break;
					}
			}
		for(int j=0; j<5000; j++) {
			for(auto te:sad[0][j])
				if(te&1)
					sad[1][j+1].pb(te);
				else
					sad[1][j+1].pb(te>>1);
		}
		swap(sad[0],sad[1]);
		for(int j=0; j<=5000; j++) {
			sad[1][j].clear();
		}
	}
	for(int i=0; i<=5000; i++)
		if(sad[0][i].size()) {
			cout<<i<<endl;
			return;
		}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	clk=clock()-clk;
	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
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