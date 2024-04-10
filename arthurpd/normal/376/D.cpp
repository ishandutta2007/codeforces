#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

char matrix[5123][5123];
int r[5123][5123];
int a[5123];

void linear_sort(int a[], int n, int mx)
{
	int count[mx+20];
	memset(count, 0, sizeof(count));
	for(int i = 0; i < n; i++)
		count[a[i]]++;

	int c = 0;
	for(int i = mx+10; i >= 0; i--)
		while(count[i] > 0)
		{
			a[c++] = i;
			count[i]--;
		}
}

int
main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf(" %s", matrix[i]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			matrix[i][j] -= '0';
	
	for(int i = 0; i < n; i++)
		for(int j = m-1; j >= 0; j--)
			if(matrix[i][j] == 0)
				r[i][j] = 0;
			else
				r[i][j] = r[i][j+1] + 1;
	
	int ans = 0;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			a[j] = r[j][i];
		linear_sort(a, n, m);
		for(int i = 0; i < n && a[i] > 0; i++)
			ans = max((i+1)*a[i], ans);
	}
	printf("%d\n", ans);
}