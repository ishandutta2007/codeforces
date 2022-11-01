#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,m,a[N],num[N];

bool check(ll x,bool pp=0)
{
	vector <ll> v;
	memset(num,0,sizeof num);
	ll p=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>m){v.push_back(i);p++;continue;}
		num[a[i]]++;
		if(num[a[i]]>x)v.push_back(i),p++;
	}
	for(int i=1;i<=m;i++)
	{
		if(num[i]>=x)continue;
		p-=x-num[i];
		if(p<0)return 0;
	}
	if(!pp)return 1;
	cout<<x<<" ";
	p=0;
	for(int i=1;i<=m;i++)
	{
		
		if(num[i]>=x)continue;
		while(num[i]<x)
		{
			a[v[p]]=i;
			p++;num[i]++;
		}
	}
	cout<<p<<"\n";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll l=0,r=(ll)1e9;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	check(l,1);
	return 0;
}