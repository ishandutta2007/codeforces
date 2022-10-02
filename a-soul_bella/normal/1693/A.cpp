#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
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
		int flag=1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
			if(a[i]<0) flag=0;
		}
		for(int i=1;i<n;i++)
			if(a[i]==0&&a[i+1]!=0) flag=0;
		if(a[n]||!flag)
		{
			cout << "No\n";
		}
		else cout << "Yes\n";
	}
	return 0;
}