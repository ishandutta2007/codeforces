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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		a = a%b;
		swap(a, b);
	}
	return a;
}

int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	if (a > b) swap(a, b);
	ll diff = b - a;
	
	ll smLCM = a * b / gcd(a, b);
	ll result = 0;
	for (ll i = 1; i*i <= diff; i++)
	{
		if (diff % i == 0)
		{
			ll div = i;
			ll tmp = (div - a % div) % div;
			if ((a + tmp)*(b + tmp) / div < smLCM)
			{
				smLCM = (a + tmp)*(b + tmp) / div;
				result = tmp;
			}

			div = diff / i;
			tmp = (div - a % div) % div;
			if ((a + tmp)*(b + tmp) / div < smLCM)
			{
				smLCM = (a + tmp)*(b + tmp) / div;
				result = tmp;
			}
		}
	}

	printf("%lld", result);
}