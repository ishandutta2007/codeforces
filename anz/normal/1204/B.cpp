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
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

ll n, l, r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> l >> r;
	ll minAns = 0, maxAns = 0;
	
	ll mul = 2;
	for (int i = 0; i < n; i++)
	{
		if (i+1 < l)
		{
			minAns += mul;
			mul *= 2;
		}
		else
			minAns++;
	}

	mul = 1;
	ll cur = 0;
	for (int i = 0; i < n; i++)
	{
		maxAns += mul;
		if (++cur < r) mul *= 2;
	}

	cout << minAns << ' ' << maxAns;
}