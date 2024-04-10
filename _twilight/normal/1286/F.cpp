#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 20, S = 1 << N, hS = 1 << 10;
const int Mod = 1e9 + 9;

template <typename T>
T _abs(T x) {
	return (x < 0) ? (-x) : (x);
}

#define ll long long

int n;
ll a[N];
int bit[S];
int f[N + 1][S];
ll sumf[hS], sumg[hS];
vector<ll> F[hS][2], G[hS][2];

void work(int st, int n, vector<ll> (*F)[2], ll *sum) {
	for (int s = 0; s < (1 << n); s++) {
		sum[s] = 0;
		for (int i = 0; i < n; i++) {
			if ((s >> i) & 1) {
				sum[s] += a[st + i];
			}
		}
		for (int t = (s - 1) & s; t; t = (t - 1) & s) {
			ll sum = 0;
			for (int i = 0; i < n; i++) {
				if ((s >> i) & 1) {
					if ((t >> i) & 1) {
						sum += a[st + i];
					} else {
						sum -= a[st + i];
					}
				}
			}
			F[s][sum & 1].push_back(sum);
		}
		sort(F[s][0].begin(), F[s][0].end());
		sort(F[s][1].begin(), F[s][1].end());
	}
}

void fix(int& x) {
	(x >= Mod) && (x -= Mod);
}
void fwt(int* f, int n) {
	int N = (1 << n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N; j++) {
			if ((j >> i) & 1) {
				fix(f[j] += f[j ^ (1 << i)]);
			}
		}
	}
}
void ifwt(int* f, int n) {
	int N = (1 << n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N; j++) {
			if ((j >> i) & 1) {
				fix(f[j] += Mod - f[j ^ (1 << i)]);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", a + i);
	int hn = n >> 1;
	work(0, hn, F, sumf);
	work(hn, n - hn, G, sumg);
	for (int i = 1; i < (1 << n); i++)
		bit[i] = bit[i >> 1] + (i & 1);
	for (int i = 0; i < n; i++)
		f[1][1 << i] = 1;
	int S0 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			S0 |= 1 << i;
		}
	}
	if (bit[S0] == n) {
		puts("0");
		return 0;
	}
	for (int s = 1; s < (1 << n); s++) {
		if (bit[s] == 1)
			continue;
		int sl = s & ((1 << hn) - 1);
		int sr = (s ^ sl) >> hn;
		int e = bit[s] - 1;
		int par = e & 1;
		boolean suc = false;
		for (int parl = 0; parl < 2 && !suc; parl++) {
			int parh = par ^ parl;
			auto pl = G[sr][parh].rbegin();
			auto pr = G[sr][parh].rbegin();
			auto _p = G[sr][parh].rend();
			for (auto x : F[sl][parl]) {
				while (pl != _p && *pl >= -x - e) pl++;
				while (pr != _p && *pr > -x + e) pr++;
				if (pl != pr) {
					suc = true;
					break;
				}
			}
			if (!suc) {
				if ((sumf[sl] & 1) == parl) {
#define LW(x) lower_bound(G[sr][parh].begin(), G[sr][parh].end(), x)
					suc = suc || (LW(-sumf[sl] - e) != LW(-sumf[sl] + e + 1));
#undef LW
				}
				if ((sumg[sr] & 1) == parh) {
#define LW(x) lower_bound(F[sl][parl].begin(), F[sl][parl].end(), x)
					suc = suc || (LW(-sumg[sr] - e) != LW(-sumg[sr] + e + 1));
#undef LW
				}
				if ((sumf[sl] & 1) == parl && (sumg[sr] & 1) == parh && sl && sr) {
					suc = suc || _abs(sumf[sl] - sumg[sr]) <= e;
				}
			}
		}
		f[e][s] = suc;
	}
	for (int i = 1; i <= n; i++) {
		fwt(f[i], n);
		for (int j = 1; j < i; j++) {
			for (int s = 0; s < (1 << n); s++) {
				f[i][s] = (f[i][s] + 1ll * f[j][s] * f[i - j][s]) % Mod;
			}
		}
		ifwt(f[i], n);
		for (int s = 0; s < (1 << n); s++) {
			if (f[i][s] && bit[s | S0] == n) {
				printf("%d\n", i);
				return 0;
			}
		}
		fwt(f[i], n);
	}
	assert(false);
	return 0;
}