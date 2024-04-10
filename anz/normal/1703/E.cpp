#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			for (int j = 0; j < n; j++) a[i][j] = s[j] - '0';
		}

		int ans = 0;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = i; j < n - 1 - i; j++)
			{
				int cnt[2] = { 0,0 };
				cnt[a[i][j]]++;
				cnt[a[n - 1 - j][i]]++;
				cnt[a[n - 1 - i][n - 1 - j]]++;
				cnt[a[j][n - 1 - i]]++;

				ans += min(cnt[0], cnt[1]);
			}
		}

		//cout << "ANS: ";
		cout << ans << '\n';
	}
}