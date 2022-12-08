#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a,b,da,db;
int f[N][20],d[N];
vector<int> g[N];

void dfs(int x,int fa=-1){
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=fa){
		int y=g[x][i];
		f[y][0]=x;
		d[y]=d[x]+1;
		dfs(y,x);
	}
}

int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    for(int i=19;~i;--i)
	if(d[f[x][i]]>=d[y]){
		x=f[x][i];
	}
    if(x==y)return x;
    for(int i=19;~i;--i)
	if(f[x][i]!=f[y][i]){
		x=f[x][i],y=f[y][i];
	}
    return f[x][0];
}

int dis(int x,int y){
	return d[x]+d[y]-2*d[lca(x,y)];
}

int main(){
	cin>>T;
	while(T--){
		cin>>n>>a>>b>>da>>db;
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=1,x,y;i<n;++i){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(db<=da*2){
			puts("Alice");
			continue;
		}
		d[1]=1;
		dfs(1);
		for(int j=1;j<20;++j)
		for(int i=1;i<=n;++i)
		f[i][j]=f[f[i][j-1]][j-1];
		if(dis(a,b)<=da){
			puts("Alice");
			continue;
		}
		int rt1=1;
		for(int i=1;i<=n;++i)
		if(dis(1,i)>dis(1,rt1)){
			rt1=i;
		}
		int rt2=1;
		for(int i=1;i<=n;++i)
		if(dis(rt1,i)>dis(rt1,rt2)){
			rt2=i;
		}
		int k=dis(rt1,rt2);
		if(k<=2*da){
			puts("Alice");
			continue;
		}
		puts("Bob");
	}
}