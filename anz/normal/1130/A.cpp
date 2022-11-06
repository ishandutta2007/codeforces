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

int main()
{
	int n;
	int t;
	scanf("%d", &n);
	int pos = 0;
	int neg = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (t > 0) pos++;
		else if (t < 0) neg++;
	}

	if (pos >= (double)n / 2) printf("1");
	else if (neg >= (double)n / 2) printf("-1");
	else printf("0");
}