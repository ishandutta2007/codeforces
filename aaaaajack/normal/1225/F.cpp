#include<bits/stdc++.h>
#define N 100100
using namespace std;
stack<int> v[N];
vector<int> g[N];
int p[N],a[N],b[N],d[N],od[N],id[N],cnt;
bool lp[N];
void DFS(int u){
	od[cnt++]=u;
	for(auto v:g[u]) DFS(v);
}
int main(){
	vector<int> ans;
	int n,mx=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);
		d[i]=d[a[i]]+1;
		if(d[i]>d[mx]) mx=i;
		p[i]=i-1;
	}
	while(mx) lp[mx]=true,mx=a[mx];
	for(int i=1;i<n;i++){
		if(!lp[i]) g[a[i]].push_back(i);
	}
	for(int i=1;i<n;i++){
		if(lp[i]) g[a[i]].push_back(i);
	}
	DFS(0);
	for(int i=0;i<n;i++) id[od[i]]=i;
	for(int i=0;i<n;i++) b[id[i]]=id[a[i]];
	for(int i=n-1;i>0;i--){
		v[b[i]].push(i);
		while(!v[i-1].empty()){
			int u=v[i-1].top();
			v[i-1].pop();
			while(p[u]!=b[u]){
				p[u]=p[p[u]];
				ans.push_back(u);
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",od[i]);
	}
	puts("");
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",od[x]);
	puts("");
	return 0;
}