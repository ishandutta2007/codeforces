#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, a, ans = 0;
string s;
int cnt[N];
 
int32_t main()
{
	IOS;
	cin >> a >> s;
	n = s.size();
	for(int i = 0; i < n; i++)
	{
		int cur = 0;
		for(int j = i; j < n; j++)
		{
			cur += (s[j] - '0');
			cnt[cur]++;
		}
	}
	if(a == 0)
	{
		int ans = 2 * cnt[0] * (n * (n + 1) / 2 - cnt[0]);
		ans += cnt[0] * cnt[0];
		cout << ans;
		return 0;
	}
	for(int i = 1; i < N; i++)
	{
		if(a % i)
			continue;
		if(a / i >= N)
			continue;
		ans += cnt[i] * cnt[a / i];
	}
	cout << ans;
	return 0;
}