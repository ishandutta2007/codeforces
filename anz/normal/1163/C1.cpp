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
	int a, b; // a/b
	void norm()
	{
		if (b == 0)
		{
			a = 1;
			return;
		}

		if (b < 0)
			a = -a, b = -b;
		int g = gcd(a, b);
		a /= g, b /= g;
		if (a == 0) b = 1;
	}

	bool operator<(const fraction& f) const
	{
		int left = a*f.b;
		int right = b*f.a;
		return left < right;
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
		else
		{
			pnt.a = d.b*y[i] - d.a*x[i];
			pnt.b = d.b;
			pnt.norm();
		}

		lines.insert({ d, pnt });
	}

	int ans = 0;
	for (auto i = lines.begin(); i != lines.end(); i++)
	{
		auto j = i;
		j++;
		for (; j != lines.end(); j++)
		{
			fraction f1,f2;
			f1 = (*i).first, f2 = (*j).first;
			if (f1.a != f2.a || f1.b != f2.b) ans++;
		}
	}

	printf("%d", ans);

}