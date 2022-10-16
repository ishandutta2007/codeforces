#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,ans=1,x[50];
int main()
{
	cin>>n>>m;
	n+=m;
	x[0]=2;
	for(int i=1;i<=40;i++)
		x[i]=(x[i-1]*x[i-1])%mod;
	for(int i=0;i<20;i++)
		if((n>>i)&1)
			ans=(ans*x[i])%mod;
	cout<<ans;
	return 0;
}