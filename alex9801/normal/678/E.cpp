#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

double arr[19][19];
double mem[19][140000];
bool chk[19][140000];
int n;

double f(int h, unsigned int b)
{
	if(!chk[h][b])
	{
		chk[h][b] = 1;
		if(!b)
			mem[h][b] = arr[1][h];
		else
		{
			int i;
			unsigned int t;
			for(i = 0; i<n-1; i++)
			{
				if(b&(1<<i))
				{
					t = b^(1<<i);
					mem[h][b] = std::max(mem[h][b], arr[h][i+2]*f(h, t) + arr[i+2][h]*f(i+2, t));
				}
			}
		}
	}
	return mem[h][b];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
	{
		arr[i][0] = 1.0;
		for(j = 1; j<=n; j++)
			scanf("%lf", &arr[i][j]);
	}

	if(n==1)
	{
		printf("1.0");
		return 0;
	}

	printf("%.10lf", f(0, (1<<(n-1))-1));
	return 0;
}