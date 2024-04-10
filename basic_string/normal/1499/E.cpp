#include<bits/stdc++.h>
using namespace std;
const int N=1009,P=998244353;
char x[N],y[N];
int f[N][N][2],g[N];
void upd(int&x,int y){if(x+=y,x>=P)x-=P;}
int main(){
	int n,m,i,j,s=0;
	scanf("%s%s",x+1,y+1),n=strlen(x+1),m=strlen(y+1);
	for(i=1;i<=n;++i)for(j=0;j<m;++j)f[i][j][0]=1;
	for(i=0;i<n;++i)for(j=1;j<=m;++j)f[i][j][1]=1;
	for(i=0;i<=n;++i)for(j=0;j<=m;++j){
		if(i<n){
			if(x[i+1]!=x[i])upd(f[i+1][j][0],f[i][j][0]);
			if(x[i+1]!=y[j])upd(f[i+1][j][0],f[i][j][1]);
		}
		if(j<m){
			if(y[j+1]!=x[i])upd(f[i][j+1][1],f[i][j][0]);
			if(y[j+1]!=y[j])upd(f[i][j+1][1],f[i][j][1]);
		}
		upd(s,f[i][j][0]),upd(s,f[i][j][1]);
	}
	for(i=1;i<=n;++i)g[i]=1;
	for(i=1;i<=n;++i){
		if(i<n&&x[i]!=x[i+1])g[i+1]=(g[i+1]+g[i])%P;
		s=(s-g[i]*1ll*m)%P;
	}
	for(i=1;i<=m;++i)g[i]=1;
	for(i=1;i<=m;++i){
		if(i<m&&y[i]!=y[i+1])g[i+1]=(g[i+1]+g[i])%P;
		s=(s-g[i]*1ll*n)%P;
	}
	printf("%d",(s+P)%P);
	return 0;
}