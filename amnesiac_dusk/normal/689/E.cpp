/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
//#define endl '\n'
#endif
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define int long long
#define fr(a,b,c) for(int a=b; a<=c; a++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[200001],fact[200001],invfact[200001];
signed main()
{
	IO;
	int n,k;
	cin>>n>>k;
	vector<int> ls,rs;
	for(int i=0; i<n; i++)
	{
		int l,r;
		cin>>l>>r;
		ls.pb(l);
		rs.pb(r);
	}
	sort(ls.begin(),ls.end());
	sort(rs.begin(),rs.end());
	int last=ls[0];
	for(int i=0,j=0; i<n||j<n;)
	{
		int cur;
		if(i!=n)
			cur=min(ls[i],rs[j]);
		else
			cur=rs[j];
		a[i-j]+=cur-last;
		last=cur;
		while(i!=n&&cur==ls[i])
			i++;
		a[i-j]+=(cur-last+1);
		last=cur+1;
		while(j!=n&&cur==rs[j])
			j++;
	}
	fact[0]=1;
	for(int i=1; i<=200000; i++)
		fact[i]=(fact[i-1]*i)%mod;
	invfact[200000]=powm(fact[200000],mod-2,mod);
	for(int i=199999; i>=0; i--)
		invfact[i]=(invfact[i+1]*(i+1))%mod;
	int ans=0;
	for(int i=k; i<=n; i++)
		ans=(ans+a[i]*(((fact[i])*((invfact[k]*invfact[i-k])%mod))%mod))%mod;
	cout<<ans<<endl;
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