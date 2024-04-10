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
const int maxn=(1e6)+10;
int T,n,flag,mx,a[maxn];
bool mk[maxn];
int sum[maxn];
int main() {
	read(T); while (T--) {
		read(n); read(mx);
		int fd=0;
		for (int i=1;i<=n;i++) read(a[i]),fd|=(a[i]==1);
		if (!fd) { puts("No"); continue; }
		flag=1;
		for (int i=1;i<=mx;i++) mk[i]=sum[i]=0;
		for (int i=1;i<=n;i++) mk[a[i]]=1,sum[a[i]]++;
		for (int i=1;i<=mx;i++) sum[i]+=sum[i-1];
		for (int i=1;i<=mx&&flag;i++) if (mk[i]) {
			for (int j=1;j<=mx/i+1;j++) if (!mk[j]) {
				int l=j*i,r=j*i+(i-1);
				r=min(r,mx);
				if (l<=r&&sum[r]-sum[l-1]) { flag=0; break; }
			}
		}
		if (flag) puts("Yes"); else puts("No");
		
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