#include <stdio.h>
#include <vector>
using namespace std;

vector<int> dx;
vector<int> dy;
char g[112][112];
char r[112][112];
char ans[112][112];
int tab[112][112];


int
main(void)
{
	int n, count = 0, ok = 1;
	scanf("%d", &n);
	for(int i = 0; i < n;  i++)
		for(int j = 0; j < n; (g[i][j] == 'o' ? count++ : 0), j++)
			scanf(" %c", &g[i][j]);

	for(int k = 0; k < n; k++)
		for(int l = 0; l < n; l++)
			if(g[k][l] == 'o')
			{
				for(int i = 0; i < n; i++)
					for(int j = 0; j < n; j++)
						if(g[i][j] == 'x'|| g[i][j] == 'o')
							tab[n+i-k][n+j-l]++;
				for(int i = 0; i < 2*n; i++)
					for(int j = 0; j < 2*n; j++)
						if((k + i - n < 0 || k + i - n >= n) || (l + j - n < 0 || l + j - n >= n))
							tab[i][j]++;
			}
//	printf("%d\n", count);

	for(int i = 0; i < 2*n; i++)
		for(int j = 0; j < 2*n; j++)
			if(tab[i][j] == count)
			{
				ans[i][j] = 'x';
				dx.push_back(i-n), dy.push_back(j-n);
			}
			else
			{
				ans[i][j] = '.';
			}
	
	ans[n][n] = 'o';
	for(int k = 0; k < n; k++)
		for(int l = 0; l < n; l++)
			if(g[k][l] == 'o')
				for(int i = 0; i < dx.size(); i++)
					if(k + dx[i] >= 0 && l + dy[i] >= 0)
						r[k + dx[i]][l + dy[i]] = 'x';
						
	
	for(int i = 0; i < n;  i++)
		for(int j = 0; j < n; j++)
/*			if(r[i][j])
				printf("%c", r[i][j]);
			else
				printf(".");*/
			if((r[i][j] == 'x' || g[i][j] == 'x') && (r[i][j] == 0 || g[i][j] == '.'))
				ok = 0;
	if(!ok)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i = 1; i < 2*n; printf("\n"), i++)
		for(int j = 1; j < 2*n; j++)
			printf("%c", ans[i][j]);
}