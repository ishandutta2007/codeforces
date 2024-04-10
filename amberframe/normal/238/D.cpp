#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

using namespace std;
typedef long long LL;
#define pb push_back
const int maxn = 1000005;
const int inf = 1<<30;

char str[maxn];
int s[10],f[maxn][10];
int n,q,idx,l[maxn],r[maxn];
void remove(int x) {
	int _l=l[x],_r=r[x];
	l[_r]=_l;r[_l]=_r;
}
bool direct(int x) {
	return str[x]=='<'||str[x]=='>';
}
struct st {
	int minw[maxn*4],val[maxn*4];
	void init() {
		for (int i=1;i<=4*(n+2);i++) minw[i]=inf;
	}
	void modify(int root,int L,int R,int l,int r,int w)
	{
		if (L>=l&&R<=r) {
			minw[root]=min(minw[root],w);return ;
		}
		int mid=L+R>>1;
		if (l<=mid) modify(root<<1,L,mid,l,r,w);
		if (r>mid) modify(root<<1|1,mid+1,R,l,r,w);
	}
	void dfs(int root,int L,int R,int w)
	{
		int mid=L+R>>1;w=min(w,minw[root]);
		if (L>=R) {
			val[L]=w;return ;
		}
		dfs(root<<1,L,mid,w);dfs(root<<1|1,mid+1,R,w);
	}
}ft,gt;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tape.in","r",stdin);
		freopen("tape.out","w",stdout);
	#endif
	scanf("%d %d %s",&n,&q,str+1);str[0]='>';
	for (int i=0;i<=n;i++) r[i]=i+1,l[i+1]=i;
	ft.init();gt.init();
	int cur=0,dir=1,las=n+1;
	while (cur<=n) {
		if (str[cur]=='<') dir=0;
		else if (str[cur]=='>') dir=1;
		else {
			s[str[cur]-'0']++;
			if (str[cur]>'0') str[cur]--;
			else remove(cur);
		}
		las=cur;cur=dir?r[cur]:l[cur];++idx;
		memcpy(f[idx],s,sizeof s);
		if (las&&direct(las)&&direct(cur)) remove(las);
		if (dir==0) gt.modify(1,0,n+1,cur+1,las,idx);
		if (dir==1) ft.modify(1,0,n+1,las+1,cur,idx);
	}
	
	ft.dfs(1,0,n+1,inf);gt.dfs(1,0,n+1,inf);
	for (int _l,_r,i=1;i<=q;i++) {
		scanf("%d %d",&_l,&_r);
		int id=min(gt.val[_l],ft.val[_r+1]);
		for (int j=0;j<10;j++)
			printf("%d ",f[id][j]-f[ft.val[_l]][j]);
		puts("");
	}
	return 0;
}