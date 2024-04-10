#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n,m,val;
ll a[N];
int fa[N];
pair<int,int> e[N];
vector<pair<int,int> > g[N];
vector<int> ans;

int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}

int main(){
	scanf("%d%d%d",&n,&m,&val);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),fa[i]=i;
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
		e[i]=make_pair(x,y);
	}
	for(int x=1;x<=n;++x)
	if(gf(x)==x){
		if(a[x]<val)continue;
		while(g[x].size()){
			int y=gf(g[x][g[x].size()-1].first);
			int id=g[x][g[x].size()-1].second;
			g[x].pop_back();
			if(y==x)continue;
			fa[y]=x;
			a[x]+=a[y]-val;
			ans.push_back(id);
			if(g[x].size()<g[y].size())g[x].swap(g[y]);
			for(int t=0;t<g[y].size();++t){
				g[x].push_back(g[y][t]);
			}
			if(a[x]<val)break;
		}
	}
	for(int i=1;i<=m;++i){
		int x=gf(e[i].first);
		int y=gf(e[i].second);
		if(x==y)continue;
		if(a[x]+a[y]>=val){
			a[x]+=a[y]-val;
			fa[y]=x;
			ans.push_back(i);
		}
	}
	if(ans.size()<n-1)puts("NO");
	else{
		puts("YES");
		for(int i=0;i<ans.size();++i){
			printf("%d\n",ans[i]);
		}
	}
}