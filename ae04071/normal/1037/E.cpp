#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int n,m,k,vis[200001],cnt[200001],ans[200001],u[200001],v[200001];
vector<pii> adj[200001];

void remove(queue<int> &que,int &res,int ei) {
	while(!que.empty()) {
		int cur=que.front();que.pop();
		res--;
		for(auto &it:adj[cur]) if(!vis[it.first] && it.second < ei) {
			cnt[it.first]--;
			if(cnt[it.first]<k) {
				vis[it.first]=1;
				que.push(it.first);
			}
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++) {
		scanf("%d%d",u+i,v+i);
		adj[u[i]].push_back(pii(v[i],i));
		adj[v[i]].push_back(pii(u[i],i));
	}
	for(int i=1;i<=n;i++) cnt[i] = (int)adj[i].size();

	queue<int> que;
	for(int i=1;i<=n;i++) if(cnt[i] < k) {
		que.push(i);
		vis[i]=1;
	}
	int res=n;
	remove(que,res,m);

	for(int i=m-1;i>=0;i--) {
		ans[i] = res;
		if(!vis[u[i]] && !vis[v[i]]) {
			cnt[u[i]]--; cnt[v[i]]--;
			if(cnt[u[i]]<k) que.push(u[i]),vis[u[i]]=1;
			if(cnt[v[i]]<k) que.push(v[i]),vis[v[i]]=1;
			remove(que,res,i);
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);

	return 0;
}