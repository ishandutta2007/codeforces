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
typedef long long ll;
const int maxn=(1e5)+10;
int T,m;
ll d[maxn],n,a[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=m;i++) read(a[i]);
		sort(a+1,a+m+1);
		for (int i=1;i<m;i++) d[i]=a[i+1]-a[i]-1;
		d[m]=n-(a[m]-a[1]+1);
		sort(d+1,d+m+1);
		reverse(d+1,d+m+1);
		//for (int i=1;i<=m;i++) printf("%lld ",d[i]); puts("");
		int now=0; ll ans=0;
		for (int i=1;i<=m;i++) {
			ans+=max(0LL,d[i]-now-now-1);
			if (d[i]==now+now+1) ans++;
			now+=2;
		}
		printf("%lld\n",n-ans);
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