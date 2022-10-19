#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;
const int BASE1 = 3137;
const int BASE2 = 10007;
const int MOD = 1e9 + 7;

int N, M;
char s[MAXN], t[MAXN];
int a[MAXN];
pii pref[MAXN];
int pot1[MAXN], pot2[MAXN];

void load() {
	scanf("%s%s", s, t + 1);
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
	return (long long)x * y % MOD;
}

pii get(int lo, int hi) {
	return pii(add(pref[hi].first, -mul(pref[lo - 1].first, pot1[hi - lo + 1])), pref[hi].second - pref[lo - 1].second * pot2[hi - lo + 1]);
}

int solve() {
	N = strlen(s);
	M = strlen(t + 1);
	
	pot1[0] = pot2[0] = 1;
	for (int i = 1; i <= M; i++) {
		pref[i] = {add(mul(pref[i - 1].first, BASE1), t[i]), pref[i - 1].second * BASE2 + t[i]};
		pot1[i] = mul(pot1[i - 1], BASE1);
		pot2[i] = pot2[i - 1] * BASE2;
	}
	
	for (int i = 0; i < N; i++)
		a[i] = s[i] - '0';
		
	if (a[0])
		for (int i = 0; i < N; i++)
			a[i] ^= 1;
			
	int cnt[2] = {0};
	int st = -1;
	for (int i = 0; i < N; i++) {
		cnt[a[i]]++;
		if (a[i] && st == -1)
			st = i;
	}
	
	int sol = 0;
	for (int x = 1; x <= M / cnt[0]; x++) {
		if ((M - x * cnt[0]) % cnt[1])
			continue;
		int y = (M - x * cnt[0]) / cnt[1];
		pii r[2] = {get(1, x), get(st * x + 1, st * x + y)}; 
		if (!y || r[0] == r[1])
			continue;
		pii hsh = {0, 0};
		int len = 0;
		for (int i = N - 1; i >= 0; i--) {
			hsh.first = add(hsh.first, mul(r[a[i]].first, pot1[len]));
			hsh.second += r[a[i]].second * pot2[len];
			len += a[i] ? y : x;
		}
		sol += hsh == pref[M];
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}