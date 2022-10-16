#include <bits/stdc++.h>
using namespace std;

const int N=100+5;
int n,m,k,p,f[N][N][N],fc[N],C[N][N];
int main(){
	cin>>n>>m>>k>>p,fc[0]=1;
	for(int i=0;i<N;i++)f[0][i][0]=1;
	for(int i=0;i<N;i++)for(int j=0;j<=i;j++)
		C[i][j]=j==0||j==i?1:(C[i-1][j-1]+C[i-1][j])%p;
	for(int i=1;i<N;i++)fc[i]=1ll*fc[i-1]*i%p;
	for(int i=1;i<=n;i++){
		f[i][1][1]=fc[i];
		for(int j=2;j<=i;j++)for(int pos=0;pos<i;pos++)
			for(int c=0;c<=i;c++)if(f[pos][j-1][c])
			for(int k=c;k<=i;k++)if(f[i-pos-1][j-1][k-c])
				f[i][j][k]=(f[i][j][k]+1ll*f[pos][j-1][c]*f[i-pos-1][j-1][k-c]%p*C[i-1][pos])%p;
		for(int j=2;j<N;j++){
			f[i][j][0]=fc[i];
			for(int k=1;k<=i;k++)f[i][j][0]=(f[i][j][0]-f[i][j][k]+p)%p;
		}
	}
	cout<<f[n][m][k]<<endl;
	return 0;
}