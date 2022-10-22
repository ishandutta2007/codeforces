#include <bits/stdc++.h>
#define N 509
using namespace std;
int n,m,g[N][2],nxt[N];
int dp[N][N],f[N][N];
char s1[N],s2[N];
int main(){
	cin>>n>>m;
	int k=n-m+1;
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int j=0;
	for(int i=2;i<=m;++i){
		while(j&&s2[j+1]!=s2[i])j=nxt[j];
		if(s2[i]==s2[j+1])j++;
		nxt[i]=j;
	}
	for(int i=0;i<m;++i){
		for(int j='0';j<='1';++j){
			int x=i;
			while(x&&s2[x+1]!=j)x=nxt[x];
			if(s2[x+1]==j)g[i][j-'0']=x+1;
		}
	//	cout<<g[i][0]<<" "<<g[i][1]<<endl; 
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		memset(f,0x3f,sizeof(f));
		for(int j=0;j<m;++j)
			for(int k=0;k<=n;++k)if(dp[j][k]<1e7){
				if(g[j][0]==m)f[nxt[j+1]][k+1]=min(f[nxt[j+1]][k+1],dp[j][k]+(s1[i]!='0'));
				else f[g[j][0]][k]=min(f[g[j][0]][k],dp[j][k]+(s1[i]!='0'));
				if(g[j][1]==m)f[nxt[j+1]][k+1]=min(f[nxt[j+1]][k+1],dp[j][k]+(s1[i]!='1'));
				else f[g[j][1]][k]=min(f[g[j][1]][k],dp[j][k]+(s1[i]!='1'));
			}
		for(int j=0;j<m;++j)
		    for(int k=0;k<=n;++k)dp[j][k]=f[j][k];
	}
	for(int i=0;i<=k;++i){
		int ans=1e9;
		for(int j=0;j<m;++j)ans=min(ans,dp[j][i]);
		if(ans<1e7)printf("%d ",ans);
		else printf("-1 ");
	}
	return 0; 
}

/*%4=0
0110
1001 */ 
//0110 1001 1001