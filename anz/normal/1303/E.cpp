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

string s, t;
int back[401][26];
int dp[401][401][401]; // a   
int solve(int idx, int a, int b)
{
	//cout << "DEBUG: " << idx << ' ' << a << ' ' << b << '\n';
	int& ret = dp[idx][a][b];
	if (ret != -1) return ret;
	ret = -2;

	if (b == t.size())
	{
		int b1 = -1;
		if(a < t.size()) b1 = back[idx][t[a] - 'a'];
		if (b1 != -1) return ret = max(a, solve(b1, a + 1, b));
		else return ret = a;
	}

	int b1 = -1;
	if (a < t.size()) b1 = back[idx][t[a] - 'a'];
	int b2 = -1;
	if (b < t.size()) b2 = back[idx][t[b] - 'a'];

	if (b2 == -1) return ret = -2;
	if (b1 == -1) return ret = max(ret, solve(b2, a, b + 1));

	ret = -2;
	if (b1 < b2) ret = max(ret, solve(b1, a + 1, b));
	else if (b1 > b2) ret = max(ret, solve(b2, a, b + 1));
	else
	{
		ret = max(ret, solve(b1, a + 1, b));
		ret = max(ret, solve(b2, a, b + 1));
		return ret;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> s >> t;
		int tmp[26]; memset(tmp, -1, sizeof tmp);
		memset(back, -1, sizeof back);
		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = 0; j < 26; j++) back[i + 1][j] = tmp[j];
			tmp[s[i] - 'a'] = i + 1;
		}
		for (int j = 0; j < 26; j++) back[0][j] = tmp[j];

		for (int i = 0; i <= s.size(); i++) for (int j = 0; j <= t.size(); j++)
			for (int k = 0; k <= t.size(); k++) dp[i][j][k] = -1;

		bool ans = false;
		for (int i = 0; i < t.size(); i++)
		{
			int res = solve(0, 0, i);
			if (res >= i)
			{
				ans = true;
				break;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}