#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 2 * 1000007;

int n;
char a[MAXN], b[MAXN];
int f[4];

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	while (scanf("%d\n", &n) == 1)
	{
		gets(a);
		gets(b);
		
		
		memset(f, 0, sizeof(f));
		
		for (int i = 0; i < 2 * n; i++)
			f[(a[i] - '0') * 2 + (b[i] - '0')] += 1;
			
		int A, B;
		A = B = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			
			x = (f[3] || f[2])? (f[3]? 3 : 2) : (f[1]? 1 : 0);
			f[x] -= 1;
			A += x >> 1;
			
			x = (f[3] || f[1])? (f[3]? 3 : 1) : (f[2]? 2 : 0);
			f[x] -= 1;
			B += x & 1;
		}

		if (A == B)
			puts("Draw");
		else
			puts(A > B? "First" : "Second");
	}
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}