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
int T,n,a[1010],ans;
int x,y,z;
void del(int b) {
	if (x==b) x=0;
	else if (y==b) y=0;
	else if (z==b) z=0;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		if (n==2) { printf("%d\n",a[1]+a[2]); continue; }
		x=y=z=0; vector<int> V;
		for (int i=1;i<n;i++) V.push_back(a[i]+a[i+1]);
		sort(V.begin(),V.end());
		reverse(V.begin(),V.end());
		while ((int)V.size()<3) V.push_back(0);
		int ans=V[0];
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
			x=V[0],y=V[1],z=V[2];
			if (i>1) del(a[i-1]+a[i]);
			if (j<n) del(a[j]+a[j+1]);
			int tmp=max(max(x,y),z);
			if (i>1) tmp=max(tmp,a[i-1]+a[j]);
			if (j<n) tmp=max(tmp,a[j+1]+a[i]);
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
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