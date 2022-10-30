#include<cstdio>
#include<algorithm>
#define N 320
#define M 100100
#define eps 1e-6
using namespace std;
double p[M],dp[N][N];
double cmb(int n,int m){
	if(n<m||m<0) return 0;
	if(n==m||m==0) return 1;
	if(dp[n][m]>eps) return dp[n][m];
	return dp[n][m]=cmb(n-1,m)+cmb(n-1,m-1);
}
int main(){
	double ans=0;
	int i,j,n,m,k,l;
	scanf("%d%d%d",&n,&m,&k);
	p[0]=1;
	for(i=1;i<=k;i++){
		p[i]=p[i-1]*(k-i+1)/(m-i+1);
	}
	for(i=0;i<=2*n;i++){
		for(j=max(i-n,0);j<=min(n,i);j++){
			ans+=p[i*n-j*(i-j)]*cmb(n,j)*cmb(n,i-j);
			if(ans>1e99) break;
		}
		if(ans>1e99) break;
	}
	if(ans>1e99) printf("1e99\n");
	else printf("%.12g\n",ans);
	return 0;
}