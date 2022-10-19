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
const int maxn=(1<<18)+5;
int n;
int sa[maxn],rk[maxn];
char s[maxn];
int t;
bool cmp1(int x,int y) { return s[x]<s[y]; }
bool cmp2(int x,int y) { return MP(rk[x],rk[x^t])<MP(rk[y],rk[y^t]); }
int RK[maxn];
int main() {
	read(n);
	int N=(1<<n);
	scanf("%s",s);
	for (int i=0;i<N;i++) sa[i]=i;
	sort(sa,sa+N,cmp1);
	for (int i=1;i<N;i++) rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for (int i=0;i<n;i++) {
		for (int j=0;j<N;j++) sa[j]=j;
		t=(1<<i);
		sort(sa,sa+N,cmp2);
		RK[sa[0]]=0;
		for (int j=1;j<N;j++) RK[sa[j]]=RK[sa[j-1]]+(MP(rk[sa[j-1]],rk[sa[j-1]^t])<MP(rk[sa[j]],rk[sa[j]^t]));
		for (int j=0;j<N;j++) rk[j]=RK[j];
	}
	int x=sa[0];
	for (int i=0;i<N;i++) printf("%c",s[x^i]); puts("");
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