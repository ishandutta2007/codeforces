#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}
int uf_par[1000001];
int uf_lev[1000001];
int uf_num[1000001];

int uf_find(int n)
{
	if (uf_par[n] == n) return n;

	int new_par = uf_find(uf_par[n]);
	uf_par[n] = new_par;
	uf_num[n] = uf_num[new_par];
	return new_par;
}

int uf_union(int a, int b)
{
	int pa = uf_find(a);
	int pb = uf_find(b);

	if (pa == pb)
	{
		return uf_num[a] = uf_num[b] = uf_num[pa];
	}

	if (uf_lev[pa] > uf_lev[pb])
		uf_par[pb] = pa;
	else if (uf_lev[pa] < uf_lev[pb])
		uf_par[pa] = pb;
	else
		uf_par[pa] = b, uf_lev[pb]++;

	int sum = uf_num[pa] + uf_num[pb];
	return uf_num[pa] = uf_num[pb] = uf_num[a] = uf_num[b] = sum;
}

int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) uf_par[i] = i, uf_num[i] = 1;
	for (int i = 0; i < m; i++)
	{
		int k, g, tmp;
		scanf("%d", &k);
		if (k == 0) continue;
		scanf("%d", &g);
		for (int j = 0; j < k - 1; j++)
		{
			scanf("%d", &tmp);
			uf_union(g, tmp);
		}
	}

	for (int i = 1; i <= n; i++)
		uf_find(i), printf("%d ", uf_num[i]);
}