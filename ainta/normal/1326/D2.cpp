#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[1010000], q[2010000];
int n, D[2010000];
bool Palin(int b, int e) {
	return D[b + e] >= e - b;
}
void Print(int b, int e) {
	for (int i = 0; i < b; i++)printf("%c", p[i]);
	for (int i = n-e; i<n; i++)printf("%c", p[i]);
	puts("");
}
void Solve() {
	int i, j;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; i < n; i++) {
		if (p[i] != p[n - i - 1])break;
	}
	if (i == n) {
		printf("%s\n", p);
		return;
	}
	int m = i;
	for (i = 0; i < n; i++) {
		q[i * 2] = p[i];
		q[i * 2 + 1] = 0;
	}
	int L = 2 * n - 1, ed = -1, mid = -1;
	for (i = 0; i < L; i++) {
		if (i < ed && i + D[mid * 2 - i] < ed) {
			D[i] = D[mid * 2 - i];
			continue;
		}
		ed = max(ed, i);
		mid = i;
		while (ed + 1 < L && i * 2 - ed - 1 >= 0 && q[ed + 1] == q[i * 2 - ed - 1])ed++;
		D[i] = ed - i;
	}
	int res = 2*m;
	for (i = 0; i < n - 2*m; i++) {
		if (Palin(m, n - m - i - 1)) {
			Print(n-m-i, m);
			return;
		}
		if (Palin(m + i, n - m - 1)) {
			Print(m, n-m-i);
			return;
		}
	}
	Print(m, m);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}