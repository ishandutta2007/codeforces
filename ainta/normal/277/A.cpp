#include<stdio.h>
int n,m,i,j,w[201][201],INF=99999999,D[201],cm,x,M,S;
bool used[201],v[201];
int main(){
	int a,b,ck=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+m;i++)for(j=1;j<=n+m;j++)w[i][j]=INF;
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		for(j=1;j<=a;j++){
			scanf("%d",&b);
			w[n+b][i]=w[i][n+b]=0;
			used[b]=true;
		}
		if(a)ck=1;
	}
	if(!ck){
		printf("%d\n",n);
		return 0;
	}
	for(i=1;i<=m;i++){
		if(used[i]){
			for(j=1;j<=n;j++){
				if(w[j][n+i]!=0)w[j][n+i]=w[n+i][j]=1;
			}
			cm++;
		}
	}
	for(i=1;i<=n+m;i++)D[i]=INF;
	D[1]=0;
	for(i=1;i<=n+cm;i++){
		x=-1,M=INF;
		for(j=1;j<=n+m;j++)if(M>D[j]&&!v[j])x=j,M=D[j];
		if(x==-1)break;
		S+=D[x];
		v[x]=true;
		for(j=1;j<=n+m;j++){
			if(!v[j] && D[j]>w[x][j])D[j]=w[x][j];
		}
	}
	printf("%d\n",S);
}