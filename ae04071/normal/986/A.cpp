#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define ALL(x) x.begin(),x.end()

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int inf=1e9;
int dist[101][100001];
int n,m,k,s,arr[100001],vis[100001];
vector<int> adj[100001];

int d[101];

void Dijk(int s) {
	queue<int> que;
	fill(vis,vis+n+1,0);
	for(int i=1;i<=n;i++) if(arr[i]==s) {
		que.push(i);
		dist[s][i] = 0;
		vis[i]=1;
	}
	while(!que.empty()) {
		int cur=que.front();que.pop();
		for(auto &it:adj[cur]) {
			if(!vis[it]) {
				vis[it]=1;
				que.push(it);
				dist[s][it] = dist[s][cur]+1;
			}
		}
	}
}
int get(int cur) {
	fill(d,d+s,inf);
	
	for(int i=1;i<=k;i++) {
		d[i-1] = dist[i][cur];
	}
	sort(d,d+k);

	int res=0;
	for(int i=0;i<s;i++) res += d[i];
	return res;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=k;i++) Dijk(i);
	for(int i=1;i<=n;i++) printf("%d ",get(i));
	return 0;
}