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
int T,n,a[maxn],p[maxn];
int lst[maxn],mat[maxn];
int fa[maxn],vis[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) lst[i]=0,p[i]=fa[i]=i;
		int now=1;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (lst[a[i]]) p[now]=lst[a[i]],p[n-now+1]=i,lst[a[i]]=0,now++;
			else lst[a[i]]=i;
		}
		if (n%2==0) { if (now!=n/2+1) { puts("NO"); continue; } }
		if (n%2==1) {
			int fd=0,cnt=0;
			for (int i=1;i<=n;i++) if (lst[i]) fd=lst[i],cnt++;
			if (cnt>1) { puts("NO"); continue; }
			p[now]=fd;
		}
		for (int i=1;i<=n;i++) fa[find(p[i])]=find(i);
		//for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		for (int i=1;i<n-i+1;i++) if (find(i)!=find(n-i+1)) {
			swap(p[i],p[n-i+1]);
			fa[find(i)]=find(n-i+1);
		}
		//for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		for (int i=2;i<n-i+1;i++) if (find(i)!=find(1)) {
			int x=p[i],y=p[n-i+1];
			p[n-i+1]=p[n];
			p[i]=p[1];
			p[1]=y,p[n]=x;
			fa[find(i)]=find(1);
		}
		if (n%2==1&&p[n/2+1]==n/2+1) {
			int fd=0;
			for (int i=1;i<=n;i++) if (i!=n/2+1&&a[p[i]]==a[n/2+1]) { fd=i; break; }
			if (!fd) { puts("NO"); continue; }
			swap(p[fd],p[n/2+1]);
		}
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=1,x=1;i<=n;i++,x=p[x]) {
			assert(!vis[x]);
			vis[x]=1;
		}
		//for (int i=1;i<=n;i++) printf("%d ",a[p[i]]); puts("");
	}
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