#include <cstdio>
#include <algorithm>
using namespace std;

int n, size, cnt_soft, cnt_hard;
char s[9];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%*s%s", s);
		cnt_soft += s[0] == 's';
		cnt_hard += s[0] == 'h';
	}
	if (cnt_soft > cnt_hard) swap(cnt_soft, cnt_hard);
	for (size = 1; (size * size + 1 >> 1) < cnt_hard || (size * size >> 1) < cnt_soft; size ++) ;
	printf("%d\n", size);
	return 0;
}