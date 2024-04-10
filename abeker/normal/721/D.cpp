#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N, K, X;
ll a[MAXN];

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (abs(a[lhs]) != abs(a[rhs]))
			return abs(a[lhs]) < abs(a[rhs]);
		return lhs < rhs;
	}
};

set <int, cmp> S;

void load() {
	scanf("%d%d%d", &N, &K, &X);
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
}

void solve() {
	int neg = 0;
	for (int i = 0; i < N; i++) {
		S.insert(i);
		neg ^= a[i] < 0;
	}
	
	while (K--) {
		int x = *S.begin();
		S.erase(x);
		if (neg) {
			if (a[x] < 0) a[x] -= X;
			else a[x] += X;
		}
		else {
			neg ^= a[x] < 0;
			if (a[x] < 0) a[x] += X;
			else a[x] -= X;
			neg ^= a[x] < 0;
		}
		S.insert(x);
	}
	
	for (int i = 0; i < N; i++)
		printf("%lld ", a[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}