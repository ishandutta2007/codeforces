#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;
vector <int> idx[26];
int cache[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		for (int i = 0; i < 26; i++) idx[i].clear();

		cin >> s;
		for (int i = 0; i < s.size(); i++)
			idx[s[i] - 'a'].push_back(i);

		memset(cache, 0, sizeof cache);

		int len = 0;
		for (int i = 0; i < 26; i++)
		{
			if (idx[i].empty()) cache[i] = 1;
			else len++;
		}

		int last = -1;
		string ans;
		for (int i = 0; i < len; i++)
		{
			for (int j = 25; j >= 0; j--)
			{
				if (cache[j]) continue;
				int clast = *upper_bound(idx[j].begin(), idx[j].end(), last);

				bool flag = true;
				for (int k = 0; k < 26; k++)
				{
					if (cache[k] || k == j) continue;
					if (upper_bound(idx[k].begin(), idx[k].end(), clast) == idx[k].end()) flag = false;
				}

				if (flag)
				{
					ans += (char)(j + 'a');
					last = clast;
					cache[j] = 1;
					break;
				}
			}
		}

		cout << ans << '\n';
	}
}