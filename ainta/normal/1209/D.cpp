#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, UF[101000], res, m;
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
int main() {
	int i, a, b;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++)UF[i] = i;
	res = m;
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		if (Find(a) != Find(b)) {
			UF[Find(a)] = Find(b);
			res--;
		}
	}
	printf("%d\n", res);
}