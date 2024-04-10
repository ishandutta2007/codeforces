#include<stdio.h>
int n,m,w[5001],D[5001],i,j,R;
double a;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		scanf("%lf",&a);
	}
	for(i=1;i<=n;i++)
	{
		D[i]=1;
		for(j=1;j<i;j++)
		{
			if(w[j]<=w[i]&&D[i]<D[j]+1)D[i]=D[j]+1;
		}
		if(R<D[i])R=D[i];
	}
	printf("%d\n",n-R);
}