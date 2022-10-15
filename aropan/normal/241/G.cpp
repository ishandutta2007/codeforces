#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 302;

long long x[MAXN];
long double r[MAXN];

template <typename T> T sqr(T x) { return x * x; }


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	x[0] = 0;
	x[MAXN - 1] = 1000000;

	r[MAXN - 1] = 1000000;
	r[0] = (long long)(sqr(x[MAXN - 1] - x[0]) / (4 * r[MAXN - 1]) + 2 + 1 - 1e-9);

	for (int i = 1; i < MAXN - 1; i++)
	{
		long long L = x[i - 1];
		long long R = x[MAXN - 1];
		while (L < R)
		{
			long long C = (L + R + 1) / 2;
			if (sqr(C - x[i - 1]) * (4 * r[MAXN - 1]) * 3+ 1e-9 < sqr(x[MAXN - 1] - C) * (4 * r[i - 1]))
			{
				L = C;
			}
			else
			{
				R = C - 1;
			}
		}
		
		do
		{
			x[i] = L;
			r[i] = sqr(L - x[i - 1]) / (long double)(4 * r[i - 1]);
			L--;
		}
		while (r[i] + 1e-9 >= r[i - 1]);
	}
	printf("%d\n", MAXN);
	for (int i = 0; i < MAXN; i++)
		cout << x[i] << " " << (int)(i == MAXN - 1? r[MAXN - 1] : r[0]) << endl;
/*
	for (int i = 0; i < MAXN; i++)
	{
		r[i] =  (i == MAXN - 1? r[MAXN - 1] : r[0]);
		for (int j = 0; j < i; j++)
		{
			if (i - j > 301)
				continue;
			r[i] = min(r[i], sqr(x[i] - x[j]) / (4 * r[j]));
		}
		cout.precision(10);
		cout << fixed << r[i] << endl;
	}
//*/
	return 0;
}