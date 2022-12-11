#include<bits/stdc++.h>
using namespace std;
int n,m;
double dp[1001][1001],a[5][5];
double mdfs(int x,int y){
	if(x<0||y<0)return 0;
	if(y==0)return dp[x][y]=1;
	if(x==0)return dp[x][y]=1.0/(y+1);
	if(dp[x][y]>=0)return dp[x][y];
	double na=(1-mdfs(y-1,x)),nb=mdfs(y,x-1);
	double px=nb*1.0/(nb+1.0/(y+1));if((y*na+1)*1.0/(y+1)<1-nb)px=0;
	double py=(nb*(y+1)+y*(na-1))*1.0/(nb*(y+1)+1);if(nb*(y+1)+y*(na-1)<0)py=0;
	dp[x][y]=px*py*(y*na*1.0/(y+1))+px*(1-py)*((y*na+1)*1.0/(y+1))+(1-px)*(1-py)*(1-nb)+(1-px)*py;
	return dp[x][y];
}
signed main(){
//	freopen("late.in","r",stdin);
	cin>>n>>m;
	for(int i=0;i<=max(n,m);i++)for(int j=0;j<=max(n,m);j++)dp[i][j]=-1;
	dp[0][0]=1;mdfs(n,m);
	printf("%.9f %.9f\n",dp[n][m],1-dp[n][m]);
	return 0;
}
/*

*/