#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

typedef class Data {
	public:
		int x, y, z;

		Data(int x, int y, int z) : x(x), y(y), z(z) {	}
} Data;

#define ll long long
#define pii pair<int, int>

int n;
pii s[N];
int t[N], d[N];
vector<Data> op;

int main() {
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		s[i] = pii(x, i);
		sum += x;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", t + i);
		sum -= t[i];
	}
	if (sum) {
		puts("NO");
		return 0;
	}
	sort(s + 1, s + n + 1);
	sort(t + 1, t + n + 1);
	sum = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = t[i] - s[i].first;
		if ((sum += d[i]) < 0) {
			puts("NO");
			return 0;
		}
	}
	int p = 1;
	for (int i = 1; i <= n; i++) {
		while (d[i] > 0) {
			while (p <= n && d[p] >= 0)
				p++;
			assert(p <= n && i < p);
			int v = min(d[i], -d[p]);
			op.emplace_back(s[i].second, s[p].second, v);
			d[i] -= v, d[p] += v;
		}
	}
	puts("YES");
	printf("%d\n", (signed) op.size());
	for (auto d : op) {
		printf("%d %d %d\n", d.x, d.y, d.z);
	}
	return 0;
}