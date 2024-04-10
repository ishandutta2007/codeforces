#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)22)

ll n,m,d,a[N],cnt[K],ans=K;
bool mark[(1<<K)];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)
	{
		ll k;cin>>k;
		for(int j=0;j<k;j++)
		{
			ll x;cin>>x;x--;
			a[x]=i;
		}
	}
	for(int i=0,j=0;i<=n-d;i++)
	{
		while(j<i+d){cnt[a[j++]]++;}
		ll res=0;
		for(int p=0;p<m;p++)if(!cnt[p])res+=(1<<p);
		mark[res]=1;
		cnt[a[i]]--;
	}
	for(int i=(1<<m)-1;i>=0;i--)
	{
		ll now=0;
		for(int j=0;j<m;j++)
			if((i&(1<<j)))
			{
				if(mark[i])mark[(i-(1<<j))]=1;
				now++;
			}
		if(!mark[i])ans=min(ans,now);
	}
	cout<<ans;
	return 0;
}