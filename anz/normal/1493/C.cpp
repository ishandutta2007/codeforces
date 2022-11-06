#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
string s;

int cnt[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;

		if (n % k)
		{
			cout << "-1\n";
			continue;
		}

		memset(cnt, 0, sizeof cnt);
		for (char c : s) cnt[c - 'a']++;

		bool flag = true;
		for (int i = 0; i < 26; i++)
			if (cnt[i] % k) flag = false;

		if (flag)
		{
			cout << s << "\n";
			continue;
		}

		bool hasAns = false;
		for (int i = n - 1; i >= 0; i--)
		{
			cnt[s[i] - 'a']--;

			for (int j = s[i] - 'a' + 1; j < 26; j++)
			{
				cnt[j]++;

				int rm[26];
				int rsum = 0;
				for (int a = 0; a < 26; a++)
				{
					rm[a] = (k - cnt[a] % k) % k;
					rsum += rm[a];
				}

				if (rsum <= n - 1 - i)
				{
					hasAns = true;

					rm[0] += n - 1 - i - rsum;
					for (int a = 0; a < i; a++) cout << s[a];
					cout << (char)('a' + j);
					for (int a = 0; a < 26; a++)
					{
						for (int b = 0; b < rm[a]; b++) cout << (char)('a' + a);
					}

					cout << '\n';

					break;
				}

				cnt[j]--;
			}

			if (hasAns) break;
		}

		if (!hasAns) cout << "-1\n";
	}
}