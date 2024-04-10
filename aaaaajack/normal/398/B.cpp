#include<cstdio>
#define N 2010
using namespace std;
double dp[N][N];
bool ux[N]={0},uy[N]={0};
int main(){
	int a,b,m,x,y,i,j;
	double n;
	scanf("%d%d",&a,&m);
	n=b=a;
	while(m--){
		scanf("%d%d",&x,&y);
		if(!ux[x]){
			ux[x]=true;
			a--;
		}
		if(!uy[y]){
			uy[y]=true;
			b--;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=a;i++){
		dp[i][0]=n/i+dp[i-1][0];
	}
	for(i=1;i<=b;i++){
		dp[0][i]=n/i+dp[0][i-1];
	}
	for(i=1;i<=a;i++){
		for(j=1;j<=n;j++){
			dp[i][j]=1/(1-(n-i)*(n-j)/n/n)*(1+j*(n-i)/n/n*dp[i][j-1]+i*(n-j)/n/n*dp[i-1][j]+i*j/n/n*dp[i-1][j-1]);
		}
	}
	printf("%.10f\n",dp[a][b]);
	return 0;
}