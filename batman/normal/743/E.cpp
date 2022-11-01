#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1020)
#define K ((ll)8)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,a[N],dp[(1<<K)];
vector <ll> v[K];

bool check(ll x)
{
	ll low=x/8,up=(x+7)/8;
	//cout<<low<<" "<<up<<"\n";
	for(int mask=0;mask<(1<<K);mask++)
	{
		ll num=0;
		for(int i=0;i<K;i++)
			if((mask&(1<<i)))
				num++;
		if(num!=x%8)continue;
		for(int t=1;t<(1<<K);t++)
		{
			dp[t]=INF;
			ll num=-1;
			for(int i=0;i<K;i++)
				if((t&(1<<i)))
					num++;
			ll p=((mask&(1<<num))?up:low);
			for(int i=0;i<K;i++)
				if((t&(1<<i)))
				{
					ll x=dp[t-(1<<i)];
					//if(i==0)cout<<x<<" "<<t-(1<<i)<<"\n";
					ll now=lower_bound(v[i].begin(),v[i].end(),x)-v[i].begin();
					if(p==0)dp[t]=min(dp[t],x);
					else now+=p-1;
					if(now<(ll)v[i].size() && now>=0)
						dp[t]=min(dp[t],v[i][now]+1);
				//	if(i==1)cout<<now<<"\n";
				}
		}
		if(dp[(1<<K)-1]<=n)return 1;
	}
	return 0;
}

int main()
{
   	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],a[i]--,v[a[i]].push_back(i);
    ll l=0,r=n+1;
    while(l<r-1)
    {
    	ll mid=(l+r)/2;
    	if(check(mid))l=mid;
    	else r=mid;
	}
	cout<<l;
    return 0;
}