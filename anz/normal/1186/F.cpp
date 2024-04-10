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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n, m;
int goal;

int orginDeg[1000001];
int curDeg[1000001];

vector <int> graph[1000001];

set <pii> edges;

vector <pii> segTree;

int left(int n) { return n << 1; }
int right(int n) { return (n << 1) + 1; }

void update(int n, pii v, int l, int r, int i, int j)
{
	if (j < l || r < i) return;
	if (i <= l && r <= j)
	{
		segTree[n] = v;

		return;
	}
	update(left(n), v, l, (l + r) / 2, i, j);
	update(right(n), v, (l + r) / 2 + 1, r, i, j);

	segTree[n] = min(segTree[left(n)], segTree[right(n)]);
}

pii getMin(int n, int l, int r, int i, int j)
{
	if (j < l || r < i) return { 987654321,987654321 };
	if (i <= l && r <= j)
	{
		return segTree[n];
	}
	pii lSum = getMin(left(n), l, (l + r) / 2, i, j);
	pii rSum = getMin(right(n), (l + r) / 2 + 1, r, i, j);
	return min(lSum, rSum);
}


int main()
{
	scanf("%d%d", &n, &m);
	segTree.resize(n * 4);
	goal = (n + m + 1) / 2;
	for (int i = 0; i < m; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		edges.insert({ a,b });
		graph[a].push_back(b);
		graph[b].push_back(a);
		curDeg[a]++, orginDeg[a]++;
		curDeg[b]++, orginDeg[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		update(1, { curDeg[i],i }, 0, n - 1, i, i);
	}

	while (m > goal)
	{
		pii curMin = getMin(1, 0, n - 1, 1, n);

		int v = curMin.second;
		int d = curMin.first;

		if (d == 987654321) break;

		if (curDeg[v] - 1 < (d + 1) / 2)
		{
			update(1, { 987654321,v }, 0, n - 1, v, v);
			continue;
		}

		vector <pii> remains;
		for (int i = 0; i < graph[v].size(); i++)
		{
			int nv = graph[v][i];
			int maxErase = (orginDeg[nv]) / 2;
			int remainErase = maxErase - (orginDeg[nv] - curDeg[nv]);
			if (remainErase)
				remains.push_back({ remainErase,nv });
		}

		sort(remains.rbegin(), remains.rend());
		for (int i = 0; i < remains.size(); i++)
		{
			if (curDeg[v] - 1 < (orginDeg[v] + 1) / 2) break;

			int nv = remains[i].second;
			if (edges.find({ v,nv }) != edges.end()) edges.erase({ v,nv });
			else if (edges.find({ nv,v }) != edges.end()) edges.erase({ nv,v });
			else continue;

			curDeg[v]--; curDeg[nv]--;
			update(1, { curDeg[nv],nv }, 0, n - 1, nv, nv);
			m--;

			if (m <= goal) break;
		}

		update(1, { 987654321,v }, 0, n - 1, v, v);
	}

	printf("%d\n", edges.size());
	for (auto i = edges.begin(); i != edges.end(); i++)
		printf("%d %d\n", (*i).first, (*i).second);
}