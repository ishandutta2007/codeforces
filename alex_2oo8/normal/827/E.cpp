#include <bits/stdc++.h>

using namespace std;

const int MX = (1 << 20);
const double pi = acos(-1);

struct base {
	double x, y;
	
	base(double x = 0, double y = 0) : x(x), y(y) { }
	base operator + (const base& v) { return base(x + v.x, y + v.y); }
	base operator - (const base& v) { return base(x - v.x, y - v.y); }
	base operator * (const base& v) { return base(x * v.x - y * v.y, x * v.y + y * v.x); }
	void operator /= (int d) { x /= d; y /= d; }
	double real() { return x; }
	double imag() { return y; }
	void imag(double z) { y = z; }
};

int rev[MX];
base w[MX + 1];

void init(int n) {
	int log_n = 0;
	while ((n >> log_n) > 1) log_n++;
	
	for (int i = 0; i < n; i++) {
		rev[i] = 0;
		for (int j = 0; j < log_n; j++)
			rev[i] |= (i >> j & 1) << (log_n - 1 - j);
		
		if (rev[i] < i) rev[i] = i;
	}
	
	w[1] = base(1, 0);
	for (int p = 0; p < log_n - 1; p++) {
		double alpha = pi / (n >> (log_n - 1 - p));
		base cur(cos(alpha), sin(alpha));
		for (int j = (1 << p); j < (2 << p); j++) {
			w[2 * j] = w[j];
			w[2 * j + 1] = w[j] * cur;
		}
	}
}

void fft(base a[], int n, bool invert) {
	for (int i = 0; i < n; i++) {
		swap(a[i], a[rev[i]]);
		if (invert) a[i].imag(-1 * a[i].imag());
	}
	for (int len = 1; len < n; len *= 2)
		for (int i = 0; i < n; i += 2 * len)
			for (int j = i, k = i + len; j < i + len; j++, k++) {
				base t = a[k] * w[k - i];
				a[k] = a[j] - t;
				a[j] = a[j] + t;
			}
	if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}

char s[MX];
base a[MX], b[MX];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d %s", &n, s);
		
		int N = 1;
		while (N < 2 * n) N *= 2;
		
		for (int i = 0; i < N; i++) a[i] = b[i] = base();
		
		for (int i = 0; i < n; i++) {
			if (s[i] == 'V') a[i] = base(1, 0);
			if (s[i] == 'K') b[n - 1 - i] = base(1, 0);
		}
		
		init(N);
		
		fft(a, N, false);
		fft(b, N, false);
		
		for (int i = 0; i < N; i++) a[i] = a[i] * b[i];
		
		fft(a, N, true);
	
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			bool ok = true;
			for (int j = i; j < n; j += i)
				if (abs(a[n - 1 + j].real()) > 0.5 || abs(a[n - 1 - j].real()) > 0.5)
					ok = false;
			
			if (ok) ans.push_back(i);
		}
		
		printf("%d\n", (int)ans.size());
		for (int x : ans) printf("%d ", x);
		printf("\n");
	}
	
	return 0;
}