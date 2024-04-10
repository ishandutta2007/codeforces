#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 20
#define M 20
#define C 26
using namespace std;
int sum[M][C],mx[M][C],con[M][C];
int a[N][M];
char s[N][M+10];
int dp[1<<N];
inline int upd(int &x,int y){
	if(x==-1||y<x) x=y;
}
int f(int p,int n,int m){
	if(p==0) return 0;
	if(dp[p]>=0) return dp[p];
	int u=__lg(p&-p);
	for(int i=0;i<m;i++){
		int j=s[u][i]-'a';
		upd(dp[p],sum[i][j]-mx[i][j]+f(p&(~con[i][j]),n,m));
		upd(dp[p],a[u][i]+f(p^(1<<u),n,m));
	}
	return dp[p];
}
int main(){
	int n,m,i,j,x;
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			con[j][s[i][j]-'a']|=1<<i;
			sum[j][s[i][j]-'a']+=a[i][j];
			if(a[i][j]>mx[j][s[i][j]-'a']) mx[j][s[i][j]-'a']=a[i][j];
		}
	}
	printf("%d\n",f((1<<n)-1,n,m));
	return 0;
}