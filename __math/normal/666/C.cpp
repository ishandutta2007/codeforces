#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)

const int MOD = ten(9) + 7;
using ll = long long;

const int N = ten(5) + 10;
ll iv[N];
ll ft[N], ift[N];
void init_inv() {
	iv[0] = iv[1] = 1;
	for (int i = 2; i < N; i++) iv[i] = (MOD - MOD / i) * iv[MOD % i] % MOD;
	ft[0] = ft[1] = 1;
	for (int i = 2; i < N; i++) ft[i] = ft[i - 1] * i % MOD;
	ift[0] = ift[1] = 1;
	for (int i = 2; i < N; i++) ift[i] = ift[i - 1] * iv[i] % MOD;
}

ll nck(int n, int k) {
	return ft[n] * ift[k] % MOD * ift[n - k] % MOD;
}

const int X = 25;
ll p25[N], p26[N];

void init() {
	init_inv();
	p25[0] = 1;
	FOR(i, N - 1) p25[i + 1] = p25[i] * X % MOD;
	p26[0] = 1;
	FOR(i, N - 1) p26[i + 1] = p26[i] * (X + 1) % MOD;
}

map<int, vector<int>> mp;
char buf[N];
int main() {
	init();

	auto f = [&](int len) {
		if (mp.count(len) == 0) {
			auto& v = mp[len];
			v.reserve(ten(5) + 1);
			mp[len].push_back(1);
			for (int k = 1; k <= ten(5) - len; k++) {
				ll last = v.back();
				v.push_back((last * (X + 1) +nck(k + len - 1, k) * p25[k] ) % MOD);
			}
		}
	};

	int m; scanf("%d", &m);
	int len; scanf("%s", buf);
	len = strlen(buf);
	f(len);
	FOR(i, m) {
		int t; scanf("%d", &t);
		if (t == 1) {
			scanf("%s", buf);
			len = strlen(buf);
			f(len);
		} else {
			int n; scanf("%d", &n);
			int ans;
			if (n - len < 0) ans = 0;
			else ans = mp[len][n - len];
			printf("%d\n", (int)ans);
		}
	}
}