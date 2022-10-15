#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1111111;

char a[MAXN];
int f[MAXN];
int n;
int ans = 0, k = 1;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s", a + 1);
	n = strlen(a + 1);

	a[0] = ')';
	for (int i = 1; i <= n; i++)
		if (a[i] == ')')
			if (a[i - f[i - 1] - 1] == '(')
			{
				f[i] = f[i - f[i - 1] - 2] + 2 + f[i - 1];
				if (f[i] > ans)
				{
					ans = f[i];
					k = 0;
				}
				k += f[i] == ans;
			}
	printf("%d %d\n", ans, k);
	return 0;
}