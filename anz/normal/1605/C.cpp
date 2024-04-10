#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> s;

		int ans = 10;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != 'a') continue;
			if (i + 1 < n)
			{
				if (s[i + 1] == 'a')
					ans = min(ans, 2);
			}
			if (i + 2 < n)
			{
				if (s[i + 2] == 'a')
					ans = min(ans, 3);
			}
			if (i + 3 < n)
			{
				int cnt[3] = { 0,0,0 };
				for (int k = i; k <= i + 3; k++) cnt[s[k] - 'a']++;

				if (cnt[1] < cnt[0] && cnt[2] < cnt[0])
					ans = min(ans, 4);
			}
			if (i + 6 < n)
			{
				int cnt[3] = { 0,0,0 };
				for (int k = i; k <= i + 6; k++) cnt[s[k] - 'a']++;

				if (cnt[1] < cnt[0] && cnt[2] < cnt[0])
					ans = min(ans, 7);
			}
		}

		if (ans == 10) cout << "-1\n";
		else cout << ans << '\n';
	}
}