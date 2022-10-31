#include<bits/stdc++.h>
#define N 200100
using namespace std;
int a[N],cnt[N],ans[N],dep;
vector<int> g[N],w[N];
long long l[N],sum;
void DFS(int u){
	for(int i=0;i<g[u].size();i++){
		sum+=w[u][i];
		l[dep]=l[dep-1]+w[u][i];
		cnt[dep]=0;
		++dep;
		DFS(g[u][i]);
		sum-=w[u][i];
	}
	ans[u]=cnt[dep-1];
	cnt[dep-1]++;
	int p=lower_bound(l,l+dep,sum-a[u])-l;
	if(p) cnt[p-1]--;
	if(dep>1) cnt[dep-2]+=cnt[dep-1];
	dep--;
}
int main(){
	int n,p,s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		scanf("%d%d",&p,&s);
		g[p].push_back(i);
		w[p].push_back(s);
	}
	dep=1;
	DFS(1);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}