#include <bits/stdc++.h>
#define int long long
using namespace std;
pair <int,int> a[1000005];
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
		{
			cin >> a[i].first;
			a[i].second=i;
		}
		sort(a+1,a+n+1);
		cout << a[1].second << " " << a[n].second << "\n";
	}
	return 0;
}