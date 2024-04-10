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
int n,a[maxn];
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		int f0=0,f1=0,f2=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]==0) f0=1;
			if (a[i]==1) f1=1;
			if (a[i]==2) f2=1;
		}
		if (f0&&f1) puts("NO");
		else if (f1&&f2) puts("NO");
		else if (!f1) puts("YES");
		else {
			sort(a+1,a+n+1);
			n=unique(a+1,a+n+1)-a-1;
			int flag=1;
			for (int i=2;i<=n;i++) if (a[i]==a[i-1]+1) { flag=0; break; }
			if (flag) puts("YES");
			else puts("NO");
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