#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, m, Max;
const char let[9] = "ATCG";
char s[N], t[N], ans[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		scanf("%s", s + i * m);
	for (int a = 0; a < 4; a ++)
		for (int b = 0; b < 4; b ++)
			if (a != b)
			{
				char x1 = let[a], x2 = let[b], y1, y2;
				for (int c = 0; c < 4; c ++)
					if (c != a && c != b)
					{
						y1 = let[c];
						break ;
					}
				for (int c = 3; c >= 0; c --)
					if (c != a && c != b)
					{
						y2 = let[c];
						break ;
					}
				int tot_r = 0, tot_c = 0;
				for (int i = 0; i < n; i ++)
				{
					char z0 = (i % 2 == 0 ? x1 : y1);
					char z1 = (i % 2 == 0 ? x2 : y2);
					int cnt_0 = 0, cnt_1 = 0;
					for (int j = 0; j < m; j ++)
					{
						if ((j % 2 == 0 && s[i * m + j] == z0) || (j % 2 == 1 && s[i * m + j] == z1))
							cnt_0 ++;
						if ((j % 2 == 0 && s[i * m + j] == z1) || (j % 2 == 1 && s[i * m + j] == z0))
							cnt_1 ++;
					}
					if (cnt_0 >= cnt_1)
					{
						tot_r += cnt_0;
						for (int j = 0; j < m; j ++)
							t[i * m + j] = j % 2 == 0 ? z0 : z1;
					}
					else
					{
						tot_r += cnt_1;
						for (int j = 0; j < m; j ++)
							t[i * m + j] = j % 2 == 0 ? z1 : z0;
					}
				}
				if (tot_r > Max)
				{
					for (int i = 0; i < n * m; i ++)
						ans[i] = t[i];
					Max = tot_r;
				}
				for (int j = 0; j < m; j ++)
				{
					char z0 = (j % 2 == 0 ? x1 : y1);
					char z1 = (j % 2 == 0 ? x2 : y2);
					int cnt_0 = 0, cnt_1 = 0;
					for (int i = 0; i < n; i ++)
					{
						if ((i % 2 == 0 && s[i * m + j] == z0) || (i % 2 == 1 && s[i * m + j] == z1))
							cnt_0 ++;
						if ((i % 2 == 0 && s[i * m + j] == z1) || (i % 2 == 1 && s[i * m + j] == z0))
							cnt_1 ++;
					}
					if (cnt_0 >= cnt_1)
					{
						tot_c += cnt_0;
						for (int i = 0; i < n; i ++)
							t[i * m + j] = i % 2 == 0 ? z0 : z1;
					}
					else
					{
						tot_c += cnt_1;
						for (int i = 0; i < n; i ++)
							t[i * m + j] = i % 2 == 0 ? z1 : z0;
					}
				} 
				if (tot_c > Max)
				{
					for (int i = 0; i < n * m; i ++)
						ans[i] = t[i];
					Max = tot_c;
				}
				//fprintf(stderr, "%c %c %c %c : %d\n", x1, x2, y1, y2, max(tot_r, tot_c));
			}
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
			putchar(ans[i * m + j]);
		putchar('\n');
	}
	return 0;
}