#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

vector<int> p = {0, 5, 3, 2, 4, 1};

int32_t main()
{
	IOS;
	int a;
	cin >> a;
	vector<int> v;
	while(a > 0)
	{
		v.push_back(a % 2);
		a /= 2;
	}
	while(v.size() < 6)
		v.push_back(0);
	reverse(v.begin(), v.end());
	int ans = 0;
	for(auto &it:p)
		ans = ans * 2 + v[it];
	cout << ans;
	return 0;
}