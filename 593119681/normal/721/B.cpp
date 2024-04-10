#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, k, ans_1, ans_2, Len[N];
char s[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", s);
		Len[i] = strlen(s);
		for (int j = 0; j < Len[i]; j ++)
			s[j] = '\0';
	}
	sort(Len + 1, Len + n + 1);
	scanf("%s", s);
	Len[n + 1] = strlen(s);
	for (int i = 1, j = 0; i <= n; i ++)
	{
		ans_1 ++;
		if (Len[i] == Len[n + 1]) break ;
		if (++ j == k) j = 0, ans_1 += 5;
	}
	for (int i = 1, j = 0; i <= n; i ++)
	{
		ans_2 ++;
		if (i == n || Len[i] == Len[n + 1] && Len[i + 1] > Len[n + 1]) break ;
		if (++ j == k) j = 0, ans_2 += 5;
	}
	printf("%d %d\n", ans_1, ans_2);
	return 0;
}