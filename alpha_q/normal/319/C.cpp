#include <bits/stdc++.h>
 
using namespace std;

const int N = 2e5 + 10;

int n;
long long a[N];
long long b[N];
long long dp[N], f[N];
vector <long long> m;
vector <long long> c;
int size, pointer;

bool bad (int l1, int l2, int l3) {
	return (c[l2] - c[l1]) * 1.0/(m[l1] - m[l2]) >= (c[l3] - c[l1]) * 1.0/(m[l1] - m[l3]);
}

void add (long long m0, long long c0) {
	++size;
	m.push_back(m0);
	c.push_back(c0);
	while (size >= 3 and bad(size - 3, size - 2, size - 1)) {
		--size;
		m.erase(m.end() - 2);
		c.erase(c.end() - 2);
	}
}

long long query (long long x) {
	if (pointer >= size) pointer = size - 1;
	while (pointer < size - 1 and m[pointer] * x + c[pointer] > m[pointer + 1] * x + c[pointer + 1]) {
		++pointer;
	}
	return m[pointer] * x + c[pointer];
}

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", b + i);
	}
	dp[1] = 0;
	add(b[1], dp[1]);
	for (int i = 2; i <= n; ++i) {
		dp[i] = query(a[i]);
		add(b[i], dp[i]);
	}
	printf("%lld\n", dp[n]);
    return 0;
}