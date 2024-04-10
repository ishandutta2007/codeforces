#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define N_ 401000
using namespace std;
int n, w[N_];

struct AA {
	int c, a;
	bool operator <(const AA &p)const {
		return c < p.c;
	}
}U[N_];

int A, B;

void UDT(int x, int y) {
	if (A*B<x*y) {
		A = x, B = y;
	}
}

void Solve() {
	int i, j;
	map<int, int>Map;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Map[w[i]]++;
	}
	int cnt = 0;
	for (auto &t : Map) {
		cnt++;
		U[cnt] = { t.second,t.first };
	}
	sort(U + 1, U + cnt + 1);
	int pv = 0, s = 0;
	for (i = 1; i*i <= n; i++) {
		while (pv + 1 <= cnt && U[pv + 1].c <= i) {
			s += U[pv + 1].c;
			pv++;
		}
		int tot = (cnt - pv) * i + s;
		if (tot >= i * i) {
			UDT(i, tot/i);
		}
	}
	s = A * B;
	for (i = 1; i <= cnt; i++) {
		if (U[i].c > A) U[i].c = A;
		U[i].c = min(U[i].c, s);
		s -= U[i].c;
	}
	printf("%d\n%d %d\n", A*B, A, B);
	vector<vector<int>>V;
	V.resize(A);
	for (i = 0; i < A; i++)V[i].resize(B);
	sort(U + 1, U + cnt + 1);
	int x = 0, y = 0;
	for (i = cnt; i >= 1; i--) {
		while (U[i].c) {
			V[x][y%B] = U[i].a;
			U[i].c--;
			x++, y++;
			if (x >= A) {
				x -= A;
				y -= A - 1;
			}
		}
	}
	for (i = 0; i < A; i++) {
		for (j = 0; j < B; j++) {
			printf("%d ", V[i][j]);
		}
		puts("");
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	int TC = 1;
	while (TC--) {
		Solve();
	}
}