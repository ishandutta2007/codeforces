#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = 2; i <= 62; i++)
	{
		int t = (1LL << i) - 1;
		for(int j = 0; j < i - 1; j++)
		{
			t ^= 1LL << j;
			if(a <= t && t <= b)
				ans++;
			t ^= 1LL << j;
		}
	}
	cout << ans << "\n";
	
}