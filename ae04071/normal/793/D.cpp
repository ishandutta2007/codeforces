#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

typedef std::pair<int,int> ip;
const int INF=987654321;
std::vector<ip> adj[81];
int n,k,m;
int cache[82][82][82];

int DP(int now,int b, int r) {
	if(r==0) return 0;

	int &ret=cache[now][b][r];
	if(ret!=-1) return ret;
	ret=INF;

	int minb=std::min(now,b),maxb=std::max(now, b);
	for(auto &it:adj[now]) {
		if(minb<it.second&&it.second<maxb) {
			int min=std::min(DP(it.second,now,r-1),DP(it.second,b,r-1));
			min+=it.first;
			ret=std::min(ret,min);
		}
	}
	return ret;
}
int main() {
	int u,v,w;
	scanf("%d %d %d",&n,&k,&m);
	for(int i=0;i<m;i++) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(ip(w,v));
	}
	memset(cache, -1,sizeof(cache));

	int ret=INF;
	for(int i=1;i<=n;i++) {
		int min=std::min(DP(i,0,k-1),DP(i,n+1,k-1));
		ret=std::min(ret,min);
	}
	if(ret>=INF) printf("-1\n");
	else printf("%d\n",ret);
	return 0;
}