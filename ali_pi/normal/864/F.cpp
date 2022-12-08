#include<bits/stdc++.h>

using namespace std;

struct nd{int s,k,id;};

nd mk(int ss,int kk,int idid){nd nndd;nndd.s=ss;nndd.k=kk;nndd.id=idid;return nndd;}

vector<int>g[3005];
vector<nd>v[3005];
int n,m,q,f[15][3005],ans[400005];

void dfs(int x,int p){
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=p&&((!f[0][g[x][i]])||f[0][g[x][i]]>x))
	{
		f[0][g[x][i]]=x;
		dfs(g[x][i],p);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[y].push_back(x);
	}
	for(int i=1;i<=q;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[y].push_back(mk(x,z,i));
	}
	for(int i=1;i<=n;i++)if(v[i].size()){
		memset(f[0],0,sizeof(f[0]));
		dfs(i,i);
		for(int j=1;j<=12;j++)for(int k=1;k<=n;k++)f[j][k]=f[j-1][f[j-1][k]];
		for(int j=0;j<v[i].size();j++){
			int u=v[i][j].s,t=v[i][j].k-1,id=v[i][j].id;
			if(!f[0][u]||f[12][u]){ans[id]=-1;continue;}
			for(int k=0;t;k++,t>>=1)if(t&1)u=f[k][u];
			if(u)ans[id]=u;else ans[id]=-1;
		}
	}
	for(int i=1;i<=q;i++)
            printf("%d\n",ans[i]);
	return 0;
}