#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T gcd(T a, T b) { return b == 0? a : gcd(b, a % b); }
template <typename T> T abs(T x) { return x < 0? -x : x; }


const int MAXL = 10000007;
const int MAXN = 2000006;

int n, r, c, l;
char s[MAXL];
int a[MAXN];
int f[MAXN];
int g[MAXN];
int b[MAXN];

int main()
{
	#ifdef MJUDGE
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout));
	#endif
	scanf("%d %d %d\n", &n, &r, &c);
	gets(s);
	l = strlen(s);
	n = 0;
	{
		int st;
		for (int i = 0; i < l; i++)
		{
			if (i == 0 || s[i - 1] == ' ') st = i;
			if (i + 1 == l || s[i + 1] == ' ')
			{
				b[n] = st;
				a[n] = i - st + 1;
				n++;
			}
		}
	}
	b[n] = l + 1;
/*	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
//*/	
	
	int length = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		if (j <= i)
		{
			j = i;
			length = 0;
		}
		
		while (j < n && length + (int)(i < j) + a[j] <= c)
		{
			length += (int)(i < j) + a[j];
			j += 1;
		}
		f[i] = j - i;
		length -= a[i] + (int)(i + 1 < j);
	}
	
	int m = r;
	while (m)
	{
		if (m & 1)
		{
			for (int i = 0; i < n; i++)
				g[i] = f[i] + g[i + f[i]];
		}
		
		if (m /= 2)
		{
			for (int i = 0; i < n; i++)
				f[i] = f[i] + f[i + f[i]];
		}
	}
/*	
	for (int i = 0; i < n; i++)
		printf("%d ", g[i]);
	cout << endl;
//*/		
	int x = 0;
	for (int i = 0; i < n; i++)
		if (g[i] > g[x])
			x = i;
			
	char *p = s + b[x];
	for (int i = 0; i < r && x < n; i++)
	{
		int length = 0;
		for (int j = 0; x < n && length + a[x] + (int)(j > 0) <= c; j++, x++)
			length += a[x] + (int)(j > 0);
		s[b[x] - 1] = '\n';
	}
	s[b[x] - 1] = 0;
	puts(p);
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}