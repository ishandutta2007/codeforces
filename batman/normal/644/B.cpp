#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e15)

ll n,b,now,ans[N],t[N],d[N];
queue <ll> q;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		if(!t[i])cin>>t[i]>>d[i];
		if(t[i]<now)
		{
			if((ll)q.size()==b)ans[i]=-1;
			else q.push(i);
			continue;
		}
		if(q.size()==0)now=t[i]+d[i],ans[i]=t[i]+d[i];
		else
		{
			ll id=q.front();
			now+=d[id];
			ans[id]=now;
			q.pop();
			i--;
		}
	}
	while(q.size())
	{
		ll id=q.front();
		now+=d[id];
		ans[id]=now;
		q.pop();
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}