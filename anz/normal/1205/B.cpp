#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}
int n;
ll a[100001];
vector <ll> new_a;

vector <int> graph[100001];
int cache[100001], par[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] & (a[i] - 1)) new_a.push_back(a[i]);
	}

	bool flag = false;
	for (int k = 0; k <= 61; k++)
	{
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] & (1ll << k))
			{
				tmp++;
			}
		}
		if (tmp > 2) flag = true;
	}

	if (flag)
	{
		cout << "3";
		return 0;
	}

	for (int i = 0; i < new_a.size(); i++) for (int j = i + 1; j < new_a.size(); j++)
	{
		if (new_a[i] & new_a[j])
		{
			graph[i].push_back(j);
			graph[j].push_back(i);
		}
	}

	int ans = 987654321;
	for (int s = 0; s < new_a.size(); s++)
	{
		memset(cache, -1, sizeof cache);
		memset(par, -1, sizeof par);
		queue <int> q;
		q.push(s); cache[s] = 0;

		while (!q.empty())
		{
			int c = q.front(); q.pop();
			for (int i : graph[c])
			{
				if (par[c] == i) continue;
				if (cache[i] != -1)
				{
					int cycle = cache[c] + cache[i] + 1;
					ans = min(ans, cycle);
					continue;
				}

				cache[i] = cache[c] + 1;
				par[i] = c;
				q.push(i);
			}
		}
	}

	if (ans == 987654321) cout << -1;
	else cout << ans;
}