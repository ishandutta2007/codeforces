#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, ans;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n >> s;
		int idx = -1;
		for(int i = 0; i < n; i++)
		{
			if(s[0] != s[i])
			{
				idx = i;
				break;
			}
		}
		if(idx == -1)
		{
			cout << (n + 2) / 3 << endl;
			continue;
		}
		int curLen = 0;
		vector<int> store;
		int j = idx;
		for(int i = 0; i < n; i++)
		{
			if(s[j] == (s[(j - 1 + n) % n]))
				curLen++;
			else
			{
				store.push_back(curLen);
				curLen = 1;
			}
			j = (j + 1) % n;
		}
		store.push_back(curLen);
		for(auto &it:store)
			ans += it / 3;
		cout << ans << endl;
	}
	return 0;
}