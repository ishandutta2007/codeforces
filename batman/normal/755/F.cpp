#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)
#define K ((ll)20)

ll n,k,a[N],maxi,mini;
vector <ll> v;
ll jaghool;
bitset <N> dp,mark;

int main()
{
	scanf("%d%d",&n,&k);
	ll k2=k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			ll x=a[i],p=1;
			while(x!=i)p++,mark[x]=1,x=a[x];
			v.push_back(p);
			maxi+=min(k2,p/2)*2,k2-=min(k2,p/2);
			if(p%2)jaghool++;
		}
	maxi+=min(k2,jaghool);
	dp[0]=1;
	sort(v.begin(),v.end());
	v.push_back(-1);
	vector <ll> v2;
	for(int i=0,cnt=1;i<v.size();i++)
	{
		if(v[i]!=v[i+1])
		{
			ll x=v[i];
			while(cnt)
			{
				dp|=(dp<<v[i]);
				for(int j=0;j<K;j++)
				{
					if((1<<j)<=cnt && cnt<(1<<(j+1))){cnt-=(1<<j);break;}
					dp|=(dp<<(v[i]<<j));
				}
			}
			cnt=1;
		}
		else cnt++;
	}
	cout<<k+1-dp[k]<<" "<<maxi<<"\n";
	return 0;
}