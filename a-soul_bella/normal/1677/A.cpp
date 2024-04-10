#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],s[5005][5005];
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
			cin >> a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				s[i][j]=0;
		for(int i=1;i<=n;i++)
			++s[i][a[i]];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				s[i][j]+=s[i-1][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				s[i][j]+=s[i][j-1];
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int x=s[i-1][a[j]];
				int y=s[n][a[i]]-s[j][a[i]];
				ans+=x*y;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}