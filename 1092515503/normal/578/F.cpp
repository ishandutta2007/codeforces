#include<bits/stdc++.h>
using namespace std;
int n,m,dsu[11000],mod,res;
char s[110][110];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x==y){puts("0");exit(0);}dsu[x]=y;}
int w;
vector<int>v;
int g[410][410];
void ADD(int x,int y){(g[x][y]+=mod-1)%=mod,(g[y][x]+=mod-1)%=mod,(++g[x][x])%=mod,(++g[y][y])%=mod;}
int id(int i,int j){return lower_bound(v.begin(),v.end(),find(i*(m+1)+j))-v.begin();}
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int Determinant(){
//	for(int i=0;i<w;i++){for(int j=0;j<w;j++)printf("%d ",g[i][j]);puts("");}
	int lam=1;
	for(int i=1,j;i<w;i++){
		j=i;while(j<w&&!g[j][i])j++;
		if(j>=w)return 0;
		if(i!=j)swap(g[i],g[j]),lam=-lam;
		int inv=mod-ksm(g[i][i]);
		for(j=i+1;j<w;j++){
			int kap=1ll*g[j][i]*inv%mod;
			for(int k=i;k<w;k++)g[j][k]=(1ll*g[i][k]*kap+g[j][k])%mod;
		}
	}
	if(lam==-1)lam=mod-1;
	for(int i=1;i<w;i++)lam=1ll*lam*g[i][i]%mod;
	return lam;
}
int main(){
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<(n+1)*(m+1);i++)dsu[i]=i;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]=='/')merge((i+1)*(m+1)+j,i*(m+1)+(j+1));
		if(s[i][j]=='\\')merge(i*(m+1)+j,(i+1)*(m+1)+(j+1));
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)if(((i+j)&1)&&dsu[i*(m+1)+j]==i*(m+1)+j)v.push_back(i*(m+1)+j);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='*'){
		if((i+j)&1)ADD(id(i,j),id(i+1,j+1));
		else ADD(id(i+1,j),id(i,j+1));
	}
	w=v.size(),v.clear();
	(res+=Determinant())%=mod;memset(g,0,sizeof(g));
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)if(!((i+j)&1)&&dsu[i*(m+1)+j]==i*(m+1)+j)v.push_back(i*(m+1)+j);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='*'){
		if((i+j)&1)ADD(id(i+1,j),id(i,j+1));
		else ADD(id(i,j),id(i+1,j+1));
	}
	w=v.size(),v.clear();
	(res+=Determinant())%=mod;memset(g,0,sizeof(g));
	printf("%d\n",res);
	return 0;
}