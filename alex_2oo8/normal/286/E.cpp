#include <bits/stdc++.h>

using namespace std;

const int MX = (1 << 23); // should be at least 2 * n, a power of two
const int md = 998244353; // prime and of form 2^k * x + 1, where 2^k >= MX
const int root = 31;      // MX-th root of unity modulo md

int pow(int x, int p) {
	int r = 1;
	while (p) {
		if (p % 2 == 1) r = r * 1ll * x % md;
		x = x * 1ll * x % md;
		p /= 2;
	}
	return r;
}

int rev[MX];

// init() must be called before any calls to fft() with exactly
// the same value of n, which must be a power of two!
void init(int n) {
	int log_n = 0;
	while ((n >> log_n) > 1) log_n++;
	
	for (int i = 0; i < n; i++) {
		rev[i] = 0;
		for (int j = 0; j < log_n; j++)
			rev[i] |= (i >> j & 1) << (log_n - 1 - j);
		
		if (rev[i] < i) rev[i] = i;
	}
}

void fft(int a[], int n, bool invert) {
	static int w_pow[MX];
	for (int i = 0; i < n; i++) swap(a[i], a[rev[i]]);
	for (int len = 1; len < n; len *= 2) {
		w_pow[0] = 1;
		w_pow[1] = pow(root, MX / (2 * len));
		if (invert) w_pow[1] = pow(w_pow[1], md - 2);
		for (int i = 2; i < len; i++) w_pow[i] = w_pow[i - 1] * 1ll * w_pow[1] % md;
		for (int i = 0; i < n; i += 2 * len)
			for (int j = i, k = i + len; j < i + len; j++, k++) {
				int t = a[k] * 1ll * w_pow[j - i] % md, u = a[j];
				a[k] = u - t < 0 ? u - t + md : u - t;
				a[j] = u + t >= md ? u + t - md : u + t;
			}
	}
	if (invert) {
		int n_inv = pow(n, md - 2);
		for (int i = 0; i < n; i++) a[i] = a[i] * 1ll * n_inv % md;
	}
}

const int MAX = (1 << 21);

int a[MAX], b[MAX];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x] = b[x] = 1;
	}
	
	init(MAX);
	fft(a, MAX, false);
	for (int i = 0; i < MAX; i++) a[i] = a[i] * 1ll * a[i] % md;
	fft(a, MAX, true);

	vector<int> ans;
	for (int i = 1; i <= m; i++) {
		int c = min(a[i], 1);
		if (b[i] == c) continue;
		if (c == 1) {
			printf("NO\n");
			return 0;
		}
		ans.push_back(i);
	}
	
	printf("YES\n%d\n", (int)ans.size());
	for (int x : ans) printf("%d ", x);
	printf("\n");
	
	return 0;
}