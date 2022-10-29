#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int Mod = 1e9 + 7;

int add(int a, int b) {
	return ((a += b) >= Mod) ? (a - Mod) : (a);
}

int mul(int a, int b) {
	return a * 1ll * b % Mod;
}

void exgcd(int a, int b, int& x, int& y) {
	if (!b)
		x = 1, y = 0;
	else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
} 

int inv(int a) {
	int x, y;
	exgcd(a, Mod, x, y);
	return (x < 0) ? (x + Mod) : (x);
}

const int N = 1024;

int k, pa, pb;
int f[N][N];

inline void init() {
	scanf("%d%d%d", &k, &pa, &pb);
	pa = mul(pa, inv(pa + pb));
	pb = Mod + 1 - pa;
}

int ans = 0;
inline void solve() {
	f[0][1] = 1;
	int _pb = inv(pb);
	for (int s = 0; s < k; s++) {
		for (int cnt_a = 1; cnt_a < k; cnt_a++) {
			int val = f[s][cnt_a];
			if (s + cnt_a < k) {
				f[s + cnt_a][cnt_a] = add(f[s + cnt_a][cnt_a], mul(val, pb));
			} else {
				ans = add(ans, mul(mul(val, pb), s + cnt_a));	
			}
			f[s][cnt_a + 1] = add(f[s][cnt_a + 1], mul(val, pa));
		}
		int prob = mul(f[s][k], pb);
		int E = mul(k + s, _pb);
		E = add(E, mul(pa, mul(_pb, _pb)));
		ans = add(ans, mul(E, prob));
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}