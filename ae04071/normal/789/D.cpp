#include <stdio.h>
#include <vector>
#include <queue>

typedef long long lli;
int n,m;
std::vector<int> adj[1000001];
bool vis[1000001];
lli self;
int self_chk[1000001];

int main() {
	scanf("%d %d",&n,&m);
	int a,b;
	for(int i=0;i<m;i++) {
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		if(a!=b)
			adj[b].push_back(a);

		if(a==b) {
			self_chk[a]=1;
			++self;
		}
	}

	lli res=0;
	std::queue<int> que;
	for(int i=1;i<=n;i++) {
		if(adj[i].size()!=0) {
			que.push(i);
			vis[i]=true;
			break;
		}
	}


	while(!que.empty()) {
		int now=que.front();que.pop();
		res+=((1ll*adj[now].size())*(adj[now].size()-1ll)/2);
		if(self_chk[now]) {
			res+=m-adj[now].size();
		}

		for(auto &it:adj[now]) {
			if(!vis[it]) {
				que.push(it);
				vis[it]=true;
			}
		}
	}
	res-=(self*(self-1))/2;

	for(int i=1;i<=n;i++) {
		if(!vis[i] && adj[i].size()!=0) {
			printf("0\n");
			return 0;
		}
	}

	printf("%lld\n",res);

	return 0;
}