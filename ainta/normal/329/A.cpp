#include<stdio.h>
int n,i,j,X[110],Y[110];
char p[110][110];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",p[i]+1);
		for(j=1;j<=n;j++){
			if(p[i][j]!='E'){
				X[i]=j;
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(p[j][i]!='E')Y[i]=j;
	for(i=1;i<=n;i++){
		if(X[i]==0)break;
	}
	if(i==n+1){
		for(i=1;i<=n;i++)printf("%d %d\n",i,X[i]);
	}
	else{
		for(i=1;i<=n;i++){
			if(Y[i]==0)break;
		}
		if(i==n+1){
			for(i=1;i<=n;i++)printf("%d %d\n",Y[i],i);
		}
		else printf("-1\n");
	}
}