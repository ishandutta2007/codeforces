#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)110)
#define MOD ((ll)1e9+7)

ll n,k,a[N],m[N][N],res[N][N];

ll cnt(ll x)
{
	ll res=0;
	while(x)res+=(x%2),x/=2;
	return res;
}

void tavan(ll x)
{
	for(ll i=0;i<n;i++)res[i][i]=1;
	while(x)
	{
		if(x%2)
		{
			ll ex[N][N]={};
			for(ll i=0;i<n;i++)
				for(ll j=0;j<n;j++)
					for(ll q=0;q<n;q++)
						ex[i][j]+=res[i][q]*m[q][j],ex[i][j]%=MOD;
			for(ll i=0;i<n;i++)
				for(ll j=0;j<n;j++)
					res[i][j]=ex[i][j];
		}
		ll ex[N][N]={};
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
				for(ll q=0;q<n;q++)
					ex[i][j]+=m[i][q]*m[q][j],ex[i][j]%=MOD;
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
				m[i][j]=ex[i][j];
		x/=2;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			m[i][j]=(cnt((a[i]^a[j]))%3==0);
	tavan(k-1);
	ll ans=0;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			ans+=res[i][j],ans%=MOD;
	cout<<ans;
	return 0;
}