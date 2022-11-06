#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
string a, b;

int cnta[27], cntb[27];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> a >> b;

		bool ans = true;

		memset(cnta, 0, sizeof cnta);
		memset(cntb, 0, sizeof cntb);

		for (char c : a) cnta[c - 'a']++;
		for (char c : b) cntb[c - 'a']++;

		for (int i = 0; i < 26; i++)
		{
			if (cntb[i] > cnta[i])
			{
				ans = false;
				break;
			}

			int d = cnta[i] - cntb[i];
			if (d % k)
			{
				ans = false;
				break;
			}

			cnta[i] -= d;
			cnta[i + 1] += d;
		}

		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}