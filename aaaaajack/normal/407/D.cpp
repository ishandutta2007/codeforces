#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[410][410],a[410][410],last_ap[410][160010]={0};
void chkmax(int &x,int y){
	if(x<y) x=y;
}
int main(){
	int n,m,l,i,j;
	int ans=0;
	memset(last_ap,-1,sizeof(last_ap));
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(l=0;l<m;l++){
			for(j=0;j+l<m;j++){
				if(l){
					if(a[i][j]==a[i][j+l]) dp[l][j]=i;
					else{
						chkmax(dp[l][j],dp[l-1][j]);
						chkmax(dp[l][j],dp[l-1][j+1]);
						chkmax(dp[l][j],last_ap[j][a[i][j+l]]);
						chkmax(dp[l][j],last_ap[j+l][a[i][j]]);
					}
				}
				else{
					chkmax(dp[l][j],last_ap[j][a[i][j]]);
				}
				chkmax(ans,(l+1)*(i-dp[l][j]));
			}
		}
		for(j=0;j<m;j++) last_ap[j][a[i][j]]=i;
	}
	printf("%d\n",ans);
	return 0;
}