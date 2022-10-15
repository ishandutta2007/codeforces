#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <map>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

map <int, int> M;
int c[4];
int n, m;

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		M[x]++;
		M[y]++;
	}
	
	for (map <int, int> :: iterator iter = M.begin(); iter != M.end(); ++iter)
		c[min(iter->second, 3)] += 1;
	
	if (m == n)
	{
		puts(c[2] == n? "ring topology" : "unknown topology");
		return 0;
	}
	
	if (m == n - 1)
	{
		if (c[1] == n - 1) puts("star topology"); else
		if (c[1] == 2 && c[2] == n - 2) puts("bus topology"); else
			puts("unknown topology");
		return 0;
	}
	
	puts("unknown topology");
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}