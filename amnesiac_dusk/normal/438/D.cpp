/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
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
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[100000],sum[400000],maxi[400000];
void build(int ind, int lb, int rb)
{
	if(lb==rb)
	{
		sum[ind]=a[lb];
		maxi[ind]=a[lb];
		return;
	}
	build(2*ind,lb,(lb+rb)/2);
	build(2*ind+1,(lb+rb)/2+1,rb);
	sum[ind]=sum[2*ind]+sum[2*ind+1];
	maxi[ind]=max(maxi[2*ind],maxi[2*ind+1]);
}
int query(int ind,int lb,int rb,int l,int r)
{
	if(l<=lb&&rb<=r)
		return sum[ind];
	if(r<lb||l>rb)
		return 0;
	return query(2*ind,lb,(lb+rb)/2,l, r)+query(2*ind+1,(lb+rb)/2+1,rb,l, r);
}
void modulo(int ind,int lb, int rb,int l, int r, int x)
{
	if(r<lb||l>rb)
		return;
	if(maxi[ind]<x)
		return;
	if(lb==rb)
	{
		sum[ind]%=x;
		maxi[ind]=sum[ind];
		return;
	}
	modulo(2*ind,lb,(lb+rb)/2,l, r, x);
	modulo(2*ind+1,(lb+rb)/2+1,rb,l ,r, x);
	maxi[ind]=max(maxi[2*ind],maxi[2*ind+1]);
	sum[ind]=sum[2*ind]+sum[2*ind+1];
}
void modify(int ind, int lb, int rb,int p, int x)
{
	if(lb>p||rb<p)
		return;
	if(lb==rb)
	{
		sum[ind]=x;
		maxi[ind]=x;
		return;
	}
	modify(2*ind,lb,(lb+rb)/2,p, x);
	modify(2*ind+1,(lb+rb)/2+1,rb,p, x);
	maxi[ind]=max(maxi[2*ind],maxi[2*ind+1]);
	sum[ind]=sum[2*ind]+sum[2*ind+1];
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		int ty;
		cin>>ty;
		if(ty==1)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
		else if(ty==2)
		{
			int l,r,x;
			cin>>l>>r>>x;
			modulo(1,1,n,l,r,x);
		}
		else
		{
			int k,x;
			cin>>k>>x;
			modify(1,1,n,k,x);
		}
	}
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	// cin >> t;
		solve();
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