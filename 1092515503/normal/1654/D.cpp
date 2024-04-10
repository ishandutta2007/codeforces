#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int T,n,X[200100],Y[200100],A[200100],B[200100],b[200100],c[200100],res,now,INV[200100];
vector<int>v[200100];
void dfs1(int x,int fa){
//	printf("%d:",x);for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
	for(auto i:v[x]){
		int y=X[i]^Y[i]^x,t;
		if(y==fa)continue;
		if(x==Y[i])swap(A[i],B[i]),swap(X[i],Y[i]);
		t=B[i];for(int j=2;j*j<=t;j++)while(!(t%j))t/=j,b[j]++;if(t>1)b[t]++;
		t=A[i];for(int j=2;j*j<=t;j++)while(!(t%j))t/=j,b[j]--,c[j]=min(c[j],b[j]);if(t>1)b[t]--,c[t]=min(c[t],b[t]);
		dfs1(y,x);
		t=B[i];for(int j=2;j*j<=t;j++)while(!(t%j))t/=j,b[j]--;if(t>1)b[t]--;
		t=A[i];for(int j=2;j*j<=t;j++)while(!(t%j))t/=j,b[j]++;if(t>1)b[t]++;
	}
}
void dfs2(int x,int fa){
//	printf("%d:%d\n",x,now);
	(res+=now)%=mod;
	for(auto i:v[x]){
		int y=X[i]^Y[i]^x;
		if(y==fa)continue;
		if(x==Y[i])swap(A[i],B[i]),swap(X[i],Y[i]);
		now=1ll*now*INV[A[i]]%mod*B[i]%mod;
		dfs2(y,x);
		now=1ll*now*A[i]%mod*INV[B[i]]%mod;
	}
}
void mina(){
	scanf("%d",&n),res=0;
	for(int i=1;i<n;i++)scanf("%d%d%d%d",&X[i],&Y[i],&A[i],&B[i]),v[X[i]].push_back(i),v[Y[i]].push_back(i);
	INV[1]=1;for(int i=2;i<=n;i++)INV[i]=1ll*INV[mod%i]*(mod-mod/i)%mod;
	dfs1(1,0);
	now=1;for(int i=1;i<=n;i++)now=1ll*now*ksm(i,b[i]=-c[i])%mod;
	dfs2(1,0);
	printf("%d\n",res);
	for(int i=1;i<=n;i++)b[i]=c[i]=0,v[i].clear();
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
4
3 2 3 4
1 2 4 3
1 4 2 4
*/