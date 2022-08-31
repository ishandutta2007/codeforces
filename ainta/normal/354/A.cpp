#include<stdio.h>
int n,l,r,pl,pr,w[100010],S1,S2,Res;
int mm(int a,int b){return a<b?b:a;}
int main()
{
	int i,T;
	scanf("%d%d%d%d%d",&n,&l,&r,&pl,&pr);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		S2+=w[i];
	}
	for(i=0;i<=n;i++){
		T=pl*mm(i*2-n-1,0)+pr*mm(n-i*2-1,0);
		T+=S1*l+S2*r;
		if(i==0 || T<Res)Res=T;
		if(i==n)break;
		S1+=w[i],S2-=w[i];
	}
	printf("%d\n",Res);
}