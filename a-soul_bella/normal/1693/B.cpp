#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],dp[500005],l[500005],r[500005];
vector <int> e[500005];
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
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=2;i<=n;i++)
		{
			int fa;
			cin >> fa;
			e[fa].push_back(i);
		}
		for(int i=1;i<=n;i++)
			cin >> l[i] >> r[i];
		for(int i=n;i>=1;i--)
		{
			int s=0;
			dp[i]=0;
			for(auto v:e[i])
				s+=a[v],dp[i]+=dp[v];
			if(s>=l[i]) a[i]=min(s,r[i]);
			else a[i]=r[i],dp[i]++;
		}
		cout << dp[1] << "\n";
	}
	return 0;
}