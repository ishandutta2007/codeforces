#include <bits/stdc++.h>
#define int long long
using namespace std;
int vis[100005],a[100005],b[100005],p[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			vis[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin >> b[i];
			p[a[i]]=b[i];
		}
		int l=1,r=n,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			int now=i;
			int cnt=0;
			while(!vis[now])
				vis[now]=1,++cnt,now=p[now];
			cnt=cnt/2;
			while(cnt--) ans+=r-l,--r,++l;
		}
		cout << ans*2 << "\n";
	}
	return 0;
}