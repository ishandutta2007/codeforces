#include<stdio.h>
int n,l,t,a,b,i,w[2000001],c;
double Res,aa,bb,nn;
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	a=(2*t)/l,b=(2*t)%l;
	aa=a,bb=b,nn=n;
	Res+=aa*nn*(nn-1)*2;
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	c=1;
	for(i=0;i<n;i++)w[i+n]=w[i]+l;
	for(i=0;i<n;i++){
		while(c<2*n &&w[c]<=w[i]+b)c++;
		Res+=(c-1-i);
	}
	c=2*n-2;
	for(i=2*n-1;i>=n;i--){
		while(c>=0 &&w[c]>=w[i]-b)c--;
		Res+=(i-1-c);
	}
	printf("%.10lf\n",Res/8.0);
}