#include <stdio.h>

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	n*=2;
	int tmp=2*m;

	k--;
	int a=(k%tmp)/2+1;
	int b=k/tmp+1;
	k++;
	char c=(k&1)?'L':'R';
	printf("%d %d %c\n",b,a,c);
	return 0;
}