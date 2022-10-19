#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,K,N;
struct Matrix{
int a[210][210];
Matrix(){memset(a,0,sizeof(a));}
int*operator[](const int&x){return a[x];}
friend Matrix operator*(Matrix&u,Matrix&v){
	Matrix w;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)w[i][j]=(1ll*u[i][k]*v[k][j]+w[i][j])%mod;
	return w;
}
}M;
int KSM(){
	Matrix R;
	for(int i=0;i<N;i++)R[i][i]=1;
	for(;n;n>>=1,M=M*M)if(n&1)R=R*M;
	int res=0;
	for(int j=0;j<(1<<m);j++)(res+=R[0][(K<<m)|j])%=mod;
	return res;
}
int main(){
	scanf("%d%d%d",&n,&K,&m),N=(K+1)<<m;
	for(int i=0;i<=K;i++)for(int j=0;j<(1<<m);j++){
		M[i<<m|j][(i<<m)|((j<<1)&((1<<m)-1))]=1;
		if(i==K)continue;
		M[i<<m|j][((i+1)<<m)|((j<<1)&((1<<m)-1))|1]=__builtin_popcount(j)+1;
	}
	printf("%d\n",KSM());
	return 0;
}