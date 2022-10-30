#include<cstdio>
#include<utility>
#include<set>
#include<vector>
#define N 100100
using namespace std;
int deg[N];
int out[N];
int f[N];
bool v[N];
vector<pair<int,int> > edge;
set<pair<int,int> > rev;
vector<int> g[N];
void init(int n){
	for(int i=1;i<=n;i++) f[i]=i;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	f[find(x)]=find(y);
}
int DFS(int now){
	v[now]=true;
	int r=out[now],s,i;
	for(i=0;i<g[now].size();i++){
		if(!v[g[now][i]]){
			s=DFS(g[now][i]);
			if(s) rev.insert(make_pair(now,g[now][i]));
			r^=s;
		}
	}
	return r;
}
int main(){
	int n,m,a,b,i;
	vector<int> odd;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&a,&b);
		edge.push_back(make_pair(a,b));
		deg[a]++;
		out[a]^=1;
		deg[b]++;
	}
	for(i=1;i<=n;i++){
		if(deg[i]&1) odd.push_back(i);
	}
	for(i=0;i<odd.size();i+=2){
		edge.push_back(make_pair(odd[i],odd[i+1]));
		out[odd[i]]^=1;
	}
	if(edge.size()&1){
		out[1]^=1;
		edge.push_back(make_pair(1,1));
	}
	init(n);
	for(i=0;i<edge.size();i++){
		if(find(edge[i].first)!=find(edge[i].second)){
			uni(edge[i].first,edge[i].second);
			g[edge[i].first].push_back(edge[i].second);
			g[edge[i].second].push_back(edge[i].first);
		}
	}
	DFS(1);
	printf("%d\n",edge.size());
	for(i=0;i<edge.size();i++){
		if(rev.count(make_pair(edge[i].first,edge[i].second))||rev.count(make_pair(edge[i].second,edge[i].first))){
			printf("%d %d\n",edge[i].second,edge[i].first);
			rev.erase(make_pair(edge[i].first,edge[i].second));
			rev.erase(make_pair(edge[i].second,edge[i].first));
		}
		else{
			printf("%d %d\n",edge[i].first,edge[i].second);
		}
	}
	return 0;
}