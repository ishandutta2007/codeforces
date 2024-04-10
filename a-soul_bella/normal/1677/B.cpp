#include <bits/stdc++.h>
using namespace std;
int ans1[2000005],ans2[2000005],a[2000005],s[2000005];
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
		for(int i=1;i<=n*m;i++) ans1[i]=ans2[i]=0;
		for(int i=1;i<=n*m;i++)
		{
			char c;
			cin >> c;
			a[i]=c-'0';
			ans1[i]+=a[i];
			s[i]=s[i-1]+a[i];
		}
		for(int i=1;i<=m;i++)
			ans2[i]=!!s[i];
		for(int i=m+1;i<=n*m;i++)
			ans2[i]=ans2[i-m]+(!!(s[i]-s[i-m]));
		for(int i=m+1;i<=n*m;i++)
			ans1[i]|=ans1[i-m];
		for(int i=1;i<=n*m;i++)
			ans1[i]+=ans1[i-1];
		for(int i=1;i<=n*m;i++)
		{
			if(i<=m) cout << ans1[i]+ans2[i] << " ";
			else  cout << ans1[i]+ans2[i]-ans1[i-m] << " ";
		}
		cout << "\n";
	}
	return 0;
}