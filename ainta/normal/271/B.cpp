#include<stdio.h>
bool v[110001];
int n,m,i,p[100001],c,j,Next[100001],k,w[501][501],S,Res=999999999;
int main()
{
	p[c++]=2;
	for(i=3;i<110000;i+=2){
		if(v[i])continue;
		p[c++]=i;
		for(j=3*i;j<110000;j+=i<<1){
			v[j]=true;
		}
	}
	k=0;
	for(i=1;i<=100000;i++){
		while(p[k]<i)k++;
		Next[i]=p[k]-i;
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		S=0;
		for(j=1;j<=m;j++){
			scanf("%d",&w[i][j]);
			S+=Next[w[i][j]];
		}
		if(S<Res)Res=S;
	}
	for(i=1;i<=m;i++){
		S=0;
		for(j=1;j<=n;j++){
			S+=Next[w[j][i]];
		}
		if(S<Res)Res=S;
	}
	printf("%d\n",Res);
}