#include<stdio.h>
int n;
int main()
{
	int i,R=0;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		R++;
		R+=(n-i)*i;
	}
	R++;
	printf("%d\n",R);
}