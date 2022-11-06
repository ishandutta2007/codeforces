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

int n, m;
string s;

ll cnt[200001][26];
ll ans[26];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cin >> s;

		for (int i = 0; i < 26; i++) cnt[0][i] = 0, ans[i] = 0;
		for (int i = 1; i <= s.size(); i++)
		{
			int c = s[i - 1] - 'a';
			ans[c]++;
			for (int j = 0; j < 26; j++)
			{
				cnt[i][j] = cnt[i - 1][j];
				if (j == c) cnt[i][j]++;
			}
		}

		for (int i = 0; i < m; i++)
		{
			int p; cin >> p;
			for (int j = 0; j < 26; j++)
			{
				ans[j] += cnt[p][j];
			}
		}

		for (int i = 0; i < 26; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}