#include<bits/stdc++.h>
#define N 5010
#define M 100100
using namespace std;
int dp[N][N];
int tmp[N];
int lm7[7][N];
int a[N];
int lst[M];
void upd(int &x,int y){
	if(y>x){
		x=y;
	}
}
int main(){
	int n,x,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			tmp[j]=0;
			upd(tmp[j],dp[lst[a[i]-1]][j]+1);
			upd(tmp[j],dp[lst[a[i]+1]][j]+1);
			upd(tmp[j],lm7[a[i]%7][j]+1);
			upd(tmp[j],dp[0][j]+1);
			upd(ans,tmp[j]);
		}
		for(int j=0;j<i;j++){
			upd(lm7[a[i]%7][j],tmp[j]);
			upd(dp[lst[a[i]]][j],tmp[j]);
			if(j) upd(lm7[a[j]%7][i],tmp[j]);
			upd(dp[lst[a[j]]][i],tmp[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}