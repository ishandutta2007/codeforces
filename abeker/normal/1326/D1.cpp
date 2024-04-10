#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;
const int BASE1 = 10007;
const int BASE2 = 3137;
const int MOD = 1e9 + 7;

int N;
char s[MAXN];
pii pref[MAXN], suff[MAXN];
int pot1[MAXN], pot2[MAXN];
int toleft[MAXN];

void load() {
	scanf("%s", s + 1);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

inline pii get_hsh(int x, int y) {
	return {pref[y].first - pref[x - 1].first * pot1[y - x + 1], add(pref[y].second, -mul(pref[x - 1].second, pot2[y - x + 1]))};
}

inline pii get_rev(int x, int y) {
	return {suff[x].first - suff[y + 1].first * pot1[y - x + 1], add(suff[x].second, -mul(suff[y + 1].second, pot2[y - x + 1]))};
}

inline bool is_pali(int x, int y) {
	return get_hsh(x, y) == get_rev(x, y);
}

void solve() {
	N = strlen(s + 1);
	pot1[0] = pot2[0] = 1;
	for (int i = 1; i <= N; i++) {
		pot1[i] = pot1[i - 1] * BASE1;
		pot2[i] = mul(pot2[i - 1], BASE2);	
	}
	
	string opt = "";
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= N; i++) 
			pref[i] = {pref[i - 1].first * BASE1 + s[i], add(mul(pref[i - 1].second, BASE2), s[i])};
		suff[N + 1] = {0, 0};
		for (int i = N; i; i--) 
			suff[i] = {suff[i + 1].first * BASE1 + s[i], add(mul(suff[i + 1].second, BASE2), s[i])};
		
		for (int i = 1; i <= N; i++) {
			int l = min(toleft[i - 1] + 2, min(i, max(2 * i - N, 0)));
			while (!is_pali(i - l + 1, i))
				l--;
			toleft[i] = l;
		}
		
		int mx = 0, pf = 0;
		for (int i = 0; i <= N / 2; i++) 
			if (pref[i] == suff[N - i + 1]) {
				int len = 2 * i + toleft[N - i];
				if (len > mx) {
					mx = len;
					pf = i;
				}
			}
		
		if (mx > opt.size()) {
			opt = "";
			for (int i = 1; i <= pf; i++)
				opt += s[i];
			for (int i = mx - pf; i; i--)
				opt += s[N - i + 1];
		}
		
		reverse(s + 1, s + N + 1);
	}
	
	puts(opt.c_str());
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}