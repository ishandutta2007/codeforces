#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,m,a[N],ans,mini;
vector <ll> e[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		if(!i)continue;
		ans+=abs(a[i]-a[i-1]);
		if(a[i]==a[i-1])continue;
		e[a[i]].push_back(a[i-1]);
		e[a[i-1]].push_back(a[i]);
	}
	mini=ans;
	for(ll i=1;i<=n;i++)
	{
		if((ll)e[i].size()==0)continue;
		ll dif=0;
		for(int j=0;j<e[i].size();j++)
			dif+=abs(i-e[i][j]);
		ll l=1,r=n;
		while(l<r-2)
		{
			ll m1=(l+r)/2,m2=m1+1,a1=0,a2=0;
			for(int j=0;j<e[i].size();j++)
				a1+=abs(e[i][j]-m1),a2+=abs(e[i][j]-m2);
			if(a1>a2)l=m1;
			else r=m2;
		}
		ll mini2=INF;
		for(int q=l;q<=r;q++)
		{
			ll x=0;
			for(int j=0;j<e[i].size();j++)
				x+=abs(e[i][j]-q);
			mini2=min(mini2,x);
		}
		mini=min(mini,ans-dif+mini2);
	}
	cout<<mini;
	return 0;
}