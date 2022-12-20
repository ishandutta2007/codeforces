#include <stdio.h>

int x[3],y[3];

int main()
{
	for(int i=0;i<3;i++) {
		scanf("%d %d",x+i,y+i);
	}
	printf("3\n");

	int cx=x[2] +(x[1]-x[0]);
	int cy=y[2]+(y[1]-y[0]);
	printf("%d %d\n", cx, cy);

	cx=x[2]+(x[0]-x[1]);
	cy=y[2]+(y[0]-y[1]);
	printf("%d %d\n", cx, cy);

	cx=x[0]+(x[1]-x[2]);
	cy=y[0]+(y[1]-y[2]);
	printf("%d %d\n",cx, cy);

	return 0;
}