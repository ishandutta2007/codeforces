#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		cin >> s;

		int x = 0, y = 0;
		int mn_x = 0, mx_x = 0;
		int mn_y = 0, mx_y = 0;

		int ans_x = 1, ans_y = 1;

		for (char c : s)
		{
			if (c == 'R') mx_y = max(mx_y, ++y);
			else if (c == 'L') mn_y = min(mn_y, --y);
			else if (c == 'D') mx_x = max(mx_x, ++x);
			else if (c == 'U') mn_x = min(mn_x, --x);

			if (mx_x - mn_x + 1 > n) break;
			if (mx_y - mn_y + 1 > m) break;

			ans_x = -mn_x + 1;
			ans_y = -mn_y + 1;
		}

		//cout << "ANS: ";
		cout << ans_x << ' ' << ans_y << '\n';
	}
}