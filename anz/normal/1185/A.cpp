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
	ll rope[3];
	for (int i = 0; i < 3; i++) scanf("%lld", rope + i);
	sort(rope, rope + 3);

	ll d;
	scanf("%lld", &d);

	ll a1 = d - (rope[1] - rope[0]);
	ll a2 = d - (rope[2] - rope[1]);

	if (a1 < 0) a1 = 0;
	if (a2 < 0) a2 = 0;
	printf("%lld", a1 + a2);
}