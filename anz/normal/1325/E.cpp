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
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 100001;

bool prime[1000001];
vector <ll> p;

int n;
int a[N];

map <pii, int> mp;
pii dv[N];

int cache[N];

bool hasOne[N];
vector <int> graph[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	prime[0] = prime[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (prime[i] == 1) continue;
		for (int j = i + i; j <= 1000000; j += i)
			prime[j] = 1;
	}

	for (int i = 2; i <= 1000000; i++)
	{
		if (prime[i] == 0) p.push_back(i);
	}

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		int v1 = -1, v2 = -1;

		ll t = a[i];
		for (int j = 0; j < p.size(); j++)
		{
			auto it = p[j];
			if (it * it > a[i]) break;
			if (t % it == 0)
			{
				int cnt = 0;
				while (t % it == 0)
				{
					t /= it;
					cnt++;
				}

				if (cnt % 2 == 0) continue;
				if (v1 == -1) v1 = j;
				else v2 = j;
			}
		}

		if (t > 1)
		{
			int ci = lower_bound(p.begin(), p.end(), t) - p.begin();
			if (v1 == -1) v1 = ci;
			else v2 = ci;
		}

		if (v1 == -1 && v2 == -1)
		{
			cout << 1;
			return 0;
		}

		mp[{v1, v2}]++;
		dv[i] = { v1,v2 };

		if (v2 != -1)
		{
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		else hasOne[v1] = 1;
	}

	for (auto &it : mp)
	{
		if (it.second >= 2)
		{
			cout << 2;
			return 0;
		}
	}


	int ans = 987654321;
	for (int i = 0; i < N; i++)
	{
		if (hasOne[i])
		{
			memset(cache, 0, sizeof cache);
			cache[i] = 1;
			queue <int> q; q.push(i);

			bool flag = false;
			while (!q.empty())
			{
				int v = q.front(); q.pop();
				for (auto nv : graph[v])
				{
					if (cache[nv]) continue;
					cache[nv] = cache[v] + 1;
					if (hasOne[nv])
					{
						int res = cache[nv] + 1;
						ans = min(ans, res);

						flag = true;
						break;
					}

					q.push(nv);
				}

				if (flag) break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (p[i] > 1000) break;
		if (graph[i].size() == 0) continue;

		memset(cache, -1, sizeof cache);
		cache[i] = 0;
		queue <pii> q; q.push({ i,-1 });

		bool flag = false;
		while (!q.empty())
		{
			int v = q.front().first;
			int par = q.front().second;
			q.pop();
			for (auto nv : graph[v])
			{
				if (nv == par) continue;
				if (cache[nv] != -1)
				{
					int res = cache[v] + cache[nv] + 1;
					ans = min(ans, res);
					flag = true;
					break;
				}

				cache[nv] = cache[v] + 1;
				q.push({ nv, v });
			}

			if (flag) break;
		}
	}

	if (ans == 987654321) ans = -1;
	cout << ans;
	// not hacked
}