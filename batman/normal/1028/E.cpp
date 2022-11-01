#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)
#define MOD ((ll)1e9+7)

ll n,b[N],a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	bool flg=1;
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
		if(b[i]!=b[0])flg=0;
	}
	if(flg)
	{
		if(b[0])return cout<<"NO\n",0;
		cout<<"YES\n";
		for(ll i=0;i<n;i++)cout<<2<<" ";
		cout<<"\n";
		return 0;
	}
	ll id=-1;
	for(ll i=0;i<n;i++)
	{
		ll pre=(i-1+n)%n;
		if(b[pre]<b[i])
		{
			id=i;
			break;
		}
	}
	if(id==-1)
	{
		while(1)cout<<1/0;
	}
	a[id]=b[id];
	for(ll i=id-1;;i--)
	{
		if(i==-1)i=n-1;
		if(i==id)break;
		ll pre=(i-1+n)%n;
		ll nex=(i+1)%n;
		ll mini=max(b[pre]+1,b[i]);
		mini-=b[i];
		mini=(mini+a[nex]-1)/a[nex];mini*=a[nex];
		mini+=b[i];
		a[i]=mini;
	}
	cout<<"YES\n";
	for(ll i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}