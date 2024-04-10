#include<stdio.h>
int n,D[5001][5001],i,j,w[5001],S[5001],k;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		S[i]=S[i-1]+w[i];}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)D[i][j]=999999999;
	D[1][1]=0;
	for(i=2;i<=n;i++){
		k=i-1;
		for(j=i;j>=1;j--){
			if(S[i]-S[j-1]<w[j-1])continue;
			if(k>j-1)k=j-1;
			while(k>=1&&S[j-1]-S[k-1]<=S[i]-S[j-1])k--;
			D[i][j]=D[j-1][k+1]+(i-j);
			if(D[i][j]>D[i][j+1]&&j!=n)D[i][j]=D[i][j+1];
		}
	}
	printf("%d\n",D[n][1]);
}