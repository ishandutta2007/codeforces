#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
#define N 100100
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
struct city{
	pii rate;
	int id;
	bool operator<(const city& r)const{
		return 1LL*rate.F*r.rate.S>1LL*r.rate.F*rate.S;
	}
}c[N];
bool better(pii a,pii b){
	return 1LL*a.F*b.S>1LL*a.S*b.F;
}
vector<int> g[N];
vector<int> ch;
bool fort[N];
bool vis[N],tdel[N];
priority_queue<city> pq;
void DFS(int u){
	vis[u]=true;
	pq.push(c[u]);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v]&&!fort[v]) DFS(v);
	}
}
int main(){
	int n,m,k;
	pii ans(0,1);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		c[i].rate=make_pair(0,0);
		c[i].id=i;
	}
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		fort[x]=true;
	}
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		c[x].rate.S++,c[y].rate.S++;
		if(!fort[x]) c[y].rate.F++;
		if(!fort[y]) c[x].rate.F++;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&!fort[i]){
			DFS(i);
			pii tmp(0,1);
			vector<int> del;
			while(!pq.empty()){
				city now=pq.top();
				pq.pop();
				if(now.rate!=c[now.id].rate) continue;
				if(better(now.rate,tmp)){
					tmp=now.rate;
					del.clear();
				}
				del.push_back(now.id);
				tdel[now.id]=true;
				for(int i=0;i<g[now.id].size();i++){
					int v=g[now.id][i];
					if(!fort[v]&&!tdel[v]){
						c[v].rate.F--;
						pq.push(c[v]);
					}
				}
			}
			if(!better(ans,tmp)){
				ans=tmp;
				ch=del;
			}
		}
	}
	printf("%d\n",ch.size());
	for(int i=0;i<ch.size();i++) printf("%d ",ch[i]);
	puts("");
	return 0;
}