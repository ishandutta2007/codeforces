#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
int a[200001];
vector <int> v[200001];

int cnt[200001];
int ans[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= k; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 0; i < n; i++) ans[i] = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			v[a[i]].push_back(i);
		}

		int sum = 0;
		for (int i = 1; i <= n; i++) sum += min(k, (int)v[i].size());

		int res = sum / k;
		priority_queue <pii> pq;
		for (int i = 1; i <= k; i++) pq.push({ res, i });

		for (int i = 1; i <= n; i++)
		{
			int cnt = min(k, (int)v[i].size());
			vector <pii> tmp;

			for (int j = 0; j < cnt && !pq.empty(); j++)
			{
				auto it = pq.top(); pq.pop();
				ans[v[i][j]] = it.second;
				if (--it.first) tmp.push_back(it);
			}

			for (auto it : tmp) pq.push(it);
		}

		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}