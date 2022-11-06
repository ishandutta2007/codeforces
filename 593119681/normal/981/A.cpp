#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50 + 5

int len, ans;
char s[N];

bool Check(int u, int v)
{
	for (int i = 0; i <= v - u; i ++)
		if (s[u + i] != s[v - i]) return 0;
	return 1;
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i ++)
		for (int j = i + 1; j < len; j ++)
			if (!Check(i, j)) ans = max(ans, j - i + 1);
	printf("%d\n", ans);
	return 0;
}