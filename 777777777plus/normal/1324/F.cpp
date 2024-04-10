#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
int a[N],f[N],g[N];
vector<int> G[N];

void dfs1(int x,int fa=-1){
	f[x]=(a[x]?1:-1);
	for(int i=0;i<G[x].size();++i)
	if(G[x][i]!=fa){
		int y=G[x][i];
		dfs1(y,x);
		f[x]+=max(f[y],0);
	}
}

void dfs2(int x,int val=0,int fa=-1){
	g[x]=val+f[x];
	int w=0;
	for(int i=0;i<G[x].size();++i)
	if(G[x][i]!=fa){
		int y=G[x][i];
		w+=max(f[y],0);
	}
	for(int i=0;i<G[x].size();++i)
	if(G[x][i]!=fa){
		int y=G[x][i];
		dfs2(y,max(0,val+(a[x]?1:-1)+w-max(f[y],0)),x);
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;++i)cout<<g[i]<<" ";
	cout<<endl;
}