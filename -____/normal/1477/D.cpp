#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 555555;
int n,m,s,a[N],b[N],w,rt,r[N];
vector<int> v[N],g[N],h[N];
void adg(int x,int y){
	g[x].push_back(y);//cout<<x<<y<<endl;
}
int ok(int x,int y){
	if(*lower_bound(v[x].begin(),v[x].end(),y)==y)
		return 0;
	return 1;
}
void dfs1(int u){
	int i,j;
	j=0;
	for(i=1;i<=w;i++){
		if(ok(u,r[i]))
			adg(u,r[i]);
		else
			r[++j]=r[i];
	}
	w=j;
	for(i=0;i<g[u].size();i++)
		dfs1(g[u][i]);
}
int dfs2(int u){
	int i,p,x;
	for(i=0;i<g[u].size();i++){
		x=g[u][i];
		if(g[x].size()==0)
			h[u].push_back(x);
		else
			p=x;
	}
	if(h[u].size()){
		for(i=0;i<g[u].size();i++){
			x=g[u][i];
			if(g[x].size())
				dfs2(x);
		}
	}
	else{
		for(i=0;i<g[u].size();i++){
			x=g[u][i];
			if(x!=p)
				dfs2(x);
		}
		h[p].push_back(u);
		for(i=0;i<g[p].size();i++){
			x=g[p][i];
			if(g[x].size()==0)
				h[p].push_back(x);
			else
				dfs2(x);
		}
	}
}
int main(){
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		s=0;
		w=0;
		for(i=1;i<=n;i++){
			if(v[i].size()==n-1)
				s++,a[i]=s,b[i]=s;
			else
				r[++w]=i;
			sort(v[i].begin(),v[i].end());
			v[i].push_back(n+1);
		}
		while(w){
			rt=r[w];
			w--;
			dfs1(rt);
			dfs2(rt);
		}
		for(i=1;i<=n;i++){
			if(h[i].size()){
				b[i]=++s;
				for(j=0;j<h[i].size();j++)
					a[h[i][j]]=s,b[h[i][j]]=++s;
				a[i]=s;
			}
		}
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		for(i=1;i<=n;i++)
			printf("%d ",b[i]);
		printf("\n");
		for(i=1;i<=n;i++){
			v[i].clear();
			g[i].clear();
			h[i].clear();
		}
	}
	return 0;
}