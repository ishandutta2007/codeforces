//Started 2 mins late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int m, n;
string s, t;
int f[N], l[N];

int32_t main()
{
	IOS;
	cin >> m >> n;
	cin >> s >> t;
	int ans = 0;
	int idx = 0, last = 0;
	for(int i = 0; i < m; i++)
	{
		if(idx < n && s[i] == t[idx])
			f[idx] = i, idx++;
	}
	idx = n - 1;
	for(int i = m - 1; i >= 0; i--)
	{
		if(idx >= 0 && s[i] == t[idx])
			l[idx] = i, idx--;
	}
	for(int i = 0; i + 1 < n; i++)
		ans = max(ans, l[i + 1] - f[i]);
	cout << ans;
	return 0;
}