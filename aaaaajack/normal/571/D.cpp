#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstring>
#include<ctime>
#include<cassert>
#define N 500100
#define M 500100
using namespace std;
int f[N+M],rt[N],mx[N+M],sz[N+M];
int len,stk[M];
long long sum[M],ans[M],add[N+M];
bool del[N];
vector<int> g[N+M],q[N],st[N];
int find(int x){
	if(f[x]==x) return x;
	int y=find(f[x]);
	mx[x]=max(mx[x],mx[f[x]]);
	return f[x]=y;
}
void DFS(int u,int n){
	if(g[u].empty()){
		for(int i=0;i<q[u].size();i++){
			int l=lower_bound(stk,stk+len,q[u][i],greater<int>())-stk-1;
			int r=lower_bound(stk,stk+len,st[u][i],greater<int>())-stk-1;
			ans[q[u][i]]=sum[r]-sum[l];
		}
		return;
	}
	stk[len]=u-n;
	sum[len]=sum[len-1]+add[u];
	len++;
	for(int i=0;i<g[u].size();i++){
		DFS(g[u][i],n);
	}
	len--;
}
int main(){
	char tp;
	int x,y,n,m,a,b;
	memset(ans,-1,sizeof(ans));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		f[i]=i;
		rt[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=m;i++){
		scanf(" %c",&tp);
		if(tp=='U'||tp=='M'){
			scanf("%d%d",&a,&b);
			if(tp=='U'){
				g[n+i].push_back(rt[a]);
				g[n+i].push_back(rt[b]);
				sz[n+i]=sz[rt[a]]+sz[rt[b]];
				rt[a]=n+i;
				del[b]=true;
			}
			else{
				f[find(a)]=n+i;
				f[find(b)]=n+i;
				f[n+i]=n+i;
			}
		}
		else{
			scanf("%d",&a);
			if(tp=='A'){
				g[n+i].push_back(rt[a]);
				sz[n+i]=sz[rt[a]];
				add[n+i]=sz[rt[a]];
				rt[a]=n+i;
			}
			else if(tp=='Z'){
				mx[find(a)]=i;
			}
			else{
				q[a].push_back(i);
				find(a);
				st[a].push_back(mx[a]);
			}
		}
	}
	stk[0]=m+1;
	len=1;
	for(int i=1;i<=n;i++){
		if(!del[i]){
			DFS(rt[i],n);
		}
	}
	for(int i=1;i<=m;i++){
		if(ans[i]>=0) printf("%I64d\n",ans[i]);
	}
	return 0;
}