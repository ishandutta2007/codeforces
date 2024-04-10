#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=5010;
int n,m,a[maxn],b[maxn],ans;
int dis(int x,int y) {
	if (x<=y) return y-x;
	return y-x+n;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); int x,y;
	for (int i=1;i<=n;i++) b[i]=n+1;
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		a[x]++; b[x]=min(b[x],dis(x,y));
	}
	for (x=1;x<=n;x++) {
		ans=0;
		for (int i=1;i<=n;i++) {
			if (!a[i]) continue;
			ans=max(ans,dis(x,i)+b[i]+n*(a[i]-1));
		}
		printf("%d ",ans);
	} printf("\n");
	return 0;
}