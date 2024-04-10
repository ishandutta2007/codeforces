#include<bits/stdc++.h>
using namespace std;
int l[200005];
vector<int>g[200005];
vector<int>p[200005];
int h[200005];
int ht[200005];
int dist[200005];
int ans[200005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&l[i]);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	memset(h,63,sizeof(h));
	queue<int>q;
	for(int i=1;i<=n;++i)if(l[i]==1){
		h[i]=0;
		q.emplace(i);
	}
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto cu:g[x]){
			if(h[cu]>h[x]+1){
				h[cu]=h[x]+1;
				q.emplace(cu);
			}
		}
	}
	for(int i=1;i<=n;++i)for(auto cu:g[i])
		if(h[i]==h[cu])ht[i]=1;
	for(int i=1;i<=n;++i)if(ht[i])p[h[i]].emplace_back(i);
	for(int i=1;i<=n;++i)ans[i]=h[i];
	for(int H=0;H<=n;++H)if(p[H].size()){
		memset(dist,63,sizeof(dist));
		deque<int>q;
		for(auto cu:p[H])
			dist[cu]=0,q.emplace_back(cu);
		while(q.size()){
			int x=q.front();
			q.pop_front();
			for(auto cu:g[x]){
				if(h[cu]==h[x]){
					if(dist[cu]>max(0,dist[x])+1){
						dist[cu]=max(0,dist[x])+1;
						q.emplace_back(cu);
					}
				}else if(h[cu]==h[x]+1){
					if(dist[cu]>dist[x]-1){
						dist[cu]=dist[x]-1;
						q.emplace_front(cu);
					}
				}
			}
		}
		for(int i=1;i<=n;++i)if(dist[i]<=0)
			ans[i]=max(ans[i],2*h[i]-H);
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}