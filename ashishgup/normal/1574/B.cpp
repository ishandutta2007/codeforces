#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, m;
		cin >> a >> b >> c >> m;
		int mx = a - 1 + b - 1 + c - 1;
		vector<int> v = {a, b, c};
		sort(v.begin(), v.end());
		int mn = max(0LL, v[2] - 1 - v[0] - v[1]);
		if(m >= mn && m <= mx)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}