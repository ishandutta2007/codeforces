#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,s,a[maxn],b[maxn];
vector<vector<int> > ans;
map<int,vector<int> > g;
void dfs(int u) {
	while (!g[u].empty()) {
		int v=g[u].back(); g[u].pop_back();
		dfs(a[v]); ans.back().push_back(v);
	}
	g.erase(u);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(s);
	for (int i=1;i<=n;i++) {
		read(a[i]); b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) {
		if (a[i]!=b[i])
			g[b[i]].push_back(i);
	}
	while (!g.empty()) {
		ans.push_back(vector<int>());
		dfs((*g.begin()).first);
		reverse(ans.back().begin(),ans.back().end());
		s-=ans.back().size();
	}
	if (s<0) { printf("-1\n"); return 0; }
	int tmp=(int)ans.size(),b=min(s,tmp);
	if (b>=3) tmp-=b-2;
	printf("%d\n",tmp);
	if (b>=3) {
		tmp=0;
		for (int i=0;i<b;i++) tmp+=ans[i].size();
		printf("%d\n",tmp);
		for (int i=0;i<b;i++)
			for (int j=0;j<ans[i].size();j++)
				printf("%d ",ans[i][j]);
		printf("\n");
		printf("%d\n",b);
		for (int i=b-1;i>=0;i--)
			printf("%d ",ans[i][0]);
		printf("\n");
	} else b=0;
	for (int i=b;i<ans.size();i++) {
		printf("%d\n",ans[i].size());
		for (int j=0;j<ans[i].size();j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}