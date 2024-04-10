#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,b,k;
int a[maxn];
int ksm(int x,int y) {
	if (y==0) return 1;
	return x%2;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(b); read(k);
	for (int i=1;i<=k;i++) read(a[i]),a[i]%=2;
	for (int i=1;i<=k;i++) {
		n+=a[i]*ksm(b,k-i); n%=2;
	}
	if (!n) printf("even\n");
	else printf("odd\n");
	return 0;
}