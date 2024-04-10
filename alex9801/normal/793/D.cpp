#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

struct edg
{
	int y, c;
	edg(int y = 0, int c = 0) :y(y), c(c) {}
	bool operator <(const edg &a) const
	{
		return y < a.y;
	}
};

std::vector<edg> arr1[85];
std::vector<edg> arr2[85];

int mem[85][85][85];
const int INF = 1000000;

int main()
{
	int n, k, mm, x, y, c, t, r, i, j, l, m;
	scanf("%d%d%d", &n, &k, &mm);
	for(i = 0; i<mm; i++)
	{
		scanf("%d%d%d", &x, &y, &c);
		if(y < x)
			arr1[x].push_back(edg(y, c));
		else if(x < y)
			arr2[x].push_back(edg(y, c));
	}

	for(i = 1; i<=n; i++)
	{
		std::sort(arr1[i].begin(), arr1[i].end());
		std::sort(arr2[i].begin(), arr2[i].end());
	}

	for(l = 1; l<=k; l++)
		for(i = 1; i<=n; i++)
			for(j = 1; j<=n; j++)
				mem[l][i][j] = INF;

	for(l = 1; l<k; l++)
	{
		for(i = 1; i<=n; i++)
		{
			for(j = i-1; j>=1; j--)
			{
				for(m = arr1[i].size()-1; m>=0; m--)
				{
					t = arr1[i][m].y;
					if(t < j)
						break;
					c = arr1[i][m].c;
					mem[l][i][j] = std::min({mem[l][i][j], mem[l-1][t][j] + c, mem[l-1][t][i-1] + c});
				}
			}

			for(j = i+1; j<=n; j++)
			{
				for(m = 0; m<arr2[i].size(); m++)
				{
					t = arr2[i][m].y;
					if(t > j)
						break;
					c = arr2[i][m].c;
					mem[l][i][j] = std::min({mem[l][i][j], mem[l-1][t][j] + c, mem[l-1][t][i+1] + c});
				}
			}
		}
	}

	r = INF;
	for(i = 1; i<=n; i++)
		for(j = 1; j<=n; j++)
			r = std::min(r, mem[k-1][i][j]);

	if(r == INF)
		printf("-1");
	else
		printf("%d", r);

	return 0;
}