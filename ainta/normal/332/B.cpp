#include<stdio.h>
int w[200001],a,b;
long long D[200001],M,R;
int main(){
	int n,k,i,bb;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&w[i]);
	for(i=1;i<=k;i++)D[1]+=w[i];
	for(i=k+1;i<=n;i++){
		D[i-k+1]=D[i-k]-w[i-k]+w[i];
	}
	for(i=n-2*k+1;i>=1;i--){
		if(M<=D[i+k])M=D[i+k],b=i+k;
		if(R<=M+D[i])R=M+D[i],a=i,bb=b;
	}
	printf("%d %d\n",a,bb);
}