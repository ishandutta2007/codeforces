#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[200005],s1[200005],s2[200005],w[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	int now=0;
	for(int i=0;i<=200000;i++)
	{
		while((1ll<<now)<i) ++now;
		w[i]=(1ll<<now)-i;
	}
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) s1[i]=s2[i]=cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			++cnt[x];
		}
		int sum=0;
		for(int i=1;i<=n;i++) sum+=cnt[i],s1[sum]=sum;sum=0;
		for(int i=n;i>=1;i--) sum+=cnt[i],s2[sum]=sum;
		for(int i=1;i<=n;i++) s1[i]=max(s1[i],s1[i-1]);
		for(int i=1;i<=n;i++) s2[i]=max(s2[i],s2[i-1]);
		int ans=1e9;
		for(int i=0;i<=18;i++)
		{
			int x=min((1ll<<i),n),X=s1[x];
			for(int j=0;j<=18;j++)
			{
				int y=min((1ll<<j),n),Y=s2[y];
				if(X+s2[y]<=n)
				{
					ans=min(ans,(1ll<<i)-X+(1ll<<j)-Y+w[n-X-Y]);
				}
			}
		}
		for(int i=0;i<=18;i++)
		{
			int x=min((1ll<<i),n),X=0;
			for(int j=0;j<=18;j++)
			{
				int y=min((1ll<<j),n),Y=s2[y];
				if(X+s2[y]<=n)
				{
					ans=min(ans,(1ll<<i)-X+(1ll<<j)-Y+w[n-X-Y]);
				}
			}
		}
		for(int i=0;i<=18;i++)
		{
			int x=min((1ll<<i),n),X=s1[x];
			for(int j=0;j<=18;j++)
			{
				int y=min((1ll<<j),n),Y=0;
				if(X+s2[y]<=n)
				{
					ans=min(ans,(1ll<<i)-X+(1ll<<j)-Y+w[n-X-Y]);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}