#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		map<char, int> m;
		for(auto &it:s)
			m[it]++;
		int cnt = 0;
		for(auto &it:m)
			if(it.first - '0' <= k)
				cnt++;
		ans += (cnt == k + 1);
	}
	cout << ans;
	return 0;
}