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

const int N = 1000005;
int n, x;
int a[N];
int l[N], r[N];
int maxNum[N];

int main()
{
	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (l[a[i]] == -1) l[a[i]] = i;
		r[a[i]] = i;
		maxNum[i] = a[i];
		if (i) maxNum[i] = max(maxNum[i], maxNum[i - 1]);
	}

	int cRight = -1;
	int frontIndex = x;
	int cLeft = 1000009;
	int backIndex = 1;

	for (int i = 1; i <= x; i++)
	{
		if (l[i] == -1)
		{
			frontIndex = i;
			continue;
		}

		if (cRight > l[i]) break;
		else
		{
			cRight = r[i];
			frontIndex = i;
		}
	}

	for (int i = x; i >= 1; i--)
	{
		if (r[i] == -1)
		{
			backIndex = i;
			continue;
		}

		if (cLeft < r[i]) break;
		else
		{
			cLeft = l[i];
			backIndex = i;
		}
	}

	ll res = 0;
	int maxRight = -1;
	for (int i = 1; i <= frontIndex+1; i++)
	{
		int tmp = max(i, backIndex - 1);
		if (maxRight != -1) tmp = max(tmp, maxNum[maxRight]);
		res += x - tmp + 1;
		if (r[i] != -1) maxRight = max(maxRight, r[i]);
	}

	printf("%lld", res);
}