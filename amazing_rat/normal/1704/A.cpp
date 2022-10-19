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
const int maxn=100;
int T,n,m;
char s[maxn],t[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		scanf("%s",s+1);
		scanf("%s",t+1);
		int flag=1;
		for (int i=m,j=n;i>=2;i--,j--) flag&=(t[i]==s[j]);
		if (!flag) { puts("NO"); continue; }
		if (n==m) { if (s[1]==t[1]) puts("YES"); else puts("NO"); continue; }
		int c0=(min(s[1]-'0',s[2]-'0')==0);
		int c1=(max(s[1]-'0',s[2]-'0')==1);
		for (int i=3;i<=n-m+1;i++) {
			int t=(s[i]-'0');
			int a=0,b=0;
			if (c0) a|=1,b|=(t==1);
			if (c1) a|=(t==0),b|=1;
			c0=a,c1=b;
		}
		if (t[1]=='1') { if (c1) puts("YES"); else puts("NO"); }
		else if (c0) puts("YES"); else puts("NO");
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