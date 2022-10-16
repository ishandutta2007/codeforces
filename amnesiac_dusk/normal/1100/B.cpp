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
//12367769,266916112,123798211
ll powm(ll a, ll b, ll m);


int a[100005];
int hola[100005];
vector<int> temp;
void solve()
{
	int n,m,te;
	cin>>m>>n;
	set<int> nums;
	for(int i=1; i<=n; i++)
	{
		cin>>te;
		nums.insert(te);
		hola[te]++;
		if(nums.size()==m)
		{
			cout<<1;
			temp.clear();
			for(int j:nums)
			{
				hola[j]--;
				if(hola[j])
					temp.pb(j);
			}
			nums.clear();
			for(int j:temp)
				nums.insert(j);
		}
		else
			cout<<0;
	}
	cout<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
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