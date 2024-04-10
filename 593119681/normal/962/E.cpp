#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n;
LL ans;

struct Point
{
	int x, t;
	Point () {}
	Point(int _x, char c) : x(_x)
	{
		t = (c == 'P' ? 0 : (c == 'R' ? 1 : 2));
	}
}P[N];

LL Calc(int st, int ed)
{
	if (!st && ed > n)
	{
		LL res = 0;
		for (int x = 1; x <= 2; x ++)
		{
			int Min = 0, Max = 0;
			for (int i = 1; i <= n; i ++)
				if (P[i].t == x)
					Min = !Min ? i : Min, Max = i;
			if (Max) res += P[Max].x - P[Min].x;
		}
		return res;
	}
	if (!st)
	{
		LL res = 0;
		for (int i = ed - 1, last_1 = ed, last_2 = ed; i > st; i --)
		{
			if (P[i].t == 1)
				res += P[last_1].x - P[i].x, last_1 = i;
			else res += P[last_2].x - P[i].x, last_2 = i; 
		}
		return res;
	}
	if (ed > n)
	{
		LL res = 0;
		for (int i = st + 1, last_1 = st, last_2 = st; i < ed; i ++)
		{
			if (P[i].t == 1)
				res += P[i].x - P[last_1].x, last_1 = i;
			else res += P[i].x - P[last_2].x, last_2 = i; 
		}
		return res;
	}
	bool f_1 = 0, f_2 = 0;
	for (int i = st + 1; i < ed; i ++)
		if (P[i].t == 1) f_1 = 1;
			else f_2 = 1;
	if (!f_1 && !f_2)
		return P[ed].x - P[st].x;
	else if (!f_1 || !f_2)
	{
		LL res = 2LL * (P[ed].x - P[st].x), Max = 0;
		for (int i = st; i < ed; i ++)
			Max = max(Max, (LL) P[i + 1].x - P[i].x);
		return res - Max;
	}
	else
	{
		LL res_1 = 2LL * (P[ed].x - P[st].x);
		LL res_2 = 3LL * (P[ed].x - P[st].x);
		for (int x = 1; x <= 2; x ++)
		{
			LL Max = 0;
			for (int i = st + 1, last = st; i <= ed; i ++)
				if (P[i].t != x) Max = max(Max, (LL) P[i].x - P[last].x), last = i;
			res_2 -= Max;
		}
		return min(res_1, res_2);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++)
	{
		char c[9];
		scanf("%d%s", &x, c);
		P[i] = Point(x, c[0]);
	}
	for (int i = 1, last = 0; i <= n + 1; i ++)
		if (i > n || P[i].t == 0)
			ans += Calc(last, i), last = i;
	printf("%lld\n", ans);
	return 0;
}