#include <bits/stdc++.h>
using namespace std;

int A, B, N;

void load() {
	scanf("%d%d", &A, &B);
}

int sumset(int lo1, int hi1, int lo2, int hi2, int lo, int hi) {
	if (lo1 == hi1 || lo2 == hi2 || lo == hi)
		return 0;
	return max(min(hi1 + hi2, hi) - max(lo1 + lo2 + 2, lo + 1) + 1, 0);	
}

int calc(int rep) {
	return sumset((A - 1) / (rep + 1), A / rep, (B - 1) / (rep + 1), B / rep, N / (rep + 1), N / rep);
}

int solve() {
	N = A + B;
	set <int> cands;
	for (int i = 1; i * i <= N; i++) {
		cands.insert(i);
		cands.insert(N / i);
	}
	int sol = 0;
	for (auto it : cands)
		sol += calc(it);
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}