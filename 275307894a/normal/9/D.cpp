#include<cstdio>
#include<iostream>
using namespace std;
int n,m,k;
long long f[39][39],ans;
int main(){
	register int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++) f[0][i]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=0;k<i;k++) f[i][j]+=f[k][j-1]*f[i-k-1][j-1];
		}
	}
	cout<<f[n][n]-f[n][m-1];
}