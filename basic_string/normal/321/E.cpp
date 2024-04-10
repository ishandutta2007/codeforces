#include<bits/stdc++.h>
using namespace std;
enum{N=4009,M=809};
int w[N][N],f[M][N],p[M][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k,l,r;
	char c;
	cin>>n>>m,memset(f,9,sizeof f),f[0][0]=0;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(cin>>c,i<j)w[i][j]=c-'0';
	for(i=n;i;--i)for(j=i+2;j<=n;++j)w[i][j]+=w[i+1][j]+w[i][j-1]-w[i+1][j-1];
	for(i=1;i<=m;++i)for(j=n;j;--j){
		l=p[i-1][j],r=min(j==n?N:p[i][j+1],j-1);
		for(k=l;k<=r;++k)if(f[i-1][k]+w[k+1][j]<f[i][j])f[i][j]=f[i-1][k]+w[k+1][j],p[i][j]=k;
	}
	cout<<f[m][n];
}