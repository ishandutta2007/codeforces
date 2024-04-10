#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

int arr[501];
std::vector<int> mem[501];
int tmp[501];
int tmp2[501];
bool chk[501];

int main()
{
	int n, k, c, c2, i, j, l;
	scanf("%d%d", &n, &k);
	for(i = 1; i<=n; i++)
		scanf("%d", &arr[i]);

	mem[0].push_back(0);
	for(i = 1; i<=n; i++)
	{
		for(j = k; j>=1; j--)
		{
			c = 0;
			c2 = 0;
			for(int y : mem[j])
			{
				chk[y] = 1;
				tmp2[c2++] = y;
			}

			if(j-arr[i]>=0)
			{
				for(int y : mem[j-arr[i]])
				{
					if(!chk[y])
					{
						chk[y] = 1;
						tmp[c++] = y;
					}
					if(y+arr[i]<=k && !chk[y+arr[i]])
					{
						chk[y+arr[i]] = 1;
						tmp[c++] = y+arr[i];
					}
				}
			}
			for(l = 0; l<c; l++)
			{
				mem[j].push_back(tmp[l]);
				chk[tmp[l]] = 0;
			}
			for(l = 0; l<c2; l++)
				chk[tmp2[l]] = 0;
		}
	}

	std::sort(mem[k].begin(), mem[k].end());
	printf("%d\n", mem[k].size());
	for(int y : mem[k])
		printf("%d ", y);

	return 0;
}