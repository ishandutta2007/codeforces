#include<bits/stdc++.h>
using namespace std;
const int N=509,P=998244353;
int f[N][N],pw[N][N],C[N][N];
int qp(int a,int b){
	int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r%P;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,x,i,j,k,dl;
	cin>>n>>x,f[n][0]=1;
	C[0][0]=1;
	for(i=1;i<N;++i){
		C[i][0]=1;
		for(j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
	for(i=0;i<N;++i)for(j=0;j<N;++j)pw[i][j]=qp(i,j); 
	for(i=0;i<=x;++i){
		for(j=2;j<=n;++j)if(f[j][i]){
			dl=min(j-1,x-i);
			for(k=0;k<=j;++k)f[j-k][i+dl]=(f[j-k][i+dl]+f[j][i]*1ll*
			pw[dl][k]%P*C[j][k])%P;
		}
	}j=0;
	for(i=0;i<=x;++i)j=(j+f[0][i])%P;cout<<j;
	return 0;
}