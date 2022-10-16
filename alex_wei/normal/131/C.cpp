#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t,ans,sum;
ll c(ll x,ll y)
{
	ll mut=1;
	for(ll i=1;i<=y;i++)
		mut=mut*(x-y+i)/i;
	return mut;
}
int main()
{
	cin>>n>>m>>t;
	for(ll i=0;i<=t;i++){
		ll x=i,y=t-i;
		if(x<=n&&x>=4&&y&&y<=m)
			sum+=c(n,x)*c(m,y);
	}
	cout<<sum;
	return 0;
}