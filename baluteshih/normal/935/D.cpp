#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define ET cout << "\n";

ll a[100005],b[100005];
const ll MOD=1e9+7;

ll pow(ll a,ll n)
{
	ll re=1;
	for(;n;n/=2,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re; 
}

int main()
{jizz
	ll n,m,p=1,i,ans=0,mo;
	cin >> n >> m,mo=pow(m,MOD-2);
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<n;i++)
		cin >> b[i];
	for(i=0;i<n;i++)
	{
		if(a[i] && b[i] && a[i]!=b[i]) break;
		if(!a[i] && !b[i])
			ans+=m*(m-1)/2%MOD*mo%MOD*mo%MOD*p%MOD;
		else if(!a[i])
			ans+=(m-b[i])*mo%MOD*p%MOD;
		else if(!b[i])
			ans+=(a[i]-1)*mo%MOD*p%MOD;
		ans%=MOD;
		if(!a[i] || !b[i]) p=p*mo%MOD;
	} 
	if(i<n && a[i]>b[i]) ans+=p,ans%=MOD;
	cout << ans << "\n";
}