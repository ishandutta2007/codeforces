#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 7;
const long long M = 1000ll * 1000 * 1000 * 1000 * 1000;
int n, m;
long long s = 0, a;

long long b[N];
long long p[N];
long long bb[N];
bool isval(int x) {
	for (int i = n - x; i < n; i++)
		bb[i - n + x] = b[i];
	long long c = a;
	for (int i = 0; i < x; i++) {
		if(p[i] > bb[i]) {
			c -= (p[i] - bb[i]);
		}
	}
	return c >= 0;
}
int main() {
	for (int i = 0; i < N - 2; i++) {
		b[i] = M;
		p[i] = M;
		p[i] = M;
	}
	cin >> n;
	cin >> m;
	cin >> a;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < m; i++)
		cin >> p[i];
	sort(b, b + n);
	sort(p, p + m);
	int dw = 0, up = min(m + 1, n + 1);
	while (up - dw > 1) {
		int md = (dw + up) / 2;
		if (isval(md))
			dw = md;
		else
			up = md;
	}
	cout << dw << " ";
	for (int i = 0; i < dw; i++) {
		s += p[i];	
	}
	cout << max(s - a, 0ll);
	return 0;
}