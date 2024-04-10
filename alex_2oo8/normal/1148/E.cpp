#include <bits/stdc++.h>

using namespace std;

const int MX = 300000;

long long a[MX], b[MX];

/*
5 3
1 3
4 4
*/

int main() {
	srand(time(NULL));
	int n = 2;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ignore = scanf("%lld", a + i);
		a[i] *= n;
		a[i] += i;
	}
	
	for (int i = 0; i < n; i++) {
		ignore = scanf("%lld", b + i);
		b[i] *= n;
	}
	
	sort(a, a + n);
	sort(b, b + n);
	
	bool ok = true;
	long long sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
		sa += a[i] / n;
		sb += b[i] / n;
		
		if (sa > sb) ok = false;
	}
	
	if (sa != sb || ok == false) {
		printf("%s\n", "NO");
		return 0;
	}
	
	printf("%s\n", "YES");
	
	vector<tuple<int, int, int>> vec;
	for (int i = 0, j = 0; i < n;) {
		assert(a[i] / n <= b[i] / n);
		if (a[i] / n == b[i] / n) {
			i++;
			continue;
		}
		while (a[j] / n <= b[j] / n) j++;
		
		int d = min(b[i] / n - a[i] / n, a[j] / n - b[j] / n);
		vec.emplace_back(a[i] % n, a[j] % n, d);
		a[i] += d * 1ll * n;
		a[j] -= d * 1ll * n;
	}
	
	printf("%d\n", (int)vec.size());
	for (auto& t : vec) {
		int i, j, d;
		tie(i, j, d) = t;
		printf("%d %d %d\n", i + 1, j + 1, d);
	}
	
	return 0;
}