#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define SZ 524288
#define pii pair<int,int>
set<int>Set;
vector<int>U[501000];
int n, m, Q, C[501000], Res[501000], IT[SZ+SZ];
struct Query {
	int num;
	long long x;
	bool operator <(const Query &p)const {
		return x < p.x;
	}
}T[501000];
void Add(int a, int b) {
	a += SZ;
	while (a) {
		IT[a] += b;
		a >>= 1;
	}
}
int Get(int c) {
	int nd = 1;
	while (nd < SZ) {
		if (IT[nd * 2] < c) {
			c -= IT[nd * 2];
			nd = nd * 2 + 1;
		}
		else nd *= 2;
	}
	return nd - SZ;
}
int main() {
	int i, a;
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		C[a]++;
	}
	for (i = 1; i <= Q; i++) {
		scanf("%lld", &T[i].x);
		T[i].num = i;
	}
	sort(T + 1, T + Q + 1);
	for (i = 1; i <= m; i++)U[C[i]].push_back(i);
	int pv = 1;
	long long cur = n;
	for (i = 0; i <= n; i++) {
		for (auto &x : U[i]) {
			Set.insert(x);
			Add(x, 1);
		}
		int sz = Set.size();
		while (pv <= Q && T[pv].x <= cur + sz) {
			Res[T[pv].num] = Get(T[pv].x - cur);
			pv++;
		}
		cur += sz;
	}
	while (pv <= Q) {
		Res[T[pv].num] = Get((T[pv].x - cur - 1) % m + 1);
		pv++;
	}
	for (i = 1; i <= Q; i++)printf("%d\n", Res[i]);

}