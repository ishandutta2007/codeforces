#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

std::vector<int> arr[20];
int inp[1001];
int res[1001];
int n, k;
const int INF = 1000000000;
int xx;
bool chk[1001];

void f(int s, int g, int x)
{
	if(s>=g)
		return;
	int m = (s+g+1)/2, i;
	for(i = s; i<m; i++)
		arr[x].push_back(i);
	for(i = m; i<=g; i++)
		arr[x+1].push_back(i);
	xx = std::max(xx, x+1);
	f(s, m-1, x+2);
	f(m, g, x+2);
}

int main()
{
	int c = 0, i, j;
	scanf("%d", &n);

	for(i = 1; i<=n; i++)
		res[i] = INF;

	f(1, n, 0);
	for(i = 0; i<=xx; i++)
	{
		if(arr[i].empty())
			continue;
		c++;
		if(c==21)
			break;

		memset(chk, 0, sizeof(chk));
		printf("%d\n", arr[i].size());
		for(j = 0; j<arr[i].size(); j++)
		{
			printf("%d ", arr[i][j]);
			chk[arr[i][j]] = 1;
		}
		printf("\n");
		fflush(stdout);

		for(j = 1; j<=n; j++)
		{
			scanf("%d", &inp[j]);
			if(!chk[j])
				res[j] = std::min(res[j], inp[j]);
		}
	}

	printf("-1\n");
	for(i = 1; i<=n; i++)
		printf("%d ", res[i]);
	printf("\n");
	fflush(stdout);

	return 0;
}