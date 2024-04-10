#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		set <pii> S, N, W, E;
		int x = 0, y = 0;
		string s; cin >> s;

		int ans = 0;
		for (auto c : s)
		{
			if (c == 'N')
			{
				x--;
				if (S.find({ x + 1,y }) != S.end() || N.find({ x,y }) != N.end())
					ans++;
				else ans += 5;

				N.insert({ x,y });
			}
			else if (c == 'S')
			{
				x++;
				if (N.find({ x - 1,y }) != N.end() || S.find({ x,y }) != S.end())
					ans++;
				else ans += 5;

				S.insert({ x,y });
			}
			else if (c == 'W')
			{
				y--;
				if (E.find({ x,y + 1 }) != E.end() || W.find({ x,y }) != W.end())
					ans++;
				else ans += 5;

				W.insert({ x,y });
			}
			else if (c == 'E')
			{
				y++;
				if (W.find({ x,y - 1 }) != W.end() || E.find({ x,y }) != E.end())
					ans++;
				else ans += 5;

				E.insert({ x,y });
			}
		}
		cout << ans << '\n';
	}
}