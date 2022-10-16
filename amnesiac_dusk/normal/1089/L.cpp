//#define opti
#ifdef opti
//#pragma GCC optimize("Ofast,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3,unroll-loops")
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
const ll inf=5e9;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[100001],b[100001];
int done[100001];
void solve()
{
	int n,k;
	cin>>n>>k;
	priority_queue<int> hol;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		cin>>b[i];
	for(int i=1; i<=n; i++)
	{
		if(done[a[i]]<b[i])
		{
			if(done[a[i]])
				hol.push(-done[a[i]]);
			done[a[i]]=b[i];
		}
		else
			hol.push(-b[i]);
	}
	int notdone=0;
	for(int i=1; i<=k; i++)
		if(!done[i])
			notdone++;
	int ans=0;
	while(notdone)
	{
		ans-=hol.top();
		hol.pop();
		notdone--;
	}
	cout<<ans<<endl;

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