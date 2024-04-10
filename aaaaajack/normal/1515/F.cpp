#include<bits/stdc++.h>
#define N 300100
using namespace std;
int pv[N],pe[N],x[N],y[N],f[N];
bool del[N],vis[N];
long long a[N];
vector<int> g[N],tr[N];
void DFS(int u,int p,int e){
	pv[u]=p;
	pe[u]=e;
	vis[u]=true;
	for(auto i:g[u]){
		int v=x[i]^y[i]^u;
		if(!vis[v]){
			DFS(v,u,i);
			tr[u].push_back(v);
		}
	}
	if(e && a[u]>=0){
		printf("%d\n",e);
		a[p]+=a[u];
		del[u]=true;
	}
}
void solve(int u){
	for(auto v:tr[u]){
		if(!del[v]) printf("%d\n",pe[v]);
		solve(v);
	}
}
int find(int x){
	if(f[x]==x) return x;
	f[x]=find(f[x]);
}
int main(){
	long long sum=0;
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
		a[i]-=k;
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
	}
	if(sum<1LL*(n-1)*k){
		puts("NO");
		return 0;
	}
	puts("YES");
	DFS(1,0,0);
	solve(1);
	return 0;
}