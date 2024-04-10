#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n;
int a[20];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int t=0;t<(1<<n);t++) {
		int s1=0,s2=0;
		for (int i=1;i<=n;i++)
			if (t&(1<<(i-1))) s1+=a[i];
			else s2+=a[i];
		if (abs(s2-s1)%360==0) {
			printf("YES\n"); return 0;
		}
	}
	printf("NO\n");
	return 0;
}