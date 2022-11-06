#include <cstdio>
using namespace std;

const int N=2e5+10;

int a[N];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int h, n, ans=0; scanf("%d%d", &h, &n);
		for (int i=1; i<=n; i++) scanf("%d", a+i);
		a[++n]=0;
		for (int i=1; i<n-1; i++) {
//			printf("%d %d\n", a[i], ans);
			if (a[i+1]==a[i]-1) {
				if (a[i+2]!=a[i]-2) {ans++, a[i+1]=a[i+2]+1;}
				else i++;
			}
			else {a[i]=a[i+1]+1; i--;}
		}
//		printf("%d\n", a[n-1]);
//		if (a[n-1]>2) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
/*
1
8 5
9 8 7 6 3
*/