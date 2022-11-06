#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;

		int ans = 0;
		int cnt = 0;
		bool hasOne = false;

		int i = 0;
		for (; i < n; i++)
		{
			if (s[i] == '1')
			{
				hasOne = true;
				break;
			}
			cnt++;
			continue;
		}

		if (!hasOne)
		{
			cout << (cnt - 1) / (k + 1) + 1 << '\n';
			continue;
		}

		int tmp = max(0, cnt - k);
		if (tmp) ans += (tmp - 1) / (k + 1) + 1;
		cnt = 0;

		for (i++; i < n; i++)
		{
			if (s[i] == '1')
			{
				int tmp = max(0, (cnt - k * 2));
				if(tmp) ans += (tmp - 1) / (k + 1) + 1;
				cnt = 0;
			}
			else cnt++;
		}

		tmp = max(0, cnt - k);
		if (tmp)ans += (tmp - 1) / (k + 1) + 1;

		cout << ans << '\n';
	}
}