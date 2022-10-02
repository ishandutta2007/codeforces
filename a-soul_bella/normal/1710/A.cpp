#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int a[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		for(int i=1;i<=k;i++)
			cin >> a[i];
		int x=0,all2=1;
		for(int i=1;i<=k;i++)
		{
			if(a[i]>=m*2)
			{
				x+=a[i]/m;
				if(a[i]/m!=2) all2=0;
			}
		}
		if(x>=n&&(!all2||n%2==0)) cout << "YES\n";
		else
		{
			all2=1;
			swap(n,m);
			x=0;
		for(int i=1;i<=k;i++)
		{
			if(a[i]>=m*2)
			{
				x+=a[i]/m;
				if(a[i]/m!=2) all2=0;
			}
		}
		if(x>=n&&(!all2||n%2==0)) cout << "YES\n";
		else cout << "NO\n";
		}
	}
	return 0;
}