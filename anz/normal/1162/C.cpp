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

int n, k;
bool a[100001];
bool l[100001];
bool r[100001];
int ans[100001];
int main()
{
	scanf("%d%d", &n, &k);
	if (n == 1) ans[1] = 1;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == 1 || i == n) ans[i] = 2;
			else ans[i] = 3;
		}
	}
	for (int i = 0; i < k; i++)
	{
		int t;
		scanf("%d", &t);
		if (!a[t])
		{
			a[t] = true;
			ans[t]--;
		}
		if (t != 1 && a[t - 1] && !l[t - 1])
		{
			l[t - 1] = true;
			ans[t - 1]--;
		}
		if (t != n && a[t + 1] && !r[t + 1])
		{
			r[t + 1] = true;
			ans[t + 1]--;
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) sum += ans[i];
	printf("%d", sum);
}