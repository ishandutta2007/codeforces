#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],ans[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,q;
		cin >> n >> q;
		for(int i=1;i<=n;i++) ans[i]=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int l=1,r=n,pos=n+1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int now=q;
			for(int i=mid;i<=n;i++)
				if(a[i]>now) --now;
			if(now>=0)
			{
				pos=mid,r=mid-1;
			}
			else l=mid+1;
		}
		for(int i=1;i<pos;i++)
			if(a[i]<=q) ans[i]=1;
		for(int i=pos;i<=n;i++)
		{
			if(a[i]>q) --q,ans[i]=1;
			else ans[i]=1;
		}
		for(int i=1;i<=n;i++)
			cout << ans[i];
		cout << "\n";
	}
	return 0;
}