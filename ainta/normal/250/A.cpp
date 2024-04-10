#include<stdio.h>
int n,D[101],p[101],S[101],i,w[101],j,c;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		D[i]=999999999;
	}
	for(i=1;i<=n;i++){
		c=0;
		for(j=i;j>=1;j--){
			if(w[j]<0)c++;
			if(c>2)break;
		}
		D[i]=D[j]+1;p[i]=j;
	}
	printf("%d\n",D[n]);
	i=n;
	c=0;
	while(i){
		S[++c]=i-p[i];
		i=p[i];
	}
	for(i=c;i>=1;i--)printf("%d ",S[i]);
}