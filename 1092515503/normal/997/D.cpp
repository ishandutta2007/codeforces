#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
void ADJ(int&x){if(x>=mod)x-=mod;}
int RED(int x){return x>=mod?x-mod:x;}
int K,fac[200],inv[200],INV[200];
struct Tre{
int f[20100][80],g[20100][80],T,h[80],F[20100][80],G[20100][80],head[10100],cnt;
struct node{int to,next;}edge[20100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void func(int _T){
	T=_T,memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<T;i++)scanf("%d%d",&x,&y),ae(x,y);
	for(int i=0;i<cnt;i++)f[i][0]=g[i][0]=1;
	for(int i=1;i<=T;i++)F[i][0]=G[i][0]=1;h[0]=T;
	for(int i=1;i<=K;i++){
		for(int x=1;x<=T;x++)
			for(int j=head[x];j!=-1;j=edge[j].next)ADJ(G[x][i]+=f[j][i-1]);
		for(int j=0;j<cnt;j++){
			g[j][i]=RED(f[j^1][i-1]-G[edge[j].to][i]+mod);
			for(int k=0;k<i;k++)f[j][i]=(1ll*f[j][k]*g[j][i-k]+f[j][i])%mod;
			ADJ(f[j][i]=mod-f[j][i]);
//			printf("[%d,%d,%d]",j,g[j][i],f[j][i]);
		}//puts("");
		for(int x=1;x<=T;x++){
			ADJ(G[x][i]=mod-G[x][i]);
			for(int j=0;j<i;j++)F[x][i]=(1ll*F[x][j]*G[x][i-j]+F[x][i])%mod;
			ADJ(F[x][i]=mod-F[x][i]);
			ADJ(h[i]+=F[x][i]);
//			printf("<%d,%d,%d>",x,G[x][i],F[x][i]);
		}//puts("");
	}
//	for(int i=0;i<=K;i++)printf("%d ",h[i]);puts("");
}
}t1,t2;
int n,m,fulK,f[160],g[160],h[160];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	INV[1]=1;for(int i=2;i<=K;i++)INV[i]=1ll*INV[mod%i]*(mod-mod/i)%mod;
	fac[0]=1;for(int i=1;i<=K;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[K]=ksm(fac[K]);for(int i=K;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	fulK=K,K>>=1;
//	for(int i=1;i<=K;i++)printf("%d ",INV[i]);puts("");
	t1.func(n),t2.func(m);
	for(int i=0;i<=K;i++)f[i<<1]=t1.h[i],g[i<<1]=t2.h[i];
	K=fulK;
	for(int i=0;i<=K;i++)for(int j=0;i+j<=K;j++)
		h[i+j]=(1ll*f[i]*g[j]%mod*inv[i]%mod*inv[j]%mod*fac[i+j]+h[i+j])%mod;
	printf("%d\n",h[K]);
	return 0;
} 
/*
3 2 10
1 2
1 3
1 2
*/