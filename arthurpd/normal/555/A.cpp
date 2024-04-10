#include <stdio.h>
#include <vector>
using namespace std;

int p[112345];
int f[112345];

vector<int> mat[112345];

int
main()
{
	int n, m, k, a, ans = 0;
	scanf("%d %d", &n, &m);
	int x = m;

	for(int i = 0; i < m; i++)
	{
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &a);
			mat[i].push_back(a);
		}
		if(mat[i][0] == 1)
		{
			int tmp = 1;
			for(int j = 1; j < k; j++)
				if(mat[i][j] == mat[i][j-1] + 1)
					tmp++;
				else
					break;

			ans += k - tmp;
			x += (k - tmp);
		}
		else
		{
			ans += (k - 1);
			x += (k-1);
		}
	}
	ans += (x - 1);
	printf("%d\n", ans);
	return 0;
}