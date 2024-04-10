#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point
{
	int x, y;
	int index;
	
	point(int x = 0, int y = 0): x(x), y(y) {}
	
	point operator-(const point& p) const { return point(x - p.x, y - p.y); }
	
	bool operator<(const point& p) const
	{
		return x < p.x;
	}
	
	ll sql() const { return x * (ll)x + y * (ll)y; }
	ll sprod(const point& p) const { return x * (ll)p.x + y * (ll)p.y; }
	ll vprod(const point& p) const { return x * (ll)p.y - y * (ll)p.x; }
};

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<point> p(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].index = i + 1;
	}
	
	sort(p.begin(), p.end());
	
	sort(p.begin() + 1, p.end(), [&](point a, point b)
	{
		a = a - p[0];
		b = b - p[0];
		
		if (a.vprod(b) == 0)
			return a.sql() < b.sql();
		else
			return a.vprod(b) > 0;
	});
	
#if 0
	for (int i = 0; i < n; i++)
		printf("%d ", p[i].index);
	printf("\n");
#endif
	
	int i = 0, j = 1;
	int k = 2;
	for (; k < n; k++)
		if ((p[1] - p[0]).vprod(p[k] - p[0]) > 0)
			break;
	assert(k != n);
	
	i = p[i].index;
	j = p[j].index;
	k = p[k].index;
	
	printf("%d %d %d\n", i, j, k);
	
	return 0;
}