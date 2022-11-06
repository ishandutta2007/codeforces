#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;
int cnt[26];
int m;
int b[51];
bool cache[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);
		memset(cache, 0, sizeof cache);

		cin >> s;
		for (char c : s) cnt[c - 'a']++;

		cin >> m;
		for (int i = 0; i < m; i++) cin >> b[i];

		int ptr = 25;
		char ans[51] = { 0, };
		while (true)
		{
			vector <int> idx;
			for (int i = 0; i < m; i++)
			{
				if (cache[i]) continue;
				if (b[i] == 0) idx.push_back(i);
			}

			if (idx.empty()) break;

			while (!cnt[ptr] || cnt[ptr] < idx.size()) ptr--;

			for (int i : idx)
			{
				cache[i] = 1;
				ans[i] = ptr + 'a';
				for (int j = 1; i - j >= 0; j++)
					b[i - j] -= j;
				for (int j = 1; i + j < m; j++)
					b[i + j] -= j;
			}

			ptr--;
		}

		cout << ans << '\n';
	}
}