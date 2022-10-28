#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		int ans = 0;
		for(int i = 0, j = k - 1; i <= j; i++, j--)
		{
			map<char, int> f;
			int cnt = 0;
			for(int idx = i; idx < n; idx += k)
				f[s[idx]]++, cnt++;
			if(j != i)
			{
				for(int idx = j; idx < n; idx += k)
					f[s[idx]]++, cnt++;
			}
			int cur = cnt;
			for(auto &it:f)
				cur = min(cur, cnt - it.second);
			ans += cur;
		}
		cout << ans << endl;
	}
	return 0;
}