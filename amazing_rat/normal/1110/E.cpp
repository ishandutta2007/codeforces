#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,flag=1;
ll a[maxn],b[maxn];
ll d[maxn],e[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	for (int i=1;i<n;i++)
		d[i]=a[i+1]-a[i];
	for (int i=1;i<n;i++)
		e[i]=b[i+1]-b[i];
	sort(d+1,d+n);
	sort(e+1,e+n);
	for (int i=1;i<n;i++)
		if (d[i]!=e[i]) { flag=0; break; }
	if (a[1]!=b[1]||a[n]!=b[n]) flag=0;
	if (flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}