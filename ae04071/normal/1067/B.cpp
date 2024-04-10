#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef long long lli;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

vector<int> adj[100001];
int n,k,vis[100001],cnt[100001],de[100001];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> que;
	int c=0;
	for(int i=1;i<=n;i++) if(sz(adj[i])==1) {
		que.push(i);
		vis[i]=1;
		c++;
		de[i]=1;
	}

	for(int t=0;t<k;t++) {
		int s=sz(que),f=0;
		if(que.empty()) {
			puts("No");
			return 0;
		}

		while(s--) {
			int cur=que.front();que.pop();
			int tmp=0,tt=0;
			for(auto &it:adj[cur]) {
				if(!vis[it]) {
					if(tmp) {
						puts("No");
						return 0;
					}
					tmp=1;
					cnt[it]++;
					if(cnt[it]==1) f++;
					if(cnt[it]==3) {
						que.push(it);
						de[it]=de[cur]+1;
						c++;
						f--;
					}
				} else {
					if(de[it]!=de[cur]-1) {
						puts("No");
						return 0;
					}
				}
			}
		}
		if(f) {
			puts("No");
			return 0;
		}

		s=sz(que);
		while(s--) {
			int cur=que.front();que.pop();
			vis[cur]=1;
			que.push(cur);
		}
	}

	if(c!=n || sz(que)!=1) puts("No");
	else puts("Yes");

	return 0;
}