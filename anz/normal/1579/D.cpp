#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		priority_queue <pii> pq;
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a; cin >> a;
			if (a) pq.push({ a, i });
		}

		vector <pii> ans;
		while (pq.size() > 1)
		{
			pii a = pq.top(); pq.pop();
			pii b = pq.top(); pq.pop();

			ans.push_back({ a.second, b.second });
			if (--a.first) pq.push(a);
			if (--b.first) pq.push(b);
		}

		cout << ans.size() << '\n';
		for (auto it : ans)
			cout << it.first << ' ' << it.second << '\n';
	}
}