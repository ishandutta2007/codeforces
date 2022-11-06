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
#include <unordered_map>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	int n, h, m;
	scanf("%d%d%d", &n, &h, &m);
	int l[51], r[51], x[51];
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &l[i], &r[i], &x[i]);

	int prise[51];
	for (int i = 0; i < n; i++) prise[i] = h;
	for (int i = 0; i < m; i++)
	{
		for (int j = l[i]; j <= r[i]; j++)
			prise[j - 1] = min(prise[j - 1], x[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) ans += prise[i] * prise[i];
	printf("%d", ans);
}