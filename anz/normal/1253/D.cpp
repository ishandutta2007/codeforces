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

int n, m;
vector <int> graph[200001];

int cache[200001];

int cMv = -1;

int cnt = 0;
int scc[200001];
int mv[200001];

void DFS(int s)
{
	cache[s] = 1;
	scc[s] = cnt;
	cMv = max(cMv, s);

	for (auto it : graph[s])
	{
		if (cache[it]) continue;
		DFS(it);
	}
}

set <int > s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (cache[i]) continue;
		cMv = i;
		cnt++;
		DFS(i);
		mv[cnt] = cMv;
	}

	int ans = 0;
	int cV = 1;
	

	while (cV <= n)
	{
		s.clear();
		int mV = mv[scc[cV]];
		s.insert(scc[cV]);

		int i;
		for (i = cV + 1; i <= mV; i++)
		{
			if (s.find(scc[i]) == s.end())
			{
				s.insert(scc[i]);
				ans++;
				mV = max(mV, mv[scc[i]]);
			}
		}

		cV = i;
	}

	cout << ans;
}