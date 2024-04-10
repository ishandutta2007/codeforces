#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,l[N],r[N],o[N<<1],tot,cnt,ans[N],ind[N<<1],head[N<<1];
struct edge{
	int to,next,w;
	edge(){}
	edge(int u,int v,int x){to = u;next = v;w = x;}
}e[N<<2];
bool vis[N<<2],gkp[N<<2];
void add(int u,int v,int w){
	e[++cnt] = edge(v,head[u],w);
	head[u] = cnt;
}
void dfs(int u){
	gkp[u] = 1;
	for(int i = head[u];~i;i = e[i].next){
		int v = e[i].to;
		if(vis[i]) continue;
		vis[i] = vis[i^1] = 1;
		ans[e[i].w] = (u<v);
		dfs(v);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(head,-1,sizeof head);
	scanf("%d",&n);cnt = -1;
	rep(i,1,n) scanf("%d%d",&l[i],&r[i]),++r[i],o[++tot] = l[i],o[++tot] = r[i];
	sort(o+1,o+tot+1);int m = unique(o+1,o+tot+1)-o-1;
	rep(i,1,n){
		l[i] = lower_bound(o+1,o+m+1,l[i])-o;
		r[i] = lower_bound(o+1,o+m+1,r[i])-o;
		add(l[i],r[i],i);add(r[i],l[i],i);
		ind[l[i]]++;ind[r[i]]++;
	}
	int last = 0;
	rep(i,1,m){
		if(ind[i]&1){
			if(last) add(i,last,0),add(last,i,0),last = 0;
			else last = i;
		}
	}
	rep(i,1,m) if(gkp[i] == 0) dfs(i);
	rep(i,1,n) printf("%d ", ans[i]);
	return 0;
}