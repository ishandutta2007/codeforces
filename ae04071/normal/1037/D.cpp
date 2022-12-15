#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

int n,val[200001],pa[200001],arr[200001];
vector<int> adj[200001];

void make(int cur,int p) {
	pa[cur]=p;
	for(auto &it:adj[cur]) if(it!=p) make(it,cur);
}

int main() {
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	make(1,0);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	
	set<pii> tr;
	tr.insert(pii(0,0));
	val[0]=1;
	
	int i=0,j=0;
	for(;i<n;i++) {
		if(tr.begin()->second != pa[arr[i]]) {
			puts("NO");
			return 0;
		}
		val[tr.begin()->first]--;
		if(val[tr.begin()->first]==0) {
			tr.erase(tr.begin());
			if(tr.empty()) {
				int c=0;
				for(;j<=i;j++,c++) {
					val[c] = (int)adj[arr[j]].size() - (arr[j]!=1);
					if(!val[c]){
						c--;
						continue;
					}
					tr.insert(pii(c,arr[j]));
				}
			}
		}
	}
	puts("YES");
	
	return 0;
}