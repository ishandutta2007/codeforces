#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,k,a[110],ans,sum;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=k;i++) {
		sum=0;
		for (int j=1;j<=n;j++) {
			if (j%k==i%k) continue;
			if (a[j]==1) sum++; else sum--;
		}
		ans=max(ans,abs(sum));
	}
	printf("%d\n",ans);
	return 0;
}