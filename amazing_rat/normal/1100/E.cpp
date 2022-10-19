#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,x[maxn],y[maxn],z[maxn];
int tot,head[maxn],in[maxn],d[maxn];
int nxt[maxn],to[maxn],cnt,ans[maxn];
void add(int a,int b) {
	tot++; nxt[tot]=head[a];
	head[a]=tot; to[tot]=b;
}
queue<int> q;
bool solve(int mid) {
	tot=0; memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	for (int i=1;i<=m;i++)
		if (z[i]>mid)
			add(x[i],y[i]),in[y[i]]++;
	for (int i=1;i<=n;i++)
		if (!in[i]) q.push(i);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		for (int i=head[u],v;i;i=nxt[i]) {
			v=to[i]; in[v]--;
			if (!in[v]) q.push(v);
		}
	}
	for (int i=1;i<=n;i++)
		if (in[i]) return 1;
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=m;i++)
		read(x[i]),read(y[i]),read(z[i]);
	int l=0,r=(1e9),mid,res;
	while (l<=r) {
		mid=(l+r)>>1;
		if (solve(mid)) l=mid+1;
		else r=mid-1,res=mid;
	}
	
	tot=0; memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	for (int i=1;i<=m;i++)
		if (z[i]>res)
			add(x[i],y[i]),in[y[i]]++;
	for (int i=1;i<=n;i++)
		if (!in[i]) q.push(i);
	while (!q.empty()) {
		int u=q.front(); q.pop(); d[u]=++cnt;
		for (int i=head[u],v;i;i=nxt[i]) {
			v=to[i]; in[v]--;
			if (!in[v]) q.push(v);
		}
	}
	for (int i=1;i<=n;i++)
		if (!d[i]) d[i]=++cnt;
	cnt=0; for (int i=1;i<=m;i++)
		if (d[x[i]]>d[y[i]])
			ans[++cnt]=i;
	printf("%d %d\n",res,cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d ",ans[i]); printf("\n");
	return 0;
}