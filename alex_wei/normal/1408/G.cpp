#include <bits/stdc++.h>
using namespace std;

const int N=1500+5;
const int mod=998244353;

int n,cnt,f[N],sz[N],ed[N],c[N][N];
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}

struct edge{
	int i,j,val;
	bool operator < (const edge &v) const {
		return val<v.val;
	}
}e[N*N];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			e[++cnt]={i,j,0};
			scanf("%d",&e[cnt].val);
		} sort(e+1,e+cnt+1);
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].i),y=find(e[i].j);
		if(x!=y){
			int nw[N];
			memset(nw,0,sizeof(nw));
			for(int j=1;j<=sz[x];j++)
				for(int k=1;k<=sz[y];k++)
					nw[j+k]=(nw[j+k]+1ll*c[x][j]*c[y][k])%mod;
			ed[x]+=ed[y]+1,sz[x]+=sz[y],f[y]=x;
			for(int j=1;j<=sz[x];j++)c[x][j]=nw[j]%mod;
		} else if(sz[x]*sz[x]==++ed[x])c[x][1]++;
	} int pos=find(1);
	for(int i=1;i<=n;i++)cout<<c[pos][i]%mod<<" "; cout<<endl;
	return 0;
}