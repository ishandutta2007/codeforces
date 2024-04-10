#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,X[100100],Y[100100],cnt[2][100100],g[2],f[100100][2][2][2];
vector<int>v[100100];
bool vis[100100];
void dfsline(int x,int fa){
//	printf("%d\n",x);
//	for(int a=0;a<2;a++)for(int b=0;b<2;b++)for(int c=0;c<2;c++)
//		printf("%d[%d,%d,%d]%d\n",x,a,b,c,f[x][a][b][c]);
	vis[x]=true;
	for(auto i:v[x]){
		if(x==abs(Y[i]))swap(X[i],Y[i]);
		int y=abs(Y[i]);
		if(y==fa)continue;
		for(int z=0;z<2;z++)for(int a=0;a<2;a++)for(int b=0;b<2;b++)for(int c=0;c<2;c++){
			int A=a,B=b,C=c;
			if(x+X[i]==0)A=!A;
			if(y+Y[i]==0)B=!B;
			C^=(A|B);
			(f[y][z][b][C]+=f[x][z][a][c])%=mod;
		}
		return dfsline(y,x);
	}
	int G[2]={0,0};
	for(int z=0;z<2;z++)for(int a=0;a<2;a++)for(int b=0;b<2;b++){
		int B=b;
		if(cnt[0][x])B^=a;
		if(cnt[1][x])B^=!a;
		G[B^0]=(1ll*f[x][z][a][b]*g[0]+G[B^0])%mod;
		G[B^1]=(1ll*f[x][z][a][b]*g[1]+G[B^1])%mod;
	}
	g[0]=G[0],g[1]=G[1];
}
void dfscirc(int x,int fi){
	vis[x]=true;
	for(auto i:v[x]){
		if(i==fi)continue;
		if(x==abs(Y[i]))swap(X[i],Y[i]);
		int y=abs(Y[i]);
		if(!vis[y]){
			for(int z=0;z<2;z++)for(int a=0;a<2;a++)for(int b=0;b<2;b++)for(int c=0;c<2;c++){
				int A=a,B=b,C=c;
				if(x+X[i]==0)A=!A;
				if(y+Y[i]==0)B=!B;
				C^=(A|B);
				(f[y][z][b][C]+=f[x][z][a][c])%=mod;
			}
			return dfscirc(y,i);			
		}
//		printf("%d %d\n",x,y);
		int G[2]={0,0};
		for(int z=0;z<2;z++)for(int a=0;a<2;a++)for(int b=0;b<2;b++){
//			printf("%d,%d,%d:%d\n",z,a,b,f[x][z][a][b]);
			int Z=a,A=z,B=b;
			if(x+X[i]==0)Z=!Z;
			if(y+Y[i]==0)A=!A;
			B^=(A|Z);
			G[B^0]=(1ll*f[x][z][a][b]*g[0]+G[B^0])%mod;
			G[B^1]=(1ll*f[x][z][a][b]*g[1]+G[B^1])%mod;
		}
		g[0]=G[0],g[1]=G[1];
		return;
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1,k;i<=m;i++){
		scanf("%d",&k);
		if(k==1){scanf("%d",&k);if(k>0)cnt[0][k]++;else cnt[1][-k]++;}
		else scanf("%d%d",&X[i],&Y[i]),v[abs(X[i])].push_back(i),v[abs(Y[i])].push_back(i);
	}
//	for(int i=1;i<=n;i++)printf("%d ",v[i].size());puts("");
	g[0]=1;
	for(int i=1;i<=n;i++)if(v[i].size()==1&&!vis[i]){
		for(int t=0;t<2;t++){
			int val=0;
			if(cnt[0][i])val^=t;
			if(cnt[1][i])val^=!t;
			f[i][t][t][val]=1;
		}
		dfsline(i,0);
	}
//	printf("%d %d\n",g[0],g[1]);
	for(int i=1;i<=n;i++)if(v[i].size()==2&&!vis[i]){
		for(int t=0;t<2;t++)f[i][t][t][0]=1;
		dfscirc(i,0);
	}
//	printf("%d %d\n",g[0],g[1]);
	for(int i=1;i<=n;i++)if(!vis[i]){
		int G[2]={0,0};
		for(int t=0;t<2;t++){
			int B=0;
			if(cnt[0][i])B^=t;
			if(cnt[1][i])B^=!t;
			(G[B^0]+=g[0])%=mod;
			(G[B^1]+=g[1])%=mod;
		}
		g[0]=G[0],g[1]=G[1];
	}
	printf("%d\n",g[1]);
	return 0;
}