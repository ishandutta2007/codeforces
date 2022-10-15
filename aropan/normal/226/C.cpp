#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

long long L, R, M, K;
long long l, r;


long long e[2][2], d[2][2];

void multi(long long a[2][2], long long b[2][2])
{
	long long c[2][2];
	memset(c, 0, sizeof(c));
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				(c[i][j] += a[i][k] * b[k][j]) %= M;
				
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = c[i][j];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	cin >> M >> L >> R >> K;
	long long l, r, c, p, x;
	x = (R - L + 1) / (K - 1);
	//cout << "\t" << x << endl;
	do
	{
		p = (L - 1) / ((L - 1) / x + 1);
		//cout << "\t" << p << endl;
		l = p, r = x;
		
		while (l < r)
		{
			c = (l + r + 1) / 2;
			if (R / c - (L - 1) / c >= K)
				l = c;
			else
				r = c - 1;
		}
		x = p;
	} while (l == p);

	long long n = l - 1;
/*	
	while (R / c - (L - 1) / c < K) c--;
	long long n = c - 1;
//*/	
	d[0][0] = 1;
	d[0][1] = 1;
	d[1][0] = 1;
	d[1][1] = 0;
	e[0][0] = 1;
	e[0][1] = 0;
	e[1][0] = 0;
	e[1][1] = 1;
	
	
	while (n)
	{
		if (n & 1)
			multi(e, d);
		if (n >>= 1)
			multi(d, d);
	}
	cout << e[0][0] % M << endl;

	return 0;
}