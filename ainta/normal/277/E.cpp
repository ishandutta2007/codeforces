#include<stdio.h>
#include<math.h>
int n,i,j,sink;
struct A{
	int x,y;
}w[401];
int F[1001][1001],p[1001];
double Cost[1001][1001],INF=1e9,D[1001],M,Res;
bool v[1001];
double dist(double a,double b){
	return sqrt(a*a+b*b);
}
int main()
{
	scanf("%d",&n);
	sink=n*2+1;
	for(i=1;i<=n;i++){
		scanf("%d%d",&w[i].x,&w[i].y);
		F[0][i]=1,F[n+i][sink]=2;
	}
	for(i=1;i<=n;i++)for(j=n+1;j<=n*2;j++)Cost[i][j]=INF;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(w[i].y<w[j].y){
				F[i][n+j]=1;
				Cost[i][n+j]=dist(w[i].x-w[j].x,w[i].y-w[j].y);
			}
		}
	}
	int Rflow=n-1,x,b,e;
	while(Rflow--){
		for(i=0;i<=sink;i++)D[i]=INF,v[i]=false;
		D[0]=0;
		while(1){
			M=INF,x=-1;
			for(i=0;i<=sink;i++)if(!v[i]&&M>D[i])M=D[i],x=i;
			if(x==-1)break;
			v[x]=true;
			if(x==sink)break;
			b=1,e=n;
			if(x<=n && x)b+=n,e+=n;
			if(x>n && F[x][sink] && D[sink]>D[x]+Cost[x][sink])D[sink]=D[x]+Cost[x][sink],p[sink]=x;
			for(i=b;i<=e;i++){
				if(F[x][i] && D[x]+Cost[x][i]<D[i])D[i]=D[x]+Cost[x][i],p[i]=x;
			}
		}
		if(!v[sink]){
			printf("-1\n");
			return 0;
		}
		x=sink;
		Res+=D[sink];
		while(x){
			F[p[x]][x]--,F[x][p[x]]++;
			Cost[x][p[x]]=-Cost[p[x]][x],Cost[p[x]][x]=0;
			x=p[x];
		}
	}
	printf("%.10lf\n",Res);
}