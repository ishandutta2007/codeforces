#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int p[100001];
int inv[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
			inv[p[i]] = i;
		}

		int last = n + 1;
		for (int i = n; i >= 1; i--)
		{
			if (inv[i] > last) continue;
			for (int j = inv[i]; j < last; j++) cout << p[j] << ' ';
			last = inv[i];
		}

		cout << '\n';
	}
}