#include<bits/stdc++.h>
#define N 210
#define M 20010
#define inf 0x3f3f3f3f
using namespace std;
int a[N];
vector<int> ans[N];
vector<int> con[N];
int dis[N],head[N],now[N],que[N],qf,qt,l[N],r[N];
bool vis[N];
int to[M],cap[M],nxt[M];
int cnt,n;
void add_edge(int u,int v,int c){
	cap[cnt]=c,to[cnt]=v,nxt[cnt]=head[u],head[u]=cnt++;
	cap[cnt]=0,to[cnt]=u,nxt[cnt]=head[v],head[v]=cnt++;
}
bool dinic_bfs(){
	memset(dis,0x3f,sizeof(dis));
	qf=0,qt=1;
	dis[0]=0;
	while(qf<qt){
		int u=que[qf++];
		for(int i=head[u];i!=-1;i=nxt[i]){
			if(!cap[i]) continue;
			int v=to[i];
			if(dis[v]==inf){
				dis[v]=dis[u]+1;
				que[qt++]=v;
			}
		}
	}
	return dis[n+1]!=inf;
}
int dinic_dfs(int u,int mx){
	if(!mx) return 0;
	if(u==n+1) return mx;
	int res=0;
	for(int &i=now[u];i!=-1;i=nxt[i]){
		if(dis[u]+1!=dis[to[i]]) continue;
		int tmp=dinic_dfs(to[i],min(cap[i],mx));
		cap[i]-=tmp;
		cap[i^1]+=tmp;
		res+=tmp;
		mx-=tmp;
		if(!mx) return res;
	}
	return res;
}
int flow(){
	int res=0;
	while(dinic_bfs()){
		for(int i=0;i<=n;i++){
			now[i]=head[i];
		}
		res+=dinic_dfs(0,inf);
	}
	return res;
}
bool check_prime(int n){
	if(n==2) return true;
	if(n%2==0) return false;
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0) return false;
	}
	return true;
}
void go(int u,int k){
	vis[u]=true;
	ans[k].push_back(u);
	if(!vis[con[u][0]]) go(con[u][0],k);
	else if(!vis[con[u][1]]) go(con[u][1],k);
}
int main(){
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	int tl=0,tr=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]&1) add_edge(0,i,2),tl+=2;
		else add_edge(i,n+1,2),tr+=2;
	}
	for(int i=1;i<=n;i++){
		if(a[i]&1){
			for(int j=1;j<=n;j++){
				if(check_prime(a[i]+a[j])){
					add_edge(i,j,1);
				}
			}
		}
	}
	if(tl==tr&&flow()==tl){
		for(int i=1;i<=n;i++){
			if(a[i]&1){
				for(int j=head[i];j!=-1;j=nxt[j]){
					if(to[j]&&!cap[j]){
						con[i].push_back(to[j]);
						con[to[j]].push_back(i);
					}
				}
			}
		}
		int k=0;
		for(int i=1;i<=n;i++){
			while(!vis[i]){
				go(i,k++);
			}
		}
		printf("%d\n",k);
		for(int i=0;i<k;i++){
			printf("%d",ans[i].size());
			for(int j=0;j<ans[i].size();j++) printf(" %d",ans[i][j]);
			puts("");
		}
	}
	else puts("Impossible");
	return 0;
}