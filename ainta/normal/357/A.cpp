#include<stdio.h>
int n,w[110],i,S,ss,x,y;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		S+=w[i];
	}
	scanf("%d%d",&x,&y);
	for(i=1;i<=n;i++){
		if(ss>=x && S-ss>=x && ss<=y && S-ss<=y)break;
		ss+=w[i];
	}
	if(i==n+1)printf("0\n");
	else printf("%d\n",i);
}