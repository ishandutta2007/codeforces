#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MAXM = 15;
const int BASE1 = 3137;
const int BASE2 = 10007;
const int MOD = 1e9 + 7;

int N, M;
int perm[MAXM][MAXN], inv[MAXM][MAXN];
pii pref[MAXM][MAXN];
int pot1[MAXN], pot2[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", perm[i] + j);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

pii get(int x, int lo, int hi) {
	return {pref[x][hi].first - pot1[hi - lo + 1] * pref[x][lo - 1].first, add(pref[x][hi].second, -mul(pot2[hi - lo + 1], pref[x][lo - 1].second))};
}

bool test(int num, int len, pii hsh) {
	for (int j = 1; j < M; j++)
		if (get(j, inv[j][num], inv[j][num] + len - 1) != hsh)
			return false;
	return true;
}

ll solve() {
	pot1[0] = pot2[0] = 1;
	for (int i = 1; i <= N; i++) {
		pot1[i] = pot1[i - 1] * BASE1;
		pot2[i] = mul(pot2[i - 1], BASE2);
	}
	
	for (int i = 0; i < M; i++) 
		for (int j = 1; j <= N; j++) {
			pref[i][j] = {pref[i][j - 1].first * BASE1 + perm[i][j], add(mul(pref[i][j - 1].second, BASE2), perm[i][j])};
			inv[i][perm[i][j]] = j;
		}
		
	ll sol = 0;
	int ptr = 2;
	for (int i = 1; i <= N; i++) {
		while (ptr <= N && test(perm[0][i], ptr - i + 1, get(0, i, ptr)))
			ptr++;
		sol += ptr - i;
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}