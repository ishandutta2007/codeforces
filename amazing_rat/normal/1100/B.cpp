#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,m,s,x,cnt[maxn],delta,v[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=m;i++) {
		read(x);
		if (cnt[x]-delta==0) s++;
		cnt[x]++; v[cnt[x]-1]--; v[cnt[x]]++;
		if (s==n) {
			printf("1");
			delta++;
			s-=v[delta];
		} else printf("0");
	} printf("\n");
	return 0;
}