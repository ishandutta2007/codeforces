#include <bits/stdc++.h>

using namespace std;

int a[55][55];

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
		
	vector<int> p(n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < n; j++)
		{
			int order = 0;
			for (int k = 0; k < n; k++)
				if (a[j][k] == i)
					order++;
				
			//printf("%d order = %d\n", j, order);
				
			if (order == n - i && !p[j])
			{
				p[j] = i;
				break;
			}
		}
		
	for (int x: p) printf("%d ", x);
	printf("\n");
	
	return 0;
}