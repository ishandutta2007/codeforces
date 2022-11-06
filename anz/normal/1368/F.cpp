#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int tmp[1001];
int ocp[1001];

int main()
{
	cin >> n;
	if (n < 4)
	{
		cout << 0 << endl;
		return 0;
	}

	int sz = 0;
	int ans = 0;

	for (int i = 2; i <= n; i++)
	{
		int res = n - ((n - 1) / i + 1) - (i - 1);
		if (res > ans)
		{
			ans = res;
			sz = i;
		}
	}

	for (int i = 0; i * sz < n; i++)
	{
		tmp[i * sz + 1] = 1;
	}

	while (true)
	{
		vector <int> query;
		for (int i = 1; i <= n; i++)
		{
			if (tmp[i] || ocp[i]) continue;
			ocp[i] = 1;
			query.push_back(i);
			if (query.size() == sz) break;
		}

		cout << query.size();
		for (int i : query) cout << ' ' << i;
		cout << endl;

		int res; cin >> res;
		for (int i = 0; i < sz; i++)
		{
			ocp[(res - 1 + i) % n + 1] = 0;
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ocp[i]) cnt++;
		}

		if (cnt >= ans) break;
	}

	cout << 0 << endl;
}