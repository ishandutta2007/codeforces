#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int G=0;
		for(int i=1;i<=m;i++)
		{
			int x;
			cin >> x;
			G=gcd(G,x);
		}
		int ans=-2e18,sum=0;
		for(int i=1;i<=n;i++)
			sum+=max(a[i],-a[i]);
		for(int i=1;i<=G;i++)
		{
			int cnt=0,mn=2e9;
			for(int j=i;j<=n;j+=G)
			{
				cnt+=a[j]<0;
				mn=min(mn,max(a[j],-a[j]));
			}
			if(cnt&1) sum-=mn*2;
		}
		ans=max(ans,sum);
		for(int i=1;i<=G;i++) a[i]=-a[i];sum=0;
		for(int i=1;i<=n;i++)
			sum+=max(a[i],-a[i]);
		for(int i=1;i<=G;i++)
		{
			int cnt=0,mn=2e9;
			for(int j=i;j<=n;j+=G)
			{
				cnt+=a[j]<0;
				mn=min(mn,max(a[j],-a[j]));
			}
			if(cnt&1) sum-=mn*2;
		}
		cout << max(ans,sum) << "\n";
	}
	return 0;
}