#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		priority_queue<pii> pq;
		pq.push({ n, 0 });

		for (int i = 1; i <= n; i++)
		{
			pii tmp = pq.top(); pq.pop();
			int sz = tmp.first;
			int idx = -tmp.second;

			ans[idx + (sz - 1) / 2] = i;
			if (sz > 2) pq.push({ (sz - 1) / 2, -idx });
			if (sz > 1) pq.push({ sz / 2, -(idx + (sz - 1) / 2 + 1) });
		}

		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}