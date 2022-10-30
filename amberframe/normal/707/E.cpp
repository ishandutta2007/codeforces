#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int maxn = 2005;
int n,m,k,q,val[maxn][maxn];
vector<mp> pos[maxn];
struct bi{
	LL sum[maxn][maxn];
	void modify(int x,int y,int val) {
		for (int i=x;i<=n;i+=i&-i)
		for (int j=y;j<=m;j+=j&-j)
			sum[i][j]+=val;
	}
	LL query(int x,int y) {
		LL res=0;
		for (int i=x;i;i-=i&-i)
		for (int j=y;j;j-=j&-j)
			res+=sum[i][j];
		return res;
	}
}bi;
struct qnode{
	int x1,y1,x2,y2;
	int st[maxn];
	LL ans;
}que[maxn];
char str[maxn];int tot,st[maxn];
int main() {
	#ifndef ONLINE_JUDGE
		freopen("garlands.in","r",stdin);
		freopen("garlands.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=k;i++) {
		int cnt;scanf("%d",&cnt);
		for (int x,y,w,j=1;j<=cnt;j++)
			scanf("%d %d %d",&x,&y,&w),val[x][y]=w,
			pos[i].pb(mp(x,y));
	}
	scanf("%d",&q);
	for (int i=1;i<=k;i++) st[i]=1;
	for (int i=1;i<=q;i++) {
		scanf("%s",str);
		if (*str=='A') {
			++tot;
			scanf("%d %d",&que[tot].x1,&que[tot].y1);
			scanf("%d %d",&que[tot].x2,&que[tot].y2);
			for (int j=1;j<=k;j++)
				que[tot].st[j]=st[j];
		}
		else {
			int w;scanf("%d",&w);st[w]^=1;
		}
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<pos[i].size();j++) {
			int x=pos[i][j].first;
			int y=pos[i][j].second;
			bi.modify(x,y,val[x][y]);
		}
		for (int j=1;j<=tot;j++)
		if (que[j].st[i]) {
			que[j].ans+=bi.query(que[j].x2,que[j].y2);
			que[j].ans+=bi.query(que[j].x1-1,que[j].y1-1);
			que[j].ans-=bi.query(que[j].x2,que[j].y1-1);
			que[j].ans-=bi.query(que[j].x1-1,que[j].y2);
		}
		for (int j=0;j<pos[i].size();j++) {
			int x=pos[i][j].first;
			int y=pos[i][j].second;
			bi.modify(x,y,-val[x][y]);
		}
	}
	for (int i=1;i<=tot;i++)
		printf("%I64d\n",que[i].ans);
	return 0;
}