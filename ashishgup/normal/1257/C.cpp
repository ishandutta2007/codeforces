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
		int ans = n + 1;
		map<int, int> prv;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(prv.count(a[i]))
				ans = min(ans, i - prv[a[i]] + 1);
			prv[a[i]] = i;
		}
		if(ans > n)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}