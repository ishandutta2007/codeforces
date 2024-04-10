#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n/2;i++)
		for (int j=1;j<=m;j++)
			printf("%d %d\n",i,j),
			printf("%d %d\n",n-i+1,m-j+1);
	if (n&1) {
		for (int j=1;j<=m/2;j++)
			printf("%d %d\n",n/2+1,j),
			printf("%d %d\n",n/2+1,m-j+1);
		if (m&1) printf("%d %d\n",n/2+1,m/2+1);
	}
	return 0;
}