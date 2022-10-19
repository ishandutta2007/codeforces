#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if (n <= 990) {
		int at = 1;
		int seenbig = 0;
		while (1) {
			printf("? %d\n", at);
			fflush(stdout);
			ll p;
			scanf("%lld", &p);
			if (p < k) { // special case
				printf("! %d\n", 1);
				fflush(stdout);
				return 0;
			} else if (p == k) {
				if (seenbig) {
					printf("! %d\n", at);
					fflush(stdout);
					return 0;
				}
			} else {
				seenbig = 1;
			}
			at--;
			if (!at) at = n;
		}
	} else {
		for (int i = 0; i < 330; i++) {
			printf("? %d\n", 1);
			fflush(stdout);
			ll p;
			scanf("%lld", &p);
		}
		int at = 1;
		int seenbig = 0;
		while (1) {
			printf("? %d\n", at);
			fflush(stdout);
			ll p;
			scanf("%lld", &p);
			if (p > k) {
				seenbig = 1;
			} else if (seenbig) {
				at += 320;
				if (at > n) at -= n;
				while (1) {
					printf("? %d\n", at);
					fflush(stdout);
					scanf("%lld", &p);
					if (p == k) {
						printf("! %d\n", at);
						fflush(stdout);
						return 0;
					}
					at--;
					if (!at) at = n;
				}
			}
			at -= 320;
			if (at < 1) at += n;
		}
	}
}