#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

struct Node
{
	int cnt[5];
};

int n;
Node a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			for (int j = 0; j < 5; j++) a[i].cnt[j] = 0;
			for (char c : s)
				a[i].cnt[c - 'a']++;
		}

		int ans = 0;

		for (int k = 0; k < 5; k++)
		{
			sort(a, a + n, [&k](Node n1, Node n2) {
				int s1 = 0, s2 = 0;
				for (int i = 0; i < 5; i++)
				{
					s1 += n1.cnt[i];
					s2 += n2.cnt[i];
				}
				return n1.cnt[k] * 2 - s1 > n2.cnt[k] * 2 - s2;
				});

			int cur = 0;
			int res = 0;
			for (int i = 0; i < n; i++)
			{
				int s = 0;
				for (int j = 0; j < 5; j++) s += a[i].cnt[j];
				int tmp = a[i].cnt[k] * 2 - s;

				cur += tmp;
				if (cur <= 0) break;

				res++;
			}

			ans = max(ans, res);
		}

		//cout << "ANS : ";
		cout << ans << '\n';
	}
}