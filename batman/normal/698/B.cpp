#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)301*1000);
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);

ll n,num;
ll root;
bool virt=1;
ll ans[N],par[N];
vector <ll> roots,oskol;

ll Par(ll x){if(par[x]==-1)return x;return par[x]=Par(par[x]);}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)par[i]=-1;
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		if(x==i)
		{
			roots.push_back(x);
		}
		else if(Par(x)==i)
		{
			oskol.push_back(i);
		}
		else ans[i]=x,par[i]=x;
	}
	if((ll)roots.size()==0)
	{
		if((ll)oskol.size()==0)
		{
			cout<<0<<"\n";
			for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
			return 0;
		}
		ans[oskol[0]]=oskol[0];
		for(int i=1;i<oskol.size();i++)ans[oskol[i]]=oskol[0];
		cout<<(ll)oskol.size()<<"\n";
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
		return 0;
	}
	else
	{
		ans[roots[0]]=roots[0];
		for(int i=1;i<roots.size();i++)ans[roots[i]]=roots[0];
		for(int i=0;i<oskol.size();i++)ans[oskol[i]]=roots[0];
		cout<<(ll)roots.size()+(ll)oskol.size()-1<<"\n";
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	}
	
	return 0;
}