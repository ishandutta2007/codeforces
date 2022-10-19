#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
int n,a[1010];
int sum=INF,ans,cnt;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=101;i++) {
		cnt=0; for (int j=1;j<=n;j++)
			cnt+=min(abs(a[j]-i),min(abs(a[j]-(i-1)),abs(a[j]-(i+1))));
		if (cnt<sum) sum=cnt,ans=i;
	} printf("%d %d\n",ans,sum);
	return 0;
}