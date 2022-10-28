#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	vector<int> v;
	for(int i = 1; i <= 3; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int a, b, c, d;
	cin >> d;
	a = v[0], b = v[1], c = v[2];
	int ans = d - abs(a - b);
	ans = max(0LL, ans);
	int ans2 = d - abs(b - c);
	ans2 = max(0LL, ans2);
	cout << ans + ans2;
	return 0;
}