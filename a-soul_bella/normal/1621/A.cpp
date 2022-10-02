#include <bits/stdc++.h>
using namespace std;
char ans[1005][1005];
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
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans[i][j]='.';
		if(k>(n+1)/2)
		{
			cout << "-1\n";
			continue;
		}
		for(int i=1;i<=n;i+=2)
			if(k) ans[i][i]='R',--k;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout << ans[i][j];
			cout << "\n";
		}
	}
	return 0;
}