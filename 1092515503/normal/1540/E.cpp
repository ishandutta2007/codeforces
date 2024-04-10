#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
const int N=310;
int n,m,a[N];
void ADD(int&x,int y){x+=y;if(x>=mod)x-=mod;}
bool sgn[N];
struct Matrix{
	int x[N][N];
	Matrix(){memset(x,0,sizeof(x));}
	int*operator[](const int&p){return x[p];}
	void print()const{
		for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",x[i][j]);puts("");}
	}
}M,G,V,C;
int d[N],coe[N][N],pov[N][N];
queue<int>q;
void COE_ADD(int i,int j,int k){
	if(!j)return ADD(coe[i][j],k);
	while(j<=n)ADD(coe[i][j],k),j+=j&-j;
}
int COE_SUM(int i,int j){
	j=min(j,n);int k=coe[i][0];
	while(j)ADD(k,coe[i][j]),j-=j&-j;
	return k;
}
void bfs(){
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y=1;y<x;y++)if(M[y][x]&&d[y]>d[x]+1)d[y]=d[x]+1,q.push(y);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)coe[i][j]=0;
		for(int j=1;j<=n;j++)
			if(d[j]<=n)coe[i][d[j]]=(1ll*(a[j]+mod)*C[i][j]%mod*pov[i][d[j]]+coe[i][d[j]])%mod;
		for(int j=1;j<=n;j++)if(j+(j&-j)<=n)ADD(coe[i][j+(j&-j)],coe[i][j]);
	}
}
void answer(){
	int k,l,r,res=0;scanf("%d%d%d",&k,&l,&r);
	for(int i=1;i<=n;i++)ADD(res,1ll*(V[r][i]-V[l-1][i]+mod)*ksm(i,k)%mod*COE_SUM(i,k)%mod);
	for(int i=l;i<=r;i++)if(d[i]>k)ADD(res,mod+a[i]);
	printf("%d\n",res);
}
void prepare(){
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)if(sgn[i])q.push(i),d[i]=0;
	bfs();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ADD(V[j][i],V[j-1][i]);
}
void modify(){
	int x,y;scanf("%d%d",&x,&y);
	if(!sgn[x]&&a[x]+y>0)sgn[x]=true,d[x]=0,q.push(x),bfs();
	ADD(a[x],y);if(d[x]>n)return;
	for(int i=1;i<=n;i++)COE_ADD(i,d[x],1ll*y*C[i][x]%mod*pov[i][d[x]]%mod);
}
void Eigen(){
	for(int i=1;i<=n;i++){
		G=M;
		for(int j=1;j<i;j++)ADD(G[j][j],mod-i);
		V[i][i]=1;
		for(int j=i-1;j;j--){
			int inv=1ll*ksm(G[j][j])*G[j][i]%mod;
			for(int k=1;k<j;k++)ADD(G[k][i],mod-1ll*inv*G[k][j]%mod);
			V[j][i]=(inv?mod-inv:0);
		}
	}
}
void Inversion(){
	for(int i=1;i<=n;i++)C[i][i]=1;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=1;k<=i;k++)
		ADD(C[k][j],mod-1ll*C[k][i]*V[i][j]%mod);
}
int main(){
//	freopen("dag.in","r",stdin);
//	freopen("dag.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		pov[i][0]=1;int inv=ksm(i);
		for(int j=1;j<=n;j++)pov[i][j]=1ll*pov[i][j-1]*inv%mod;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sgn[i]=(a[i]>0);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d",&x),M[i][i]=i;
		while(x--)scanf("%d",&y),M[i][y]=y;
	}
	Eigen(),Inversion(),prepare(),scanf("%d",&m);
	for(int i=1,tp;i<=m;i++)scanf("%d",&tp),tp==1?answer():modify();
	return 0;
}