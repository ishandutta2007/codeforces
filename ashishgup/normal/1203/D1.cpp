#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
string s, t;
int f[N], l[N];

int32_t main()
{
	IOS;
	cin >> s >> t;
	n = s.size();
	m = t.size();
	int idx = 0;
	for(int i = 0; i < n; i++)
	{
		if(idx < m && s[i] == t[idx])
		{
			f[idx] = i;
			idx++;
		}
	}
	idx = m - 1;
	for(int i = n - 1; i >= 0; i--)
	{
		if(idx >= 0 && s[i] == t[idx])
		{
			l[idx] = i;
			idx--;
		}
	}
	int ans = l[0];
	ans = max(ans, n - 1 - f[m - 1]);
	for(int i = 1; i < m; i++)
	{
		int cur = l[i] - f[i - 1] - 1;
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}