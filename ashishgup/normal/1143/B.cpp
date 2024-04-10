#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int32_t main()
{
	IOS;
	string s;
	cin >> s;
	vector<int> pw9;
	pw9.push_back(1);
	for(int i = 1; i <= 10; i++)
		pw9.push_back(pw9.back() * 9);
	int ans = 1;
	int cur = 1;
	int len = s.size();
	for(auto &it:s)
	{
		len--;
		int temp = cur * pw9[len];
		int x = (it - '1');
		if(len + 1 == s.size())
			x = max(x, 1LL);
		temp *= x;
		ans = max(ans, temp);
		cur *= (it - '0');
	}
	ans = max(ans, cur);
	cout << ans;
	return 0;
}