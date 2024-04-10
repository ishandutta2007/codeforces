#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, cnt;
char s[N];

int main()
{
	scanf("%d%s", &n, s);
	for (int i = 1; i < n; i ++)
		if (s[i] != s[i - 1])
			cnt ++, i ++;
	printf("%d\n", n - cnt);
	return 0;
}