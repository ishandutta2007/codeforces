#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <sstream>
#include <numeric>
#include <climits>
#include <string>
#include <cctype>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef pair<int, int> PII;

const int N = int(1e5) + 100;

int n, m, len, block;
int a[N], b[N], c[N];
int l[N], r[N];
PII f[N];

PII operator +(const PII &a, int x) {
	return PII(a.first + x, a.second);
}

void modify(int pos, int value) {
	int t = b[pos];
	a[pos] = value;
	f[pos] = pos + value >= r[t] ? PII(1, pos) : f[pos + value] + 1;
	c[pos] = pos + value >= r[t] ? pos + value : c[pos + value];
	for (int i = pos - 1; i >= l[t]; --i) {
		f[i] = i + a[i] >= r[t] ? PII(1, i) : f[i + a[i]] + 1;
		c[i] = i + a[i] >= r[t] ? i + a[i] : c[i + a[i]];
	}
}

PII query(int pos) {
	PII ans(0, 0);
	for (; pos < n; pos = c[pos]) {
		ans = PII(ans.first + f[pos].first, f[pos].second);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (len = 1; len * len < n; len++);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; i += len) {
		l[block] = i;
		r[block] = min(n, i + len);
		for (int j = r[block] - 1; j >= l[block]; --j) {
			b[j] = block;
			f[j] = a[j] + j >= r[block] ? PII(1, j) : f[a[j] + j] + 1;
			c[j] = a[j] + j >= r[block] ? a[j] + j : c[a[j] + j];
		}
		block++;
	}

	int ctrl, a, b;
	while (m--) {
		scanf("%d%d", &ctrl, &a);
		if (ctrl == 0) {
			scanf("%d", &b);
			modify(a - 1, b);
		} else {
			PII ans = query(a - 1);
			printf("%d %d\n", ans.second + 1, ans.first);
		}
	}
}