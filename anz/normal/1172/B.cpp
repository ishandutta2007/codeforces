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
const ll MOD = 998244353;
vector <int> graph[200001];
int cache[200001];
ll ans = 1;

ll fact(ll n)
{
	ll res = 1;
	for (ll i = 1; i <= n; i++)
	{
		res *= i;
		res %= MOD;
	}
	return res;
}

void DFS(int start)
{
	cache[start] = 1;
	ll num = 0;
	if (start != 1) num++;
	vector <int> tmp;
	for (int i = 0; i < graph[start].size(); i++)
	{
		if (cache[graph[start][i]] == 0)
		{
			num++;
			tmp.push_back(graph[start][i]);
		}
	}

	ans *= fact(num);
	ans %= MOD;

	for (int i = 0; i < tmp.size(); i++)
		DFS(tmp[i]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	DFS(1);

	ans *= n;
	ans %= MOD;

	printf("%lld", ans);
}