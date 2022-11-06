#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, len, Sum[N], Op[10], q[11];
char s[N], Ans[N];

int main()
{
	for (scanf("%d", &n); n; n --)
	{
		scanf("%s", s);
		len = strlen(s);
		for (int i = 0; i < len; i ++)
			Sum[i] = (i ? Sum[i - 1] : 0) + (s[i] != '0');
		if ((Sum[len - 1] == 2 && s[0] == '1' && s[len - 1] == '1') || (Sum[len - 1] == 1 && s[0] == '1'))
			for (int i = 1; i < len - 1; i ++) putchar('9');
		else
		{
			bool lim = 1;
			int cnt = 0;
			for (int i = 0; i < 10; i ++) Op[i] = 0;
			for (int i = 0; i < len; i ++)
			{
				for (int j = lim ? s[i] - '0' : 9; ~j; j --)
				{
					Op[j] ^= 1, cnt += (Op[j] ? 1 : -1);
					if (i + cnt >= len)
					{
						Op[j] ^= 1, cnt += (Op[j] ? 1 : -1);
						continue ;
					}
					else if (!lim || j < s[i] - '0' || Sum[len - 1 - cnt] - Sum[i] > 0)
					{
						lim &= (j == s[i] - '0');
						Ans[i] = j + '0';
						break ;
					}
					else
					{
						q[0] = 0;
						for (int k = 0; k < 10; k ++)
							if (Op[k]) q[++ q[0]] = k;
						int res = 0;
						for (int k = len - cnt, t = 1; !res && k < len; k ++, t ++)
						{
							if (s[k] - '0' > q[t]) res = 1;
							if (s[k] - '0' < q[t]) res = -1;
						}
						if (!~res || (!res && lim))
						{
							Op[j] ^= 1, cnt += (Op[j] ? 1 : -1);
							continue ;
						}
						else
						{
							lim &= (j == s[i] - '0');
							Ans[i] = j + '0';
							break ;
						}
					}
				}
				printf("%c", Ans[i]);
			}
		}
		puts("");
	}
	return 0;
}