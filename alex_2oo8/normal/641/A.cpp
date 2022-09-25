#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define MAXN 100005

using namespace std;

int main ()
{
	int N;
	scanf("%d",&N);
	static char s[MAXN];
	scanf("\n%s",s);
	static int a[MAXN];
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d",&a[i]);
	}
	static char b[MAXN];
	memset(b,0,sizeof(b));
	int pos = 0;
	while (!b[pos])
	{
		b[pos] = 1;
		if (s[pos] == '<') pos -= a[pos];
		else pos += a[pos];
		if ((pos < 0) || (pos >= N))
		{
			printf("FINITE\n");
			return 0;
		}
	}
	printf("INFINITE\n");
	return 0;
}