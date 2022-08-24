#include<stdio.h>
int n,w[1001],i,j,m,a,b,t;
double P[1001][1001],R,t1,t2;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(w[i]>w[j])P[i][j]=1;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(a>b)t=a,a=b,b=t;
		P[a][b]=0.5;
		for(j=1;j<a;j++){
			P[j][a]=P[j][b]=(P[j][a]+P[j][b])/2.0;}
		for(j=b+1;j<=n;j++){
			P[a][j]=P[b][j]=(P[a][j]+P[b][j])/2.0;}
		for(j=a+1;j<=b-1;j++){
			t1=P[a][j],t2=P[j][b];
			P[a][j]=(1.0-t2+t1)/2.0;
			P[j][b]=(t2+1.0-t1)/2.0;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			R+=P[i][j];
		}
	}
	printf("%lf\n",R);
}