#include<stdio.h>
long long h[100010],p[100010],Res,B=0,E=20000000000LL,M,K;
int n,m,i,pv,o;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&h[i]);
	for(i=1;i<=m;i++)scanf("%lld",&p[i]);
	while(B<=E){
		M=(B+E+1)>>1;
		pv=1;
		for(i=1;i<=n;i++){
			if(p[pv]-h[i]>M)continue;
			if(h[i]-p[pv]>M)break;
			if(p[pv]>=h[i]){
				while(pv<=m && p[pv]-h[i]<=M)pv++;
			}
			else{
				K=h[i]-p[pv];
				while(pv<=m && p[pv]<=h[i])pv++;
				while(pv<=m && ( (p[pv]-h[i])*2LL+K <=M || p[pv]-h[i]+K*2LL <= M ))pv++;
			}
			if(pv==m+1)break;
		}
		if(pv!=m+1){
			B=M+1;
		}
		else{
			Res=M;
			E=M-1;
		}
	}
	printf("%lld\n",Res);
}