#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional> 
#include <stack>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m,q,pa[400001];
int find(int cur) {
	return cur==pa[cur] ? cur : pa[cur]=find(pa[cur]);
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n+m;i++) pa[i]=i;
	for(int i=0;i<q;i++) {
		int r,c;
		scanf("%d%d",&r,&c);
		
		int pu=find(r),pv=find(c+n);
		if(pu!=pv) pa[pv]=pu;
	}
	int ans=0;
	for(int i=1;i<=n+m;i++) if(find(i)==i) ans++;
	printf("%d\n",ans-1);
	return 0;
}