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
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		for (; b; a %= b, swap(a, b));
		return a;
	}
	return a;
}

int n, z;
int x[200001];
int main()
{
	scanf("%d%d", &n, &z);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	sort(x, x + n);
	int l = 0, r = n / 2 + 1;
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		bool flag = true;
		for (int i = 0; i < mid; i++)
		{
			if (x[n - mid + i] - x[i] < z)
			{
				flag = false;
				break;
			}
		}
		if (flag) l = mid;
		else r = mid;
	}
	printf("%d", l);
}