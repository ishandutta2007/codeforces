#include "bits/stdc++.h"
using namespace std;
int a[400010];
int b[400010];
int d1[400010], d2[400010];
int pi[400010];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		b[i] = (m - a[i]) % m;
	}
	sort(b, b + n);
	for(int i = 0; i < n; i++) {
		d1[i] = (m + a[(i + 1) % n] - a[i]) % m;
		d2[i] = (m + b[(i + 1) % n] - b[i]) % m;
	}
	for(int i = n; i < n + n; i++) {
		d2[i] = d2[i - n];
	}
	// for(int i = 0; i < n; i++) {
	// 	printf("%d ", d1[i]);
	// }
	// printf("\n");
	// for(int i = 0; i < n; i++) {
	// 	printf("%d ", d2[i]);
	// }
	// printf("\n");

	// exit(0);

	int cur = -1;
	pi[0] = -1;
	for(int i = 1; i < n; i++) {
		while(cur != -1 && d1[cur + 1] != d1[i]) {
			cur = pi[cur];
		}
		if(d1[cur + 1] == d1[i]) {
			++cur;
		}
		pi[i] = cur;
	}
	set <int> s;
	cur = -1;
	for(int i = 0; i < n + n - 1; i++) {
		while(cur != -1 && d1[cur + 1] != d2[i]) {
			cur = pi[cur];
		}
		if(d1[cur + 1] == d2[i]) {
			++cur;
		}
		// cout << i << ' ' << cur << endl;
		if(cur == n - 1) {
			s.insert((m + a[0] - b[i - n + 1]) % m);
			cur = pi[cur];
		}
	}
	printf("%u\n", s.size());
	for(auto i : s) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}