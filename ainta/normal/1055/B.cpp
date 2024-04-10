#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, L;
long long w[101000], P[101000], res;
long long Get(int a) {
	return P[a] - min(P[a], P[a - 1]);
}
void Add(int a, long long d) {
	res -= Get(a) + Get(a + 1);
	w[a] += d;
	P[a] = min((w[a] + L - 1) / L - 1,1ll);
	res += Get(a) + Get(a + 1);
}
int main() {
	//freopen("input.txt", "r", stdin);
	int i, a, b;
	scanf("%d%d%d", &n, &m, &L);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		Add(i, a);
	}
	while (m--) {
		scanf("%d", &a);
		if (!a)printf("%lld\n", res);
		else {
			scanf("%d%d", &a, &b);
			Add(a, b);
		}
	}
}