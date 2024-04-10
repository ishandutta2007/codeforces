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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;

vector <int> graph[200001];
int a[200001];
int dist[200001];
int cache[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dist, -1, sizeof dist);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	queue <int> q;
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		int par = a[i] % 2;
		if (i >= a[i])
		{
			graph[i - a[i]].push_back(i);
			if (a[i - a[i]] % 2 == 1 - par)
			{
				dist[i] = 1;
				flag = true;
			}
		}
		if (i + a[i] < n)
		{
			graph[i + a[i]].push_back(i);
			if (a[i + a[i]] % 2 == 1 - par)
			{
				dist[i] = 1;
				flag = true;
			}
		}

		if (flag)
		{
			q.push(i);
			cache[i] = true;
		}
	}

	while (!q.empty())
	{
		int i = q.front(); q.pop();
		for (auto it : graph[i])
		{
			if (cache[it]) continue;
			dist[it] = dist[i] + 1;
			cache[it] = true;
			q.push(it);
		}
	}

	for (int i = 0; i < n; i++) cout << dist[i] << ' ';
}