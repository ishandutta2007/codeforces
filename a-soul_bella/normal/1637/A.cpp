#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int flag=0;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[i-1]) flag=1;
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}