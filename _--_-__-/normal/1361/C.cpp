#include<bits/stdc++.h>
using namespace std;

const int maxn=500111;
const int N=20;

std::vector<int>g[1<<N],E[1<<N];
int U[maxn],V[maxn],n;

int f[1<<N];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
bool check(int m){
	static int dgr[1<<N];
	for(int i=0;i<(1<<m);i++){
		dgr[i]=0;
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		int u=U[i]&(1<<m)-1, v=V[i]&(1<<m)-1;
		dgr[u]++;
		dgr[v]++;
		f[gf(u)]=gf(v);
	}
	int piv=-1;
	for(int i=0;i<(1<<m);i++){
		if(dgr[i]%2==1)return false;
		if(dgr[i]>0){
			if(piv==-1)piv=gf(i);
			else if(gf(i)!=piv)return false;
		}
	}
	return true;
}

int iter[1<<N];
std::vector<int>seq;
bool used[maxn];
void dfs(int x)
{
	for(int&i=iter[x];i<(int)g[x].size();i++){
		int id=E[x][i];
		if(used[id>>1])continue;
		used[id>>1]=1;
		dfs(g[x][i]);
		seq.push_back(id);
	}
}

void construct(int m){
	for(int i=1;i<=n;i++){
		int u=U[i]&(1<<m)-1, v=V[i]&(1<<m)-1;
		g[u].push_back(v);
		g[v].push_back(u);
		E[u].push_back(i*2);
		E[v].push_back(i*2+1);
	}
	int piv=0;
	while(g[piv].size()==0)piv++;
	dfs(piv);
	for(auto x:seq)
	{
		if(x%2==0)printf("%d %d ",x,x-1);
		else printf("%d %d ",x-2,x-1);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",U+i,V+i);
	}
	int ans=20;
	while(!check(ans))ans--;
	
	printf("%d\n",ans);
	construct(ans);
	return 0;
}