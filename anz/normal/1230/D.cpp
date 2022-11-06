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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;
ll a[7001], b[7001];

bool cant[7001];
bitset<7001> graph[7001]; // a->b if a better than b
int sz[7001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		if (i == j) continue;
		if (a[i] & (~a[j]))
		{
			graph[i][j] = 1;
			sz[i]++;
		}
	}

	int rm = n;
	ll ans = 0;

	queue <int> q;
	for (int i = 0; i < n; i++)
	{
		if (sz[i] == rm - 1)
		{
			cant[i] = true;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int c = q.front(); q.pop();
		rm--;
		for (int i = 0; i < n; i++)
		{
			if (cant[i]) continue;
			if (graph[i][c] == 1) sz[i]--;
			else
			{
				if (sz[i] == rm - 1)
				{
					cant[i] = true;
					q.push(i);
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!cant[i]) ans += b[i];
	}
	cout << ans;
}