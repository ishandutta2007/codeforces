#include <bits/stdc++.h>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

#define ll long long

int n, m;
ll s;
int *p, *d;

inline void init() {
	scanf("%d"Auto, &n, &s);
	p = new int[(n + 1)];
	d = new int[(n + 1)];
}

boolean check(int mid) {
	ll sum = 0, rest = n, lim = 1; 
	for (int i = 1; rest && sum <= s; i++) {
		sum += i * min(rest, lim);
		rest -= min(rest, lim);
		lim *= mid;
	}
	return sum <= s;
}
	
inline void solve() {
	if (s < 2 * n - 1) {
		puts("No");
		return;
	}
	if (s * 2 > n * 1ll * (n + 1)) {
		puts("No");
		return;
	}
	puts("Yes");
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	++r;
	ll sum = -s;
	int cur = 2, put = 1, lim = r, lst = 1;
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		sum += i;
	}
	for (int i = n; i > cur && sum; i--) {
		if (sum >= i - cur) {
			sum -= i - cur;
			d[i]--;
			d[cur]++;
			put++;
			if (put == lim) {
				cur++, put = 1;
				lim = lim * r;
			}
		} else {
			d[i]--;
			d[i - sum]++;	// dif = i - (i - sum) = sum
			sum = 0;
			break;
		}
	}
	assert(!sum);
	p[1] = 0;
	int cnt = 2;
	for (int i = 2; i <= n; i++) {
		cur = cnt;
		for (int j = 0; j < d[i]; j++) {
			p[cnt++] = lst + j / r;
		}
		lst = cur;
	}
	for (int i = 2; i <= n; i++) {
		printf("%d ", p[i]);
	}
}

int main() {
	init();
	solve();
	return 0;
}