#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=3e5+10;

int l[N], r[N], a[N], b[N];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
//		memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r));
		int n; scanf("%d", &n);
		for (int i=1; i<=n; i++) scanf("%d", a+i);
		for (int i=1; i<=n; i++) {
			if (!l[a[i]]) l[a[i]]=i;
			r[a[i]]=i;
		}
		for (int i=1; i<=n; i++) b[i]=a[i];
		sort(b+1, b+1+n);
		int m=unique(b+1, b+1+n)-b-1;
//		for (int i=1; i<=m; i++) printf("%d %d %d\n", b[i], l[b[i]], r[b[i]]);
		int cnt=1, ans=0;
		for (int i=2; i<=m; i++) {
			if (r[b[i-1]]>l[b[i]]) {ans=max(ans, cnt); cnt=0;}
			cnt++;
		}
		for (int i=1; i<=m; i++) l[b[i]]=r[b[i]]=0;
		ans=max(ans, cnt);
		printf("%d\n", m-ans);
	}
	return 0;
}