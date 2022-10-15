#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 3000000;

int a[MAXN];
int l, r;
char s[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	gets(s);
	int l = MAXN / 2, r = MAXN / 2;
	a[l] = strlen(s);
	for (int i = (int)strlen(s) - 2; i >= 0; i--)
	{
		if (s[i] == 'l')
		{
			a[++r] = i + 1;
		}
		else
		{
			a[--l] = i + 1;
		}
	}
	for (int i = l; i <= r; i++)
		printf("%d\n", a[i]);
	return 0;
}