#include <stdio.h>

int matrix[200][200];

int
main(void)
{
 	int n, m, i, j, x, y;
	scanf("%d %d", &n, &m);
	matrix[100][100] = n;
	while(42)
	{
	 	bool done = true;
	 	for(i = 0; i < 200; i++)
			  for(j = 0; j < 200; j++)
			  		if(matrix[i][j] >= 4)
					{
					 	x = matrix[i][j] / 4;
					 	matrix[i][j] %= 4;
						matrix[i+1][j] += x;
						matrix[i][j+1] += x;
						matrix[i-1][j] += x;
						matrix[i][j-1] += x;
						done = false;
					}
		if(done) break;
	}
	for(i = 0; i < m; i++)
	{
	 	 scanf("%d %d",&x, &y);
		 if(x >= 100 || y >= 100 || x <= -100 || y <= -100)
		 	  printf("0\n");
		else
			printf("%d\n", matrix[x+100][y+100]);
	}
	return 0;
}