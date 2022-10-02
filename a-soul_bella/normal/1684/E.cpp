#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],cnt[100005];
int b[100005];
map <int,int> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		int now=0;
		for(int i=0;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]<=n) ++cnt[a[i]];
		}
		sort(a+1,a+n+1);
		int len=max(n-k,0ll);
		for(int i=n;i>=n-k+1;i--)
		{
			while(cnt[now]&&now<=n&&now<=a[i]) ++now;
			if(now>=a[i]) break;
			if(a[i]<=n) --cnt[a[i]];
			++cnt[now];
		}
		int ex=0;
		for(int i=0;i<=n;i++)
		{
			if(!cnt[i])
			{
				ex=i;
				break;
			}
		}
		mp.clear();
		for(int i=1;i<=n;i++)
			if(a[i]>=ex) ++mp[a[i]];
		int qwq=0;
		for(int i=1;i<=n;i++)
			if(mp[a[i]]) b[++qwq]=mp[a[i]],mp[a[i]]=0;
		sort(b+1,b+qwq+1);
		for(int i=1;i<=qwq;i++)
		{
			if(b[i]<=k)
			{
				k-=b[i];
				b[i]=0;
			}
			else
			{
				b[i]-=k;
				k=0;
			}
		}
		int ans=0;
		for(int i=1;i<=qwq;i++)
			if(b[i]) ++ans;
		cout << ans << "\n";
	}
	return 0;
}