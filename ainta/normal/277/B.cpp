#include<stdio.h>
int main()
{
	int n,m,i,j,c=0,t;
	scanf("%d%d",&n,&m);
	if(m==3){
		if(n==3){
			printf("0 0\n0 1\n1 0\n");
		}
		else if(n==4){
			printf("0 0\n0 3\n3 0\n1 1\n");
		}
		else printf("-1\n");
		return 0;
	}
	for(i=1;i<=m;i++){
		printf("%d %d\n",i,i*i);
	}
	j=0,i=10000;
	t=m*2-n;
	while(j<n-m){
		j++,t++;
		printf("%d %d\n",i,t*t);
		i--;
	}
	return 0;
}