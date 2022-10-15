#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 1003;

char a[MAXN], b[MAXN];

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	gets(a);
	gets(b);
	
	int n = 0;
	for (int i = 0; a[i]; i++)
		n += a[i] == '1';
	int m = 0;
	for (int i = 0; b[i]; i++)
		m += b[i] == '1';
	if (n & 1)
		n += 1;
	puts(n >= m? "YES" : "NO");
	return 0;
}