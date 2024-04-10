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
typedef __int128 ll;
const int maxn=1010;
int T,n,m;
ll a[maxn],b[maxn];
ll d[maxn][maxn],e[maxn][maxn];
ll gcd(ll x,ll y) {
	if (y) return gcd(y,x%y);
	return x;
}
int q1[maxn],hd1,tl1;
int q2[maxn],hd2,tl2;
int v1[maxn],v2[maxn];
struct Seg {
	int op;
	ll tr[maxn][maxn*4];
	void build(int x,int l,int r,int root) {
		if (l==r) { if (!op) tr[x][root]=d[x][l]; else tr[x][root]=e[x][l]; return; }
		int mid=(l+r)>>1;
		build(x,l,mid,root<<1),build(x,mid+1,r,root<<1|1);
		tr[x][root]=gcd(tr[x][root<<1],tr[x][root<<1|1]);
	}
	void del(int x,int y,int l,int r,int root) {
		if (l==r) { tr[x][root]=0; return; }
		int mid=(l+r)>>1;
		if (y<=mid) del(x,y,l,mid,root<<1);
		else del(x,y,mid+1,r,root<<1|1);
		tr[x][root]=gcd(tr[x][root<<1],tr[x][root<<1|1]);
	}
} T1,T2;
int main() {
	read(T); while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(a[i]),v1[i]=0;
		for (int i=1;i<=m;i++) read(b[i]),v2[i]=0;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			ll g=gcd(a[i],b[j]);
			d[i][j]=a[i]/g,e[j][i]=b[j]/g;
		}
		T1.op=0,T2.op=1; hd1=hd2=1,tl1=tl2=0;
		for (int i=1;i<=n;i++) {
			T1.build(i,1,m,1);
			if (T1.tr[i][1]>1) q1[++tl1]=i,v1[i]=1;
		}
		for (int i=1;i<=m;i++) {
			T2.build(i,1,n,1);
			if (T2.tr[i][1]>1) q2[++tl2]=i,v2[i]=1;
		}
		while (hd1<=tl1||hd2<=tl2) {
			if (hd1<=tl1) {
				int x=q1[hd1]; hd1++;
				for (int i=1;i<=m;i++) if (!v2[i]) {
					T2.del(i,x,1,n,1);
					if (T2.tr[i][1]>1) q2[++tl2]=i,v2[i]=1;
				}
			}
			if (hd2<=tl2) {
				int x=q2[hd2]; hd2++;
				for (int i=1;i<=n;i++) if (!v1[i]) {
					T1.del(i,x,1,m,1);
					if (T1.tr[i][1]>1) q1[++tl1]=i,v1[i]=1;
				}
			}
		}
		if (tl1==n||tl2==m) puts("NO");
		else {
			puts("YES");
			printf("%d %d\n",n-tl1,m-tl2);
			for (int i=1;i<=n;i++) if (!v1[i]) write(a[i]),putchar(' '); puts("");
			for (int i=1;i<=m;i++) if (!v2[i]) write(b[i]),putchar(' '); puts("");
		}
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