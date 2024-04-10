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
typedef unsigned long long ll;
const int maxn=(1e6)+10;
int T,n,m;
ll rem[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		ll x=-1,y=-1;
		for (int i=0;i<n;i++) {
			ll sum=0,all=0;
			for (int j=0;j<m;j++) {
				ll x; read(x);
				sum+=x;
				all+=sum;
			}
			if (i==0) x=all;
			else if (x!=all) y=all;
			rem[i]=all;
		}
		int cnt=0;
		for (int i=0;i<n;i++) if (rem[i]==x) cnt++;
		if (cnt==n-1) swap(x,y);
		int fd;
		for (int i=0;i<n;i++) if (rem[i]==x) { fd=i; break; }
		write(fd+1),putchar(' '),writeln(y-x);
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