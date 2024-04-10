/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,K,deg[210],res;
struct Matrix{
	int a[210][210];
	Matrix(){memset(a,0,sizeof(a));}
	friend Matrix operator*(const Matrix&u,const Matrix&v){
		Matrix w;
		for(int i=1;i<=(n<<1);i++)for(int j=1;j<=(n<<1);j++)for(int k=1;k<=(n<<1);k++)w.a[i][j]=(1ll*u.a[i][k]*v.a[k][j]+w.a[i][j])%mod;
		return w;
	}
}A,M,R;
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),deg[x]++,deg[y]++,A.a[x][y]=A.a[y][x]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)M.a[i+n][j+n]=A.a[i][j];
	// for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)printf("%d ",A.a[i][j]);
	for(int i=1;i<=n;i++)M.a[i+n][i]=1,M.a[i][i+n]=(mod-(deg[i]-1))%mod;
	// for(int i=1;i<=(n<<1);i++,puts(""))for(int j=1;j<=(n<<1);j++)printf("%d ",M.a[i][j]);
	for(int i=1;i<=(n<<1);i++)R.a[i][i]=1;
	for(K--;K;K>>=1,M=M*M)if(K&1)R=R*M;
	// for(int i=1;i<=(n<<1);i++,puts(""))for(int j=1;j<=(n<<1);j++)printf("%d ",R.a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)res=(1ll*A.a[i][j]*R.a[j][i]+res)%mod;
	// printf("%d\n",res);
	A=A*A;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)res=(1ll*A.a[i][j]*R.a[j+n][i]+res)%mod;
	printf("%d\n",res);
	return 0;
}