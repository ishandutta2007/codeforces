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

int n;
int a[200];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	bool flag = true;
	bool wasSquare = false;
	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == 1)
		{
			if (a[i + 1] == 2)
			{
				ans += 3;
				if (wasSquare) ans--;
			}
			else ans += 4;
		}
		else if (a[i] == 2)
		{
			if (a[i + 1] == 1)
			{
				ans += 3;
			}
			else flag = false;
			wasSquare = false;
		}
		else
		{
			if (a[i + 1] == 1) ans += 4;
			else flag = false;
			wasSquare = true;
		}

	}

	if (flag) printf("Finite\n%lld\n", ans);
	else printf("Infinite\n");
}