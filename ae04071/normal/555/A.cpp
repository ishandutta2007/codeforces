#include <cstdio>
#include <algorithm>
#include <vector>

#define sz(x) ((int)x.size())
using namespace std;

int n,m;
vector<int> adj[100001];
int main() {
	scanf("%d%d",&n,&m);
	
	int ans=0,mx=1;
	for(int i=0;i<m;i++) {
		int s;
		scanf("%d",&s);
		while(s--) {
			int val;
			scanf("%d",&val);
			adj[i].push_back(val);
		}
		if(adj[i][0]==1) {
			for(int j=1;j<sz(adj[i]);j++) {
				if(adj[i][j]!=mx+1) {
					ans += sz(adj[i])-j;
					break;
				}
				mx++;
			}
		} else {
			ans+=sz(adj[i])-1;
		}
	}
	printf("%d\n",ans + n-mx);
	return 0;
}