#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

int n,m,k;
vector <ll> vec;
ll ans,tvn2[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	tvn2[0]=1;
	for(int i=1;i<N;i++)tvn2[i]=tvn2[i-1]*2,tvn2[i]%=MOD;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int v,u;
		cin>>v>>u;
		if(u-v!=1 && u-v!=k+1)return cout<<0,0;
		if(u-v==k+1)vec.push_back(v);
	}
	sort(vec.begin(),vec.end());
	ll ex=n-k-1;
	if(vec.size())ex=vec[0];
	for(int i=ex;i>=1;i--)
	{
		int end=min(i+k,n-k-1);
		if(vec.size() && vec.back()>end)break;
		ans+=tvn2[end-i+1-(int)vec.size()-(!vec.size() || i!=vec[0])];ans%=MOD;
	}
	cout<<(ans+(!vec.size()))%MOD;
	return 0;
}