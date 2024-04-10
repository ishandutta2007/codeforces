#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];

int get(int x)
{
	int ans = -1e9;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > x)
			continue;
		int j = i;
		int cur = 0;
		while(j <= n)
		{
			if(a[j] <= x)
				cur += a[j];
			else
				break;
			ans = max(ans, cur);
			if(cur < 0)
				cur = 0;
			j++;
		}
		i = j;
	}
	ans -= x;
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = -30; i <= 30; i++)
		ans = max(ans, get(i));
	cout << ans;
	return 0;
}