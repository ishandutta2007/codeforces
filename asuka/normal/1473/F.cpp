#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N],b[N],vis[105];
namespace Flow{
	int s,t;
	struct edge{
		int to,cap,nxt;
		edge(){}
		edge(int a,int b,int c){to = a;cap = b;nxt = c;}
	}e[N<<1];
	int head[N],cur[N],cnt = 1;
	void add(int u,int v,int w){
		e[++cnt] = edge(v,w,head[u]); head[u] = cnt;
		e[++cnt] = edge(u,0,head[v]); head[v] = cnt;
	}
	int dep[N];
	queue<int> q;
	bool bfs(){
		// printf("bfs\n");
		memset(dep,-1,sizeof dep);
		q.push(s); dep[s] = 0; cur[s] = head[s];
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = head[u];~i;i = e[i].nxt){
				int v = e[i].to,w = e[i].cap;
				if(w <= 0 || dep[v] != -1) continue;
				cur[v] = head[v];
				dep[v] = dep[u]+1;
				q.push(v);
			}
		}
		return dep[t] != -1;
	}
	int dfs(int u,int dis){
		if(u == t || dis == 0) return dis;
		int flow = 0;
		for(int i = cur[u];~i;i = e[i].nxt){
			int v = e[i].to; cur[u] = i;
			if(dep[v] == dep[u]+1 && e[i].cap > 0){
				int f = dfs(v,min(dis,e[i].cap));
				if(f > 0){
					e[i].cap -= f; e[i^1].cap += f;
					flow += f; dis -= f;
					if(dis == 0) break;
				}
			}
		}
		return flow;
	}
	int dinic(){
		int ans = 0;
		while(bfs()) ans += dfs(s,inf);
		return ans;
	}
}
using namespace Flow;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(head,-1,sizeof head);
	memset(cur,-1,sizeof cur);
	scanf("%d",&n); s = 0; t = n+1;
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) scanf("%d",&b[i]);
	int res = 0;
	rep(i,1,n){
		if(b[i] > 0) add(s,i,b[i]),res += b[i];
		else add(i,t,-b[i]);
		rep(j,1,100) vis[j] = 0;
		per(j,1,i-1){
			if(a[i]%a[j] == 0){
				if(!vis[a[j]]){
					vis[a[j]] = 1;
					add(i,j,inf);
				}
			} 
		}
	}
	// printf("ook\n");
	res -= dinic();
	printf("%d\n",res);
	return 0;
}