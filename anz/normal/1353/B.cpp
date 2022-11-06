#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
int a[31], b[31];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		priority_queue <int> qa, qb;
		cin >> n >> k;

		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			qa.push(-x);
		}

		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			qb.push(x);
		}

		for (int i = 0; i < k; i++)
		{
			int ta = -qa.top();
			int tb = qb.top();

			if (ta >= tb) break;
			
			qa.pop(); qb.pop();

			qa.push(-tb);
			qb.push(ta);
		}

		int ans = 0;
		while (!qa.empty())
		{
			ans -= qa.top();
			qa.pop();
		}

		cout << ans << '\n';
	}
}