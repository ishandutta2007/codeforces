#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,num[101][101],x,y;
void ans(){
	int mn=9e18,mx=-1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)mx=max(mx,num[i][j]),mn=min(mn,num[i][j]);
	printf("%lld %lld %lld\n",mx,mn,num[x][y]);
	exit(0);
}
signed main(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y);
	if(n==1){
		printf("%lld %lld %lld\n",(k-1)/m+1,k/m,k/m+(k%m>=y));
		return 0;
	}
	for(int i=1;i<=m;i++)num[1][i]=num[n][i]=k/(m*(n*2-2));
	for(int i=2;i<n;i++)for(int j=1;j<=m;j++)num[i][j]=k/(m*(n*2-2))*2;
	k%=m*(n*2-2);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(!k)ans();
		num[i][j]++,k--;
	}
	for(int i=n-1;i>=2;i--)for(int j=1;j<=m;j++){
		if(!k)ans();
		num[i][j]++,k--;
	}
	return 0;
}