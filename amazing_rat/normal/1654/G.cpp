// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(2e5)+10;
int n,h[maxn];
int hd,tl,q[maxn];
vector<int> g[maxn],V[maxn];
int ans[maxn],mk[maxn];
int dis[maxn],Q[maxn],tl2;
bool cmp(int x,int y) { return dis[x]<dis[y]; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) h[i]=-1;
	int x,y;
	for (int i=1;i<=n;i++) {
		read(x); if (x) h[i]=0,q[++tl]=i;
	}
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	while (hd<=tl) {
		x=q[hd]; hd++;
		for (int &y : g[x]) if (h[y]==-1) h[y]=h[x]+1,q[++tl]=y;
	}
	for (int i=1;i<=n;i++) {
		int flag=0;
		for (int &j : g[i]) if (h[i]==h[j]) { flag=1; break; }
		if (flag) V[h[i]].push_back(i);
		ans[i]=h[i];
		//printf("%d %d %d\n",i,h[i],flag);
	}
	for (int i=0;i<=n;i++) if ((int)V[i].size()) {
		for (int j=1;j<=n;j++) mk[j]=0,dis[j]=1e9;
		tl=0;
		for (int &x : V[i]) dis[x]=0,mk[x]=1,q[++tl]=x;
		while (tl) {
			for (int j=1;j<=tl;j++) {
				x=q[j];
				for (int &y : g[x])
					if (h[y]==h[x]) {
						if (dis[y]>dis[x]+1) dis[y]=dis[x]+1,q[++tl]=y;
					} else if (h[y]==h[x]+1) dis[y]=min(dis[y],max(0,dis[x]-1));
			}
			tl2=0;
			for (int j=1;j<=tl;j++) {
				x=q[j];
				for (int &y : g[x]) if (h[y]==h[x]+1&&!mk[y]) mk[y]=1,Q[++tl2]=y;
			}
			sort(Q+1,Q+tl2+1,cmp);
			for (int j=1;j<=tl2;j++) q[j]=Q[j]; tl=tl2;
		}
		for (int j=1;j<=n;j++) if (mk[j]&&dis[j]==0) ans[j]=min(ans[j],i);
	}
	for (int i=1;i<=n;i++) printf("%d ",2*h[i]-ans[i]); puts("");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/