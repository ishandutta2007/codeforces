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
#include <list>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int k;
vector <pll> graph[200001];

ll cache[200001];
ll deg[200001];
ll sz[200001];
ll len[200001];

int getSize(int s, int p)
{
	int res = 1;
	for (auto it : graph[s])
	{
		if (cache[it.first] || it.first == p) continue;
		res += getSize(it.first, s);
	}

	return deg[s] = res;
}

int getCent(int s, int p, int sz)
{
	for (auto it : graph[s])
	{
		if (cache[it.first] || it.first == p) continue;
		if (deg[it.first] > sz / 2)
			return getCent(it.first, s, sz);
	}
	return s;
}

ll getB(int s, int p)
{
	sz[s] = 1;
	len[s] = 0;
	for (auto v : graph[s])
	{
		if (v.first == p) continue;
		len[s] += getB(v.first, s);
		sz[s] += sz[v.first];
		len[s] += sz[v.first] * v.second;
	}

	return len[s];
}

pair<ll, bool> getG(int s, int p)
{
	ll res = 0;
	int child = 0;
	for (auto it : graph[s])
	{
		if (it.first == p) continue;
		auto ch = getG(it.first, s);
		if (ch.second)
		{
			child++;
			res += it.second;
		}
		res += ch.first;
	}

	if (child % 2)
		return{ res, false };
	else
		return{ res, true };
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll G = 0, B = 0;
		cin >> k;
		for (int i = 1; i <= 2 * k; i++)
		{
			graph[i].clear();
			sz[i] = 0, len[i] = 0;
			cache[i] = 0, deg[i] = 0;
		}
		for (int i = 0; i < k * 2 - 1; i++)
		{
			ll a, b, c; cin >> a >> b >> c;
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,c });
		}

		int sz = getSize(1, -1);
		int cent = getCent(1, -1, sz);
		B = getB(cent, -1);

		G = getG(cent, -1).first;

		cout << G << ' ' << B << '\n';
	}
}