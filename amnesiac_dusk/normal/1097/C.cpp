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

int po[500001],ne[500001];
void solve()
{
	int n;
	cin>>n;
	int zero=0;
	for(int i=0; i<n; i++)
	{
		string s;
		cin>>s;
		int val=0;
		int pos=1;
		for(int j=0; j<s.length(); j++)
		{
			if(s[j]=='(')
				val++;
			else
				val--;
			if(val<0)
				pos=0;
		}
		if(pos==1&&val>0)
			po[val]++;
		int neg=1;
		val=0;
		for(int j=((int)s.length())-1; j>=0; j--)
		{
			if(s[j]==')')
				val++;
			else
				val--;
			if(val<0)
				neg=0;
		}
		if(neg==1&&val>0)
			ne[val]++;
		if(pos==1&&neg==1)
			zero++;
	}
	int ans=zero/2;
	for(int i=1; i<=500000; i++)
		ans+=min(po[i],ne[i]);
	cout<<ans<<endl;
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