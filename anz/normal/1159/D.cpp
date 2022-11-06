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
	int k, n;
	scanf("%d%d", &n, &k);
	if (k == 1)
	{
		printf("1");
		for (int i = 1; i < n; i++) printf("0");
		return 0;
	}

	int num = (n - k) / 2;

	for (int i = 0; i < n; i++)
	{
		if (i % (num + 1) == 0) printf("1");
		else printf("0"); 
	}
}