#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == i)
				continue;
			int j = i;
			while(j + 1 <= n && j + 1 != a[j + 1])
				j++;
			i = j;
			ans++;
		}
		ans = min(ans, 2LL);
		cout << ans << endl;
	}
	return 0;
}