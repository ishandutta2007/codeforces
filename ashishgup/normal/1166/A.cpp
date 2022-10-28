#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 0;
string s[N];
map<char, int> m;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		m[s[i][0]]++;
	}
	for(auto &it:m)
	{
		int x = it.second / 2;
		ans += x * (x - 1) / 2;
		x += it.second % 2;
		ans += x * (x - 1) / 2;
	}
	cout << ans;
	return 0;
}