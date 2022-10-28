#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string s;

int get(int i, int j)
{
	vector<char> reqd = {(char)(i + '0'), (char)(j + '0')};
	int cur = 0, ans = 0;
	for(int k = 0; k < n; k++)
	{
		if(s[k] != reqd[cur])
			ans++;
		else
			cur ^= 1;
	}
	if((n - ans) % 2)
		ans++;
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		n = s.size();
		int ans = n;
		map<int, int> f;
		for(auto &it:s)
			f[it]++;
		int mx = 0;
		for(auto &it:f)
			mx = max(mx, it.second);
		ans -= mx;
		for(int i = 0; i <= 9; i++)
			for(int j = 0; j <= 9; j++)
				ans = min(ans, get(i, j));
		cout << ans << endl;
	}
	return 0;
}