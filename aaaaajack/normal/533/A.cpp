#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<utility>
#include<cstring>
#define N 500100
using namespace std;
vector<int> g[N],ch[N];
bool vis[N];
int h[N],th[N],s[N],vec[N],sz,tr[N*4],val[N];
void DFS(int u,int rt){
	vis[u]=true;
	if(rt>0&&th[u]>h[u]) ch[rt].push_back(th[u]);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]) continue;
		if(rt>0){
			th[v]=min(th[u],th[v]);
		}
		else{
			h[v]=min(h[u],h[v]);
		}
		DFS(v,rt);
	}
	vis[u]=false;
}
void build(int u,int l,int r,int n){
	if(l+1==r){
		tr[u]=(l+1)-(upper_bound(h+1,h+n+1,s[l],greater<int>())-h-1);
		return;
	}
	build(u<<1,l,(l+r)/2,n);
	build(u<<1|1,(l+r)/2,r,n);
	tr[u]=max(tr[u<<1],tr[u<<1|1]);
}
int qry(int u,int ql,int qr,int l,int r){
	if(ql>=qr) return 0;
	if(ql==l&&qr==r) return tr[u];
	int m=(l+r)/2;
	if(qr<=m) return qry(u<<1,ql,qr,l,m);
	else if(ql>=m) return qry(u<<1|1,ql,qr,m,r);
	else return max(qry(u<<1,ql,m,l,m),qry(u<<1|1,m,qr,m,r));
}
int main(){
	int n,x,y,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]),th[i]=h[i];
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&s[i]);
	}
	sort(s,s+k,greater<int>());
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(h[1],1));
	vis[1]=true;
	int st=-1;
	for(int i=0;i<k;i++){
		if(pq.top().first<s[i]){
			st=i;
			break;
		}
		int u=pq.top().second;
		pq.pop();
		for(int j=0;j<g[u].size();j++){
			if(vis[g[u][j]]) continue;
			vis[g[u][j]]=true;
			h[g[u][j]]=min(h[g[u][j]],h[u]);
			pq.push(make_pair(h[g[u][j]],g[u][j]));
		}
	}
	if(st==-1) puts("0");
	else{
		while(!pq.empty()){
			vec[sz++]=pq.top().second;
			pq.pop();
		}
		for(int i=0;i<sz;i++){
			DFS(vec[i],0);
			th[vec[i]]=s[st];
			DFS(vec[i],vec[i]);
			val[i]=h[vec[i]];
		}
		sort(h+1,h+n+1,greater<int>());
		build(1,0,k,n);
		for(int i=0;i<sz;i++){
			bool flag=true;
			int u=vec[i],pre,l,r;
			sort(ch[u].begin(),ch[u].end(),greater<int>());
			l=lower_bound(s,s+k,ch[u].front(),greater<int>())-s;
			r=lower_bound(s,s+k,val[i],greater<int>())-s;
			if(qry(1,0,l,0,k)>0||qry(1,r,k,0,k)>0) flag=false;
			for(int j=ch[u].size()-1;j>=0;j--){
				l=lower_bound(s,s+k,ch[u][j],greater<int>())-s;
				if(qry(1,l,r,0,k)>j+1) flag=false;
				r=l;
			}
			if(flag){
				printf("%d\n",s[st]-val[i]);
				return 0;
			}
		}
		puts("-1");
	}
	return 0;
}