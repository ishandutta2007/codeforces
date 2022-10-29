#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 105;

typedef class Work {
	public:
		int a, b;

		Work() {	}
		Work(int a, int b) : a(a), b(b) {	}

		void read() {
			scanf("%d%d", &a, &b);
		}
		boolean operator < (Work c) {
			return a < c.a;
		}
} Work;

int n, r;
int f[60005];
vector<Work> pos, neg;

int main() {
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++) {
		Work x;
		x.read();
		if (x.b >= 0) {
			pos.push_back(x);
		} else {
			neg.emplace_back(x.a + x.b, -x.b);
		}
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	int cnt = 0;
	for (auto w : pos) {
		if (r >= w.a) {
			r += w.b;
			++cnt;
		} else {
			break;
		}
	}
	for (int i = 0; i <= r; i++)
		f[i] = 0;
	for (auto w : neg) {
		for (int i = r; i - w.b >= w.a && i >= w.b; i--) {
			f[i] = max(f[i], f[i - w.b] + 1);
		}
	}
	printf("%d\n", f[r] + cnt);
	return 0;
}