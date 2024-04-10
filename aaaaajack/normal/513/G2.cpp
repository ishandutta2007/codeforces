#include<cstdio>
#define N 32
#define K 210
using namespace std;
double dp[K][N][N];
int a[N];
int main(){
	int n,l,r,k,t,i,j,ni,nj;
	double ans=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]>a[j]) dp[0][i][j]=1;
		}
	}
	for(t=1;t<=k;t++){
		for(l=0;l<n;l++){
			for(r=l;r<n;r++){
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						if(i>=l&&i<=r) ni=r-(i-l);
						else ni=i;
						if(j>=l&&j<=r) nj=r-(j-l);
						else nj=j;
						dp[t][ni][nj]+=2.0/n/(n+1)*dp[t-1][i][j];
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			ans+=dp[k][i][j];
		}
	}
	printf("%.12f\n",ans);
	return 0;
}