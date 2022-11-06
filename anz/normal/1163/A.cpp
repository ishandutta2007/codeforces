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
#include <climits>
#include <cmath>

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
	int n, m;
	scanf("%d%d", &n, &m);
	if (m == 0) printf("1");
	else if (m > n / 2)
	{
		printf("%d", n - m);
	}
	else
	{
		printf("%d", m);
	}
}