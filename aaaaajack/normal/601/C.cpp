#include<cstdio>
#include<cstring>
#define N 100100
double rk[2][N];
int main(){
	int n,m,p=0;
	double ans=0;
	scanf("%d%d",&n,&m);
	if(m==1) puts("1");
	else{
		rk[1][0]=1;
		int x,k=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			k+=x;
			memset(rk[p],0,sizeof(rk[p]));
			double sum=0;
			for(int j=i;j<=i*m;j++){
				sum+=rk[p^1][j-1];
				if(j>=m+1) sum-=rk[p^1][j-m-1];
				rk[p][j]=(sum-(j>=x?rk[p^1][j-x]:0))/(m-1);
			}
			p^=1;
		}
		for(int i=n;i<k;i++){
			ans+=rk[p^1][i];
		}
		printf("%.12f\n",1+ans*(m-1));
	}
	return 0;
}