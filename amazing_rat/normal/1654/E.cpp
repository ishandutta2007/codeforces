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
int n;
int a[maxn];
ll b[maxn];
int ans;
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	int B=400,len=100000/B+5;
	for (int d=-B;d<=B;d++) {
		for (int i=1;i<=n;i++) b[i]=a[i]-(ll)d*i;
		sort(b+1,b+n+1);
		int cnt=0;
		for (int i=1;i<=n;i++) {
			if (i==1||b[i]!=b[i-1]) ans=max(ans,cnt),cnt=1;
			else cnt++;
		}
		ans=max(ans,cnt);
	}
	for (int i=1;i<=n;i++) {
		int tot=0;
		for (int j=i+1;j<=n&&j<=i+len-1;j++) if (abs(a[j]-a[i])%(j-i)==0) {
			b[++tot]=(a[j]-a[i])/(j-i);
			//if (i==1) printf("%lld\n",b[tot]);
		}
		sort(b+1,b+tot+1);
		int cnt=0;
		for (int j=1;j<=tot;j++) {
			if (j==1||b[j]!=b[j-1]) ans=max(ans,cnt+1),cnt=1;
			else cnt++;
		}
		ans=max(ans,cnt+1);
	}
	printf("%d\n",n-ans);
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