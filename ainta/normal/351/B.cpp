#include<stdio.h>
int n,i,j,w[3010],inv;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		for(j=0;j<i;j++)if(w[j]>w[i])inv++;
	}
	if(inv&1)printf("%lf\n",(double)inv*2-1.0);
	else printf("%lf\n",(double)inv*2);
}