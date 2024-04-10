#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,a,b,x;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(x);
		if (x==1) b++; else a++;
	}
	if (a) a--,printf("2 ");
	if (b) b--,printf("1 ");
	for (int i=1;i<=a;i++) printf("2 ");
	for (int i=1;i<=b;i++) printf("1 ");
	printf("\n");
	return 0;
}