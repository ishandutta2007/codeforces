#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int MAXM = 5e5 + 5;

int N, M;
bitset <MAXN> mat[MAXN], inv[MAXN];
int a[MAXM], b[MAXM];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", a + i, b + i);
		mat[--b[i]].set(--a[i]);
	}
}

void solve() {
	for (int i = 0; i < N; i++)
		inv[i].set(i);
		
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++)
			if (mat[j].test(i)) {
				swap(mat[i], mat[j]);
				swap(inv[i], inv[j]);
				break;
			}
		for (int j = i + 1; j < N; j++)
			if (mat[j].test(i)) {
				mat[j] ^= mat[i];
				inv[j] ^= inv[i];
			}
	}
	
	for (int i = N - 1; i >= 0; i--) 
		for (int j = i + 1; j < N; j++)
			if (mat[i].test(j))
				inv[i] ^= inv[j];
	
	for (int i = 0; i < M; i++)
		puts(inv[a[i]].test(b[i]) ? "NO" : "YES");
}

int main() {
	load();
	solve();
	return 0;
}