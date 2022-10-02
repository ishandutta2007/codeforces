#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
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
		if(n==3&&a[2]%2==1)
		{
			cout << "-1\n";
			continue;
		}
		int cnt=0,sum=0;
		for(int i=2;i<n;i++)
			cnt+=a[i]==1,sum+=a[i]+a[i]%2;
		if(cnt==n-2)
		{
			cout << "-1\n";
			continue;
		}
		cout << sum/2 << "\n"; 
	}
	return 0;
}