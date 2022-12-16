#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,int> pii;
int n,a[100001],vis[100001];
vector<pii> ans;
vector<int> gv[100001];

void dfs(int cur,int g) {
	vis[cur]=g;
	gv[g].push_back(cur);
	if(!vis[a[cur]]) dfs(a[cur],g);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);

	int g=1;
	for(int i=1;i<=n;i++) if(!vis[i]) {
		dfs(i,g++);
	}

	int r=-1;
	for(int i=1;i<g;i++) if((int)gv[i].size() == 1) {
		r=i;
		break;
	}

	if(r!=-1) {
		for(int i=1;i<g;i++) if(i!=r) {
			for(auto &it:gv[i]) ans.push_back(pii(gv[r][0],it));
		}
	} else {
		int f=0;
		for(int i=1;i<g;i++) {
			if((int)gv[i].size()%2!=0) {
				f=1;
				break;
			}
			if((int)gv[i].size()==2 && r==-1) {
				r=i;
			}
		}
		if(!f && r!=-1) {
			for(int i=1;i<g;i++) if(i!=r) {
				int c=0;
				for(auto &it:gv[i]) ans.push_back(pii(gv[r][c],it)),c=(c+1)%2;
			}
			ans.push_back(pii(gv[r][0],gv[r][1]));
		} else r=-1;
	}

	if(r==-1) puts("NO");
	else {
		puts("YES");
		for(auto &it:ans) printf("%d %d\n",it.first,it.second);
	}

	return 0;
}