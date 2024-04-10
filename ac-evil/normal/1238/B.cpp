#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1e5+10;

int a[N];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n, r, ans=0, i; scanf("%d%d", &n, &r);
		for (i=1; i<=n; i++) scanf("%d", a+i);
		sort(a+1, a+1+n);
		n=unique(a+1, a+1+n)-a-1;
		for (i=n; i; i--) if (a[i]<=(n-i)*r) break;
		printf("%d\n", n-i);
	}
	return 0;
}
/*
1
6 1
3 3 3 5 5 7
*/