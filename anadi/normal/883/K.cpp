#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;

const int N = 2e5 + 7;

int n, st[N], s[N], g[N], k[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i] >> g[i];
		k[i] = s[i] + g[i];
		st[i] = s[i];
	}	
	for(int i = 2; i <= n; i++)
	{
		k[i] = min(k[i], k[i - 1] + 1);
		s[i] = max(s[i], s[i - 1] - 1);
		if(k[i] < s[i])
		{
			cout << -1 << "\n";
			return 0;
		}
	}
	LL ans = k[n] - st[n];
	for(int i = n - 1; i >= 1; i--)
	{
		k[i] = min(k[i], k[i + 1] + 1);
		s[i] = max(s[i], s[i + 1] - 1);
		if(k[i] < s[i])
		{
			cout << -1 << "\n";
			return 0;
		}
		ans += k[i] - st[i];
	}
	cout << ans << "\n";
	for(int i = 1; i <= n; i++)
		cout << k[i] << " ";
	return 0;
}