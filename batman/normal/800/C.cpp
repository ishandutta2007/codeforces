#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=201*1000;
ll tavan(ll x,ll y,ll mod){ll res=1;while(y){res=(1LL*res*(y%2?x:1))%mod;x=(1LL*x*x)%mod;y/=2;}return res;}

ll n,m,phi[N];
bool block[N];
vector <ll> v,num[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		block[x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		phi[i]+=i;
		for(int j=2*i;j<=m;j+=i)phi[j]-=phi[i];
	}
	for(ll i=1;i<=m;i++)
		if(m%i==0)
		{
			v.push_back(i);
			for(ll j=i;j<=m;j+=i)
				if(__gcd(j/i,m/i)==1 && !block[j])
				{
					if(j!=m)num[(ll)v.size()-1].push_back(j);
					else if(!block[0])num[(ll)v.size()-1].push_back(0);
				}
					
		}
	for(ll i=1;i<v.size();i++)
	{
		ll maxi=0;
		for(ll j=0;j<i;j++)
			if(v[i]%v[j]==0 && (ll)num[j].size()>(ll)num[maxi].size())
				maxi=j;
		for(auto u:num[maxi])num[i].push_back(u);
	}
	vector <ll> res;res=num[(ll)v.size()-1];
	reverse(res.begin(),res.end());
	vector <ll> ans;ans.push_back(res[0]);
	for(ll i=1;i<res.size();i++)
	{
		ll x=res[i-1],y=res[i],mod=m,g=__gcd(x,mod);
		mod/=g;x/=g;y/=g;
	//	cout<<x<<" "<<y<<" "<<mod<<"\n";
	//	cout<<res[i-1]<<" "<<res[i]<<" "<<(y*tavan(x,phi[mod]-1,mod))%mod<<"\n";
		ans.push_back((y*tavan(x,phi[mod]-1,mod))%mod);
	}
	cout<<ans.size()<<"\n";
	for(auto u:ans)cout<<u<<" ";
	return 0;
}