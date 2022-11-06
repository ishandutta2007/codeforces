#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

struct que
{
	int a, t, x, p;
	que(int aa = 0, int at = 0, int ax = 0, int ap = 0) :a(aa), t(at), x(ax), p(ap) {}
	bool operator <(const que &y) const
	{
		return x!=y.x ? x<y.x : p<y.p;
	}
};

struct str
{
	int r, t;
	str(int ar = 0, int at = 0) :r(ar), t(at) {}
	bool operator <(const str &y) const
	{
		return t<y.t;
	}
};

que sor[100010];
int idx[400010];
std::vector<int> com;
std::vector<str> res;
int b;

void add(int x, int y, int v)
{
	x += b;
	y += b;

	while(x<y)
	{
		if(x%2==1)
		{
			idx[x] += v;
			x++;
		}
		if(y%2==0)
		{
			idx[y] += v;
			y--;
		}
		x /= 2;
		y /= 2;
	}
	if(x==y)
		idx[x] += v;
}

int get(int x)
{
	int r = 0;

	x += b;
	while(x)
	{
		r += idx[x];
		x /= 2;
	}
	return r;
}

int adr(int x)
{
	return std::lower_bound(com.begin(), com.end(), x)-com.begin();
}

int main()
{
	int n, s = 0, m, i, j;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
	{
		scanf("%d%d%d", &sor[i].a, &sor[i].t, &sor[i].x);
		sor[i].p = i;
	}

	std::sort(sor, sor+n);

	for(b = 1; b<n; b *= 2);

	for(i = 0; i<n; i++)
	{
		if(i!=n-1 && sor[i].x==sor[i+1].x)
			continue;

		m = sor[s].t;

		com.clear();
		for(j = s; j<=i; j++)
		{
			com.push_back(sor[j].t);
			m = std::max(m, sor[j].t);
		}

		std::sort(com.begin(), com.end());
		com.erase(std::unique(com.begin(), com.end()), com.end());

		m = adr(m);

		for(j = s; j<=i; j++)
		{
			if(sor[j].a == 1)
				add(adr(sor[j].t), m, 1);
			else if(sor[j].a == 2)
				add(adr(sor[j].t), m, -1);
			else
				res.push_back(str(get(adr(sor[j].t)), sor[j].p));
		}
		for(j = s; j<=i; j++)
		{
			if(sor[j].a == 1)
				add(adr(sor[j].t), m, -1);
			else if(sor[j].a == 2)
				add(adr(sor[j].t), m, 1);
		}

		s = i+1;
	}

	std::sort(res.begin(), res.end());
	for(i = 0; i<res.size(); i++)
		printf("%d\n", res[i].r);
}