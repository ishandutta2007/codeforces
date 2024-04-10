#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define ll long long

int n;
int a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		cnt += (a[i] == a[i + 1]);
	}
	if (cnt > 1) {
		puts("cslnb");
	} else if (cnt == 1) {
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i + 1]) {
				a[i]--;
				if (a[i] < 0 || (i > 1 && a[i] == a[i - 1])) {
					puts("cslnb");
					return 0;
				}
				break;
			}
		}
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i] - i + 1;
		}
		if (sum & 1) {
			puts("cslnb");
		} else {
			puts("sjfnb");
		}
	} else {
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i] - i + 1;
		}
		if (!(sum & 1)) {
			puts("cslnb");
		} else {
			puts("sjfnb");
		}
	}
	return 0;
}