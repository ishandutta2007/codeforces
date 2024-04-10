#include <cstdio>
const int MAX = 1000005;
int a[MAX], ans[MAX], pos[MAX];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		pos[a[i]] = a[i];
	}
	int t = 1;
	for (int i = 1; i < MAX; i++)
		if (pos[i])
		{
			if (t < i)
				t = i;
			while (t < i + pos[i] && t < MAX)
			{
				ans[t] = t - i;
				t++;
			}
			if (i + pos[i] < MAX && !pos[i + pos[i]])
				pos[i + pos[i]] = pos[i];
		}
	int res = 0;
	for (int i = 0; i < n; i++)
		if (res < ans[a[i]])
			res = ans[a[i]];
	printf("%d\n", res);
	return 0;
}