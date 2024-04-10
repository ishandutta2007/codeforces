#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+10;
int n,a[maxn];
ll ans;
ll sqr(int x) {
	return (ll)x*x;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n/2;i++)
		ans+=sqr(a[i]+a[n-i+1]);
	printf("%lld\n",ans);
	return 0;
}