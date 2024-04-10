#include<cstdio>
#include<algorithm>
#define N 1010
#define M 1010
#define inf 1023456789
using namespace std;
int a[N][M],lt[N][M]={0},rt[N][M]={0},lb[N][M]={0},rb[N][M]={0};
int main(){
	int n,m,i,j,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			lt[i][j]=max(lt[i-1][j],lt[i][j-1])+a[i][j];
		}
	}
	for(i=n;i>=1;i--){
		for(j=1;j<=m;j++){
			lb[i][j]=max(lb[i+1][j],lb[i][j-1])+a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=m;j>=1;j--){
			rt[i][j]=max(rt[i-1][j],rt[i][j+1])+a[i][j];
		}
	}
	for(i=n;i>=1;i--){
		for(j=m;j>=1;j--){
			rb[i][j]=max(rb[i+1][j],rb[i][j+1])+a[i][j];
		}
	}
	for(i=2;i<=n-1;i++){
		for(j=2;j<=m-1;j++){
			ans=max(ans,
					max(lt[i-1][j]+rb[i+1][j]+lb[i][j-1]+rt[i][j+1],
						lt[i][j-1]+rb[i][j+1]+lb[i+1][j]+rt[i-1][j]
						)
					);
		}
	}
	printf("%d\n",ans);
	return 0;
}