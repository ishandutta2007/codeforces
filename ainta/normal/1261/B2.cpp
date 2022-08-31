#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
vector<pii>V;
int n, w[201000];
struct Query {
	int c, a, num;
	bool operator<(const Query &p)const {
		return c < p.c;
	}
};
vector<Query>Q;
int BIT[201000];
void Add(int a, int b) {
	while (a <= n) {
		BIT[a] += b;
		a += (a&-a);
	}
}
int Sum(int a) {
	int r = 0;
	while (a) {
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
int Res[201000];
int Get(int a) {
	int b = 1, e = n, r = 0, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Sum(mid) >= a) {
			r = mid;
			e = mid - 1;
		}
		else b = mid + 1;
	}
	return r;
}
int main() {
	int i, K;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		V.push_back({ -w[i],i });
	}
	sort(V.begin(), V.end());
	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Q.push_back({ a,b,i + 1 });
	}
	sort(Q.begin(), Q.end());
	int pv = 1;
	for (auto &t : Q) {
		while (pv <= n && pv <= t.c) {
			Add(V[pv - 1].second, 1);
			pv++;
		}
		Res[t.num] = Get(t.a);
	}
	for (i = 1; i <= K; i++)printf("%d\n", w[Res[i]]);
}