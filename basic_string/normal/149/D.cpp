#include<bits/stdc++.h>
using namespace std;
const int N=709,P=1e9+7;
int f[N][N][3][3],g[N];
char s[N];
int wk(int l,int r,int x,int y){
	if(l+1==r)return x?(y==0):(y>0); 
	if(~f[l][r][x][y])return f[l][r][x][y];
	int w=0,i,j,k;
	for(i=l;i<r;++i)if(g[i]==g[l-1]){
		for(j=0;j<3;++j)for(k=0;k<3;++k)if(j!=k||!j)w=(w+wk(l,i,x,j)*1ll*wk(i+1,r,k,y))%P;
		goto gg;
	}
	for(j=0;j<3;++j)for(k=0;k<3;++k)if((x!=j||!x)&&(y!=k||!y)&&(x?(y==0):(y>0)))w=(w+wk(l+1,r-1,j,k))%P;
	gg:;
	return f[l][r][x][y]=w;
}
int main(){
	int n,i,j,w=0;
	memset(f,-1,sizeof f),scanf("%s",s+1),n=strlen(s+1);
	for(i=1;i<=n;++i)if(s[i]=='(')g[i]=g[i-1]+1;else g[i]=g[i-1]-1;
	for(i=0;i<3;++i)for(j=0;j<3;++j)w=(w+wk(1,n,i,j))%P;
	printf("%d",w);
	return 0;
}