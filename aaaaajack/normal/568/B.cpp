#include<cstdio>
#define N 4010
#define Q 1000000007
int c[N][N];
long long eq[N][N],sum[N];
int cmb(int n,int m){
	if(n<m||m<0) return 0;
	if(n==m||m==0) return 1;
	if(c[n][m]) return c[n][m];
	c[n][m]=cmb(n-1,m)+cmb(n-1,m-1);
	if(c[n][m]>=Q) c[n][m]-=Q;
	return c[n][m];
}
int main(){
	int n;
	long long ans=0;
	eq[0][0]=1;
	sum[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			eq[i][j]+=1LL*eq[i-1][j]*j;
			eq[i][j+1]+=eq[i-1][j];
		}
		for(int j=1;j<=n;j++){
			eq[i][j]%=Q;
			sum[i]+=eq[i][j];
		}
		sum[i]%=Q;
	}
	for(int i=1;i<=n;i++){
		ans+=cmb(n,i)*sum[n-i];
		ans%=Q;
	}
	printf("%d\n",ans);
	return 0;
}