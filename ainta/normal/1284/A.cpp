#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
char p[30][1010], q[30][1010];
int main() {
	int i;
	scanf("%d%d", &n,&m);
	for (i = 0; i < n; i++) {
		scanf("%s", p[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%s", q[i]);
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		long long x;
		scanf("%lld", &x);
		x--;
		printf("%s%s\n", p[x%n], q[x%m]);
	}
}