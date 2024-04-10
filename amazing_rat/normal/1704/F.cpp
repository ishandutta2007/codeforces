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
const int maxn=(5e5)+10;
int T,n;
char s[maxn];
int sg[maxn];
bool vis[maxn];

int main() {
	int bd=200;
	for (int i=2;i<=bd;i++) {
		for (int j=0;j<=1000;j++) vis[j]=0;
		for (int j=0;j+2<=i;j++) vis[sg[j]^sg[i-j-2]]=1;
		while (vis[sg[i]]) sg[i]++;
	}
	for (int i=bd+1;i<maxn;i++) sg[i]=sg[i-34];
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		int c0=0,c1=0;
		for (int i=1;i<=n;i++) if (s[i]=='R') c0++; else c1++;
		if (c0==c1) {
			int ans=0,cnt=0;
			for (int i=1;i<=n;i++) {
				if (i==1||s[i]!=s[i-1]) cnt++;
				else ans^=sg[cnt],cnt=1;
			}
			ans^=sg[cnt];
			if (ans) puts("Alice"); else puts("Bob");
		} else if (c0>c1) puts("Alice"); else puts("Bob");
	}
	return 0;
}