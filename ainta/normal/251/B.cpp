#include<stdio.h>
int p[101],k,n,i,j,w[101],A[101][101],B[101][101],M[101];
bool ck=0,ck2=0;
int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		p[w[i]]=i;
	}
	for(i=1;i<=n;i++)scanf("%d",&M[i]);
	for(i=1;i<=n;i++)A[0][i]=B[0][i]=i;
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++)A[i][j]=A[i-1][w[j]];
		for(j=1;j<=n;j++)B[i][j]=B[i-1][p[j]];
	}
	for(i=1;i<=n;i++){
		if(M[i]!=i)ck=1;
		if(M[i]!=A[1][i]||M[i]!=B[1][i])ck2=1;}
	if(ck==0||(ck2==0&&k>1)){
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++){
			if(A[i][j]!=M[j])break;
		}
		if(j==n+1&&i%2==k%2)break;
		for(j=1;j<=n;j++){
			if(B[i][j]!=M[j])break;
		}
		if(j==n+1&&i%2==k%2)break;
	}
	if(i!=k+1){printf("YES\n");return 0;}
	printf("NO\n");
}