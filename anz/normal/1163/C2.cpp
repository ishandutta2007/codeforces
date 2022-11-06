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

struct fraction
{
	ll a, b; // a/b
	void norm()
	{
		if (b == 0)
		{
			a = 1;
			return;
		}
		else if (a == 0)
		{
			b = 1;
			return;
		}

		if (b < 0)
			a = -a, b = -b;
		ll g = gcd(abs(a), abs(b));
		a /= g, b /= g;
	}

	bool operator<(const fraction& f) const
	{
		ll left = a*f.b;
		ll right = b*f.a;
		return left < right;
	}

	bool operator==(const fraction& f) const
	{
		return a == f.a && b == f.b;
	}

	bool operator!=(const fraction& f) const
	{
		return !operator==(f);
	}
};

int n;
int x[1001], y[1001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);

	set <pair<fraction, fraction> > lines;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
	{
		fraction d;
		d.a = y[j] - y[i];
		d.b = x[j] - x[i];
		d.norm();
		
		fraction pnt;
		if (d.b == 0) pnt.a = x[i], pnt.b = 1;
		else if (d.a == 0) pnt.a = y[i], pnt.b = 1;
		else
		{
			pnt.a = d.b*y[i] - d.a*x[i];
			pnt.b = d.b;
			pnt.norm();
		}

		lines.insert({ d, pnt });
	}

	ll ans = 0;
	
	vector<fraction> d;
	for (auto i = lines.begin(); i != lines.end(); i++)
		d.push_back((*i).first);

	for (int i = 0; i < d.size() - 1; i++)
	{
		ans += d.size() - 1 - i;

		auto right = upper_bound(d.begin() + i, d.end(), d[i]);
		
		ll tmp = right - (d.begin()+i) - 1;
		ans -= tmp;
	}

	printf("%lld", ans);

}