#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2222;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,m,c[N*2][N*2],f[N][N],g[N][N];
int cal(int x,int y){
	return c[x+y][x];
}
int main(){
	int i,j,ans;
	n=4400;
	for(i=0;i<=n;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MO;
	}
	cin>>n>>m;
	ans=0;
	for(i=1;i<n;i++){
		for(j=1;j<=m;j++){
			f[i][j]=mul(cal(i,j-1),cal(i-1,m-j));
			g[i][j]=(g[i][j-1]+f[i][j])%MO;
		}
	}
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
			ad(ans,mul(g[i][j],f[n-i][m-j]));
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
			ad(ans,MO-mul(f[i][j],f[n-i][m-j]));
	swap(n,m);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(i=1;i<n;i++){
		for(j=1;j<=m;j++){
			f[i][j]=mul(cal(i,j-1),cal(i-1,m-j));
			g[i][j]=(g[i][j-1]+f[i][j])%MO;
		}
	}
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
			ad(ans,mul(g[i][j],f[n-i][m-j]));
	ans=mul(ans,2);
	cout<<ans;
	return 0;
}