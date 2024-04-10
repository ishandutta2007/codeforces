#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
    return y ? gcd(y, x % y) : x;
}
long long extgcd(long long x, long long y, long long &a, long long &b) {
    if (!y) {
        a = 1, b = 0;
        return x;
    }
    long long g = extgcd(y, x % y, b, a);
    b -= (x / y) * a;
    return g;
}
long long GetInv(long long a, long long b) {
	long long x, y;
	extgcd(a, b, x, y);
	return (x % b + b) % b;
}
void Merge(long long a1, long long m1, long long a2, long long m2, long long &a3, long long &m3) {
    long long d = gcd(m1, m2);
    long long c = a2 - a1;
    c = (c % m2 + m2) % m2;
    m1 /= d;
    m2 /= d;
    c /= d;
    c *= GetInv(m1, m2);
    c %= m2;
    c *= m1 * d;
    c += a1;
    m3 = m1 * m2 * d;
    a3 = (c % m3 + m3) % m3;
}
const int N = 500005;
const int V = 1000005;
int n, m, a[N], b[N], va[V], vb[V];
long long K;
int main() {
	scanf("%d%d%lld", &n, &m, &K);
	memset(va, -1, sizeof(va));
	memset(vb, -1, sizeof(vb));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), va[a[i]] = i;
	for (int i = 0; i < m; i++) scanf("%d", &b[i]), vb[b[i]] = i;
	int g = gcd(n, m);
	vector<long long> vec;
	for (int i = 0; i < V; i++) if (va[i] != -1 && vb[i] != -1) {
		int p = va[i], q = vb[i];
		if (p % g == q % g) {
			long long a3, m3;
			Merge(p, n, q, m, a3, m3);
			vec.push_back(a3);
		}
	}
	long long al = 1ll * n * m / g;
	long long P = al - vec.size();
	vec.push_back(al);
	vec.push_back(-1);
	sort(vec.begin(), vec.end());
	long long dlt = K / P;
	K %= P;
	if (!K) K = P, dlt--;
	long long R = -1;
	for (int i = 1; i < (int)vec.size() && K; i++) {
		long long mn = min(K, vec[i] - vec[i - 1] - 1);
		K -= mn;
		R = vec[i - 1] + mn;
	}
	printf("%lld\n", dlt * al + R + 1);
	return 0;
}