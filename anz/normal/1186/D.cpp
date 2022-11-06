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

int n;

int a[100000];
bool hasMinus[100000];

int main()
{
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		double d; scanf("%lf", &d);
		int f = floor(d), c = ceil(d);

		a[i] = c;
		sum += c;
		if (f != c) hasMinus[i] = true;
	}

	for (int i = 0; i < n; i++)
	{
		if (sum > 0 && hasMinus[i])
		{
			sum--;
			printf("%d\n", a[i] - 1);
		}
		else printf("%d\n", a[i]);
	}
}