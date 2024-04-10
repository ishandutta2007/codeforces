#include<stdio.h>
int main()
{
	int n,m,R,i,c;
	scanf("%d%d",&n,&m);
	if(n<m){
		R=n+1;
		printf("%d\n",R);
		c=0;
		for(i=m;i>=m-n;i--){
			printf("%d %d\n",c,i);
			c++;
		}
	}
	else{
		R=m+1;
		printf("%d\n",R);
		c=0;
		for(i=n;i>=n-m;i--){
			printf("%d %d\n",i,c);
			c++;
		}
	}
	return 0;
}