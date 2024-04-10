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

const ll MOD=1e9+7;
ll num[1000005],Left[1000005];

ll Pow(ll a,ll n)
{
	ll re=1;
	for(;n;n/=2,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re; 
}

int main()
{jizz
	ll n,last=0,i,J,ans=0;
	cin >> n;
	for(i=0,J=1;i<n;J=J*++i%MOD)
		cin >> num[i];
	sort(num,num+n);
	for(i=1;i<n;i++)
		if(num[i]!=num[i-1]) Left[i]=Left[i-1]+i-last,last=i;
		else Left[i]=Left[i-1];
	for(i=0;num[i]!=num[n-1];i++)
		ans=(ans+J*num[i]%MOD*Pow(n-Left[i],MOD-2))%MOD;
	cout << ans << "\n";
}