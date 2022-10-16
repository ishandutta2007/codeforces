#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define mpitr map<int,int>::iterator
#include <bits/stdc++.h>
using namespace std;
const ll mod=1000000007;
ll powm(ll b,ll e,ll m);
ll a[100001];
ll anses[17];
set<ll> seg[17];
int main()
{
	IO
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(ll i=0; i<17; i++)
		for(ll k=0,j=0; j<=n+1; j++)
			if(!((a[j]>>i)&1))
			{
				anses[i]+=(((j-k)*(j-k+1LL))>>1LL);
				seg[i].insert(j);
				k=j+1;
			}
	int p,v;
	set<ll>::iterator temp,temp1;
	while(m-->0)
	{
		cin>>p>>v;
		ll ans=0;
		for(ll i=0; i<17; i++)
		{
			if((((v>>i)^(a[p]>>i))&1))
			{
				if(((v>>i)&1))
				{
					seg[i].erase(p);
					temp=seg[i].upper_bound(p);
					temp1=seg[i].upper_bound(p);
					temp1--;
					ll te=*(temp),te1=*(temp1);
					anses[i]-=((te-p)*(te-p-1LL))>>1LL;
					anses[i]-=((p-te1)*(p-te1-1LL))>>1LL;
					anses[i]+=((te-te1)*(te-te1-1LL))>>1LL;
				}
				else
				{
					temp=seg[i].upper_bound(p);
					temp1=seg[i].upper_bound(p);
					temp1--;
					ll te=*(temp),te1=*(temp1);
					seg[i].insert(p);
					anses[i]-=(((te-te1)*(te-te1-1LL)))>>1LL;
					anses[i]+=(((te-p)*(te-p-1LL)))>>1LL;
					anses[i]+=(((p-te1)*(p-te1-1LL)))>>1LL;
				}
			}
			ans+=(anses[i]<<i);
		}
		a[p]=v;
		cout<<ans<<"\n";
	}
}
ll powm(ll b,ll e,ll m)
{
	ll a=1;
	while(e)
	{
		if(e&1)
			a=(a*b)%m;
		b=(b*b)%m;
		e>>=1;
	}
	return a;
}