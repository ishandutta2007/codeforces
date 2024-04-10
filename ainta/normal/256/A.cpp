#include<stdio.h>
int D[4001][4001],n,i,w[4001],p[4001][4001],j,R;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		p[i][i]=i;
		for(j=1;j<i;j++){
			if(w[j]==w[i])p[j][i]=i,p[i][j]=j;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(p[i][j]<p[i][j-1])p[i][j]=p[i][j-1];
		}
	}
	if(n==1){
		printf("1\n");
		return 0;
	}
	int t;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			D[i][j]=2;
			t=D[p[j][i-1]][i]+1;
			if(D[i][j]<t)D[i][j]=t;
			if(R<D[i][j])R=D[i][j];
		}
	}
	printf("%d\n",R);
}