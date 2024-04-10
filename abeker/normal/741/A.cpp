#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 105;

int N;
int a[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

int order(int x) {
	int y = x;
	for (int i = 1; i <= N; i++) {
		y = a[y];
		if (y == x)
			return i;
	}
	return -1;
}

ll solve() {
	ll res = 1;
	for (int i = 1; i <= N; i++) {
		int tmp = order(i);
		if (tmp == -1)
			return -1;
		res = res / __gcd(res, (ll)tmp) * tmp;
	}
	return res % 2 ? res : res / 2;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}