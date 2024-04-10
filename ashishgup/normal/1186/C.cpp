#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string a, b;
	cin >> a >> b;
	int curXor = 0;
	for(auto &it:b)
		curXor ^= (it - '0');
	int n = a.size(), m = b.size();
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		curXor ^= (a[i] - '0');
		if(i >= m)
			curXor ^= (a[i - m] - '0');
		if(i >= m - 1 && curXor == 0)
			ans++;
	}
	cout << ans;
	return 0;
}