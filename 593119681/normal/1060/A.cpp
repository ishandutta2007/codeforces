#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, cnt;
char s[N];

int main()
{
	scanf("%*d%s", s);
	for (n = 0; s[n]; n ++)
		if (s[n] == '8') cnt ++;
	printf("%d\n", min(cnt, n / 11));
	return 0;
}