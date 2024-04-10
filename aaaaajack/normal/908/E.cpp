#include<bits/stdc++.h>
#define Q 1000000007
using namespace std;
bool gg[2000];
int sz[2000],par[2000];
char s[100][2000];
int dp[2000][2000];
int C(int n,int m){
	if(n<m||m<0) return 0;
	if(n==0||n==m) return 1;
	if(dp[n][m]) return dp[n][m];
	if(n-m<m) return dp[n][m]=C(n,n-m);
	return dp[n][m]=(C(n-1,m-1)+C(n-1,m))%Q;
}
int main(){
	int m,n,r=1;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	par[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<i;j++){
			par[i]=(par[i]+1LL*par[j]*C(i-1,j)%Q)%Q;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<i;j++){
			if(gg[j]) continue;
			gg[i]=true;
			for(int k=0;k<n;k++){
				if(s[k][j]!=s[k][i]){
					gg[i]=false;
					break;
				}
			}
			if(gg[i]){
				sz[j]++;
				break;
			}				
		}
		if(!gg[i]) sz[i]=1;
	}
	for(int i=0;i<m;i++){
		if(!gg[i]) r=1LL*r*par[sz[i]]%Q;
	}
	printf("%d\n",r);
	return 0;
}