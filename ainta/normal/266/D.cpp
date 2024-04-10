#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,a,b,c,w[201][201],INF=999999999,o[20001][3];
bool v[201];
struct A{
	int a,b;
	bool operator <(const A &p)const{
		return a<p.a;
	}
}D[201];
int R;
void Do(int a,int b,int c){
	int i,M=0,t;
	for(i=1;i<=n;i++)D[i].a=w[a][i],D[i].b=w[b][i];
	sort(D+1,D+n+1);
	for(i=n;i>=1;i--){
		if(D[i].a-M<c&&M-D[i].a<c)t=M+D[i].a+c;
		else t=max(M,D[i].a)*2;
		if(R>t)R=t;
		if(M<D[i].b)M=D[i].b;
	}
}
int main()
{
	int i,j,k;
	R=INF;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)w[i][j]=INF;
		w[i][i]=0;}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		w[a][b]=w[b][a]=c;
		o[i][0]=a,o[i][1]=b,o[i][2]=c;
	}
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(w[i][j]>w[i][k]+w[k][j])w[i][j]=w[i][k]+w[k][j];
	for(i=0;i<m;i++){
		Do(o[i][0],o[i][1],o[i][2]);
	}
	if(R&1)printf("%d.5\n",R/2);
	else printf("%d\n",R/2);
}