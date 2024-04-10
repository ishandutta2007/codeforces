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

int n,a[100001],fact[100002],invfact[100002];
vector<pii> hola;
int ncr(int n, int k)
{
	if(n<0||k<0||n<k)
		return 0;
	return (((fact[n]*invfact[k])%mod)*invfact[n-k])%mod;
}
int solve(int l, int r, int i)
{
//	cout<<l<<" "<<r<<" "<<i<<" "<<hola[i].fi<<" "<<hola[i].se<<endl;
	if(l<0||r>n)
		return 0;
//	deb<<endl;
	if(i==(int)hola.size())
		return ncr(n+l-r-1,n-r);
//	deb<<endl;
	if(hola[i].fi>=l&&hola[i].fi<=r)
		return 0;
	if(hola[i].fi<l)
	{
		int lol=ncr(hola[i].se-hola[i-1].se-1,l-hola[i].fi-1);
//		cout<<lol<<endl;
		if(!lol)
			return 0;
		return (lol*solve(hola[i].fi,hola[i].fi+hola[i].se-1,i+1))%mod;
	}
	else
	{
		int lol=ncr(hola[i].se-hola[i-1].se-1,hola[i].fi-r-1);
		if(!lol)
			return 0;
//		cout<<lol<<endl;
		return (lol*solve(hola[i].fi-hola[i].se+1,hola[i].fi,i+1))%mod;
	}
}
void solve()
{
	int te;
	cin>>n;
	fact[0]=1;
	for(int i=1; i<=n; i++)
		fact[i]=(fact[i-1]*i)%mod;
	invfact[n]=powm(fact[n],mod-2,mod);
	for(int i=n-1; i>=0; i--)
		invfact[i]=(invfact[i+1]*(i+1))%mod;
	for(int i=1; i<=n; i++)
	{
		cin>>te;
		a[te]=i;
	}
	hola.pb({0,0});
	for(int i=1; i<=n; i++)
		if(a[i])
		{
//			cout<<a[i]<<" "<<i<<endl;
			hola.pb({a[i],i});
		}
	if(hola.size()==1)
		cout<<powm(2,n-1,mod);
	else if(hola[1].se!=1)
		cout<<(powm(2,hola[1].se-2,mod)*(solve(hola[1].fi-hola[1].se+1,hola[1].fi,2)+solve(hola[1].fi,hola[1].fi+hola[1].se-1,2)))%mod<<endl;
	else
		cout<<solve(hola[1].fi,hola[1].fi,2)<<endl;
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