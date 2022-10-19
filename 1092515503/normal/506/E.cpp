#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=10007;
int n,m,f[210][210][210],g[210];
char s[210];
int dfs(int l,int r,int k){
	if(k<0)return 0;
	if(l>=r)return k==0;
	int&res=f[l][r][k];if(res!=-1)return res;res=0;
	if(s[l]!=s[r])res=dfs(l+1,r,k-1)+dfs(l,r-1,k-1);else res=dfs(l+1,r-1,k);
	return res%=mod;
}
int sfd(int l,int r,int k){
	if(k<0)return 0;
	int&res=f[l][r][k];if(res!=-1)return res;res=0;
	if(l==r)return 0;if(l>r)return !k;
	if(s[l]!=s[r])res=sfd(l+1,r,k-1)+sfd(l,r-1,k-1);else res=sfd(l+1,r-1,k);
	return res%=mod;
}
int c;
struct Matrix{
	int a[310][310];
	int*operator[](const int&x){return a[x];}
	Matrix(){memset(a,0,sizeof(a));}
	friend Matrix operator*(Matrix&u,Matrix&v){
		Matrix w;
		for(int i=1;i<=c;i++)for(int j=i;j<=c;j++){
			ll t=0;
			for(int k=i;k<=j;k++)t+=u[i][k]*v[k][j];
			w[i][j]=t%mod;
		}
		return w;
	}
	void print(){for(int i=1;i<=c;i++){for(int j=1;j<=c;j++)printf("%2d ",a[i][j]);puts("");}}
}M,I;
void ksm(){
	I=Matrix();for(int i=1;i<=c;i++)I[i][i]=1;
	for(int y=((n+m+1)>>1);y;y>>=1,M=M*M)if(y&1)I=I*M;
}
int main(){
	scanf("%s%d",s+1,&n),m=strlen(s+1);
	memset(f,-1,sizeof(f));
//	printf("%d|%d|%d\n",dfs(3,3,0),dfs(4,4,0),dfs(3,4,1));
	for(int i=0;i<=min(n,m);i++)g[i]=dfs(1,m,i);
	c=m+((m+1)>>1)+1;
	for(int i=1;i<=m;i++){M[i][i]=24;if(i<m)M[i][i+1]=1;M[i][m+((i+(m&1))>>1)+1]=g[i];}
	for(int i=m+1;i<c;i++)M[i][i]=25,M[i][i+1]=1;
	M[c][c]=26;
//	M.print();
	ksm();
//	I.print();
	int res=(1ll*g[0]*I[m+1][c]+I[1][c])%mod;
	if(!((n+m)&1)){printf("%d\n",res);return 0;}
	memset(f,-1,sizeof(f));
	for(int i=0;i<=min(n,m);i++)g[i]=sfd(1,m,i);
//	for(int i=0;i<=m;i++)printf("%d ",g[i]);puts("");
	M=Matrix();
	for(int i=1;i<=m;i++){M[i][i]=24;if(i<m)M[i][i+1]=1;M[i][m+((i+(m&1))>>1)+1]=g[i];}
	for(int i=m+1;i<c;i++)M[i][i]=25,M[i][i+1]=1;
	ksm();
//	printf("%d\n",res);
	printf("%d\n",(res+mod-(1ll*g[0]*I[m+1][c]+I[1][c])%mod)%mod);
	return 0;
}
/*
abbabb 18
*/