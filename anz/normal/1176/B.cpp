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

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int div[3] = { 0,0,0 };
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			div[a % 3]++;
		}
		int ans = div[0];
		int tmp = min(div[1], div[2]);
		ans += tmp;
		div[1] -= tmp, div[2] -= tmp;
		ans += div[1] / 3;
		ans += div[2] / 3;
		printf("%d\n", ans);
	}
}