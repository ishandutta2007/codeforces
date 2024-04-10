#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000, B = 21;

template<typename T>
void FWHT(T a[1 << B], bool inverse, int bits = B) {
	for (int len = 1; 2 * len <= (1 << B); len <<= 1) {
		for (int i = 0; i < (1 << B); i += 2 * len) {
			int f = min(len, 1 << bits);
			for (int j = 0; j < f; j++) {
				T u = a[i + j];
				T v = a[i + len + j];
				a[i + j] = u + v;
				a[i + len + j] = u - v;
			}
		}
	}
	
	if (inverse) {
		for (int i = 0; i < (1 << B); i++) a[i] >>= B;
	}
}

long long s[MX], a[1 << B];
int aa[1 << B];

int main() {
	int n = 1e6;
	long long k = 1e12 - 42e7;
	ignore = scanf("%d %lld", &n, &k);
	for (int i = 1; i < n; i++) {
		int p;
		long long w;
		ignore = scanf("%d %lld", &p, &w);
		s[i] = s[p - 1] ^ w;
		//s[i] = ((long long)i ^ ((long long)i << 20) ^ ((long long)i << 40) ^ ((long long)(i & 3) << 60));
		//s[i] ^= 12345678987654321ll;
	}
	
	int bits = 62, originalBits = 62;
	long long ans = 0;
	while (originalBits > 0) {
		memset(aa, 0, sizeof aa);
		
		int shift = max(0, bits - B);
		
		for (int i = 0; i < n; i++) aa[s[i] >> shift]++;
		
		FWHT(aa, false);
		
		for (int i = 0; i < (1 << B); i++) a[i] = aa[i] * 1ll * aa[i];
		
		FWHT(a, true, originalBits - shift + 1);
		
		memset(aa, 0, sizeof aa);
		for (int i = 0; i < n; i++) aa[s[i] >> shift]++;
			
		int id = 0;
		if (a[0] >= k) {
			for (int i = 0; i < (1 << B); i++) {
				if (aa[i] == 0) continue;
				aa[i] = id++;
			}
		}
		else {
			int p = 0;
			while (a[p] < k) {
				k -= a[p];
				p++;
			}
			
			if (originalBits > shift) {
				ans ^= ((long long)(p & ((1 << (originalBits - shift)) - 1))) << shift;
			}
			
			for (int i = 0; i < (1 << B); i++) {
				if ((i ^ p) < i) continue;
				if (aa[i] == 0 || aa[i ^ p] == 0) {
					aa[i] = aa[i ^ p] = -1;
					continue;
				}
				k += aa[i] * 1ll * aa[i] + aa[i ^ p] * 1ll * aa[i ^ p];
				aa[i] = id++;
				aa[i ^ p] = id++;
			}
		}
		
		originalBits = min(originalBits, shift);
		
		int newBits = 0;
		while (id > (1 << newBits)) newBits++;
		
		assert(newBits < B);
		
		for (int i = 0; i < n; i++) {
			long long f = s[i] >> shift;
			if (aa[f] == -1) {
				s[i] = s[n - 1];
				n--;
				i--;
				continue;
			}
			s[i] ^= f << shift;
			s[i] ^= (long long)(aa[f]) << shift;
		}
		
		bits = shift + newBits;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}