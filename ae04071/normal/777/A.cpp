#include <stdio.h>

int n,x;
int arr[6][3]={{1,2,3},{2,1,3},{2,3,1},{3,2,1},{3,1,2},{1,3,2}};
int main() {
	scanf("%d %d",&n,&x);
	n%=6;

	printf("%d\n",arr[n][x]-1);

	return 0;
}