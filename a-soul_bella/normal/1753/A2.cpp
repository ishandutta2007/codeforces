#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[500005],cnt[500005],del[500005];
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
		int S=0;
		for(int i=1;i<=n;i++)
		{
			del[i]=0;
			cin >> a[i];
			S+=a[i];
		}
		if(S%2)
		{
			cout << "-1\n";
			continue;
		}
		int C=n;
		if(S>0)
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==1&&S>0)
				{
					del[i]=1,++i,S-=2,--C;
				}
			}
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==-1&&S<0)
				{
					del[i]=1,++i,S+=2,--C;
				}
			}
		}
		cout << C << "\n";
		del[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			if(del[i+1])
			{
				cout << i << " " << i+1 << "\n";
				++i;
			}
			else
			{
				cout << i << " " <<i << "\n";
			}
		}
	}
	return 0;
}