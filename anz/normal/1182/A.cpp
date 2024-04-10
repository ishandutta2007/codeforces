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
	int n;
	scanf("%d", &n);
	if (n % 2)
		printf("0");
	else
	{
		ll ans = 1;
		for (int i = 0; i < n / 2; i++)
			ans *= 2;
		printf("%lld", ans);
	}
}