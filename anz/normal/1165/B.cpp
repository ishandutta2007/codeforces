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

int n, t;
int a[200001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > ans) ans++;
	}
	printf("%d", ans);
}