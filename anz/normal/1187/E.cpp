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

int n;
vector <int> graph[200001];
vector <int> child[200001];

ll all_child[200001];
ll ans[200001];
ll res = 0;

int cache[200001];
int DFS1(int start)
{
	ll res = 1;
	cache[start] = 1;
	for (int i = 0; i < graph[start].size(); i++)
	{
		if (cache[graph[start][i]]) continue;
		child[start].push_back(graph[start][i]);
		res += DFS1(graph[start][i]);
		ans[start] += ans[graph[start][i]];
	}

	ans[start] += res;
	return all_child[start] = res;
}

void DFS2(int start)
{
	res = max(res, ans[start]);
	for (int i = 0; i < child[start].size(); i++)
	{
		int c = child[start][i];

		ans[start] -= ans[c];
		ans[start] -= all_child[c];
		all_child[start] -= all_child[c];
		all_child[c] += all_child[start];
		ans[c] += all_child[start];
		ans[c] += ans[start];

		DFS2(c);

		ans[c] -= ans[start];
		ans[c] -= all_child[start];
		all_child[c] -= all_child[start];
		all_child[start] += all_child[c];
		ans[start] += all_child[c];
		ans[start] += ans[c];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS1(1);
	DFS2(1);

	printf("%lld", res);
}