#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int back[100001][26];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(back, -1, sizeof back);
		string s, t; cin >> s >> t;
		int isExist[26] = { 0, };
		for (char c : s) isExist[c - 'a'] = 1;

		bool flag = false;
		for (char c : t)
		{
			if (!isExist[c - 'a'])
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			cout << "-1\n";
			continue;
		}

		memset(isExist, -1, sizeof isExist);
		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = 0; j < 26; j++)
				back[i + 1][j] = isExist[j];

			isExist[s[i] - 'a'] = i + 1;
		}

		for (int j = 0; j < 26; j++)
			back[0][j] = isExist[j];

		int ans = 1;

		int cd = 0;
		for (int i = 0; i < t.size(); i++)
		{
			if (back[cd][t[i] - 'a'] == -1)
			{
				ans++;
				cd = 0;
			}

			cd = back[cd][t[i] - 'a'];
		}

		cout << ans << '\n';
	}
}