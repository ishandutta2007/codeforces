#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[1000005],sum[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,c;
		cin >> n >> c;
		for(int i=1;i<=c;i++)
			sum[i]=cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			++cnt[x];
		}
		int flag=1;
		for(int i=1;i<=c;i++)
			sum[i]=sum[i-1]+cnt[i];
		for(int i=1;i<=c;i++)
		{
			for(int j=i;j<=c;j+=i)
			{
				if(sum[min(j+i-1,c)]-sum[j-1]>0&&!cnt[j/i]&&cnt[i])
				{
					flag=0;
				}
			}
		}
		if(flag)
		{
			cout << "Yes\n";
			continue;
		}
		cout << "No\n";
	}
	return 0;
}