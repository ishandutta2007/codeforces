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

string s;
int ps[500001][26];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s;

	for (int i = 1; i <= s.size(); i++)
	{
		ps[i][s[i - 1] - 'a']++;
		for (int j = 0; j < 26; j++)
			ps[i][j] += ps[i - 1][j];
	}

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;

		if (l == r)
		{
			cout << "Yes\n";
			continue;
		}

		int cnt = 0;
		for (int i = 0; i < 26; i++)
		{
			int res = ps[r][i] - ps[l - 1][i];
			if (res > 0) cnt++;
		}

		if (cnt <= 2 && s[r - 1] == s[l - 1]) cout << "No\n";
		else cout << "Yes\n";
	}
}