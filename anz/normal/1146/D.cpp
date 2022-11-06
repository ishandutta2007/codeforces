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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b)
{
	while (a)
	{
		int tmp = b%a;
		b = a;
		a = tmp;
	}
	return b;
}

int dist[200007]; // d_i
ll sum[200007]; 

int main()
{
	int m, a, b;
	scanf("%d%d%d", &m, &a, &b);
	int n = min(m, a + b - 1);
	for (int i = 0; i <= n; i++)
		dist[i] = n + 1;

	set <pii> s; // x, d_i
	s.insert({ 0, 0 });
	dist[0] = 0;
	while (!s.empty())
	{
		pii tmp = *s.begin();
		s.erase(s.begin());
		if (dist[tmp.second] != tmp.first) //  ?
			continue;
		sum[tmp.first]++; // d_i tmp.first   

		//b~a+b    0~a+b . (dp)
		if (tmp.second >= b && tmp.first < dist[tmp.second - b])
		{
			dist[tmp.second - b] = tmp.first;
			s.insert({ tmp.first, tmp.second - b });
		}
		if (tmp.second + a <= n && max(tmp.first, tmp.second + a) < dist[tmp.second + a])
		{
			dist[tmp.second + a] = max(tmp.first, tmp.second + a);
			s.insert({ max(tmp.first, tmp.second + a), tmp.second + a });
		}
	}

	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i > 0)
			sum[i] += sum[i - 1];
		ans += sum[i];
	}
	// 0~n  .

	// m ...
	ll g = (ll)gcd(a, b);
	if (m > n)
	{
		ll tmp = m;
		while ((tmp + 1) % g) tmp--;

		ans += ((ll)m - tmp)*((ll)m / g + 1);
		ans += ((((ll)tmp / g + 1)*((ll)tmp / g + 2) / 2) - (((ll)n / g + 1)*((ll)n / g + 2) / 2)) * g;
	}


	printf("%lld", ans);
}