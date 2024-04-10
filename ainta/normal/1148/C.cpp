#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pii pair<int,int>
int n;
int w[301000], Loc[301000];
vector<pii>Res;
void Go(int a, int b) {
	Res.push_back({ a,b });
	swap(Loc[w[a]], Loc[w[b]]);
	swap(w[a], w[b]);
}
void Swap(int a, int b) {
	if (abs(b - a) * 2 >= n) {
		Go(a, b);
		return;
	}
	if (a <= n/2) {
		if (b <= n/2) {
			Go(b, n);
			Go(a, n);
		}
		else {
			Go(b, 1);
			Go(1, n);
			Go(a, n);
		}
	}
	else {
		if (b <= n / 2) {
			Go(b, n);
			Go(1, n);
			Go(1, a);
		}
		else {
			Go(b, 1);
			Go(a, 1);
		}
	}
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Loc[w[i]] = i;
	}
	for (i = 1; i <= n; i++) {
		if (Loc[i] != i) {
			Swap(i, Loc[i]);
		}
	}
	printf("%d\n", Res.size());
	for (auto &t : Res) {
		printf("%d %d\n", t.first, t.second);
	}
//	for (i = 1; i <= n; i++)printf("%d ", w[i]);
}