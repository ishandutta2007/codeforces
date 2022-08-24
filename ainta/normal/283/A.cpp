#include<stdio.h>
double Sum;
int n,i,t,a,b,c,w[300001],o[300001];
int main()
{
	scanf("%d",&n);
	c=1;
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&a,&b);
			o[a]+=b;
			Sum+=(double)a*b;
		}
		if(t==2){
			scanf("%d",&a);
			Sum+=(double)a;
			w[++c]=a;
		}
		if(t==3){
			Sum-=(double)(w[c]+o[c]);
			o[c-1]+=o[c];
			w[c]=o[c]=0;
			c--;
		}
		printf("%.6lf\n",Sum/(double)c);
	}
}