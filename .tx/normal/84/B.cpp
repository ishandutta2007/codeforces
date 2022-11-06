#include <cstdio>
#include <iostream>
using namespace std;
int a[100000];
int main() {
	int n, i;
	long long ans, k;
	scanf("%d", &n);
	k = 1;
	ans = n;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i) {
			if (a[i] == a[i - 1]) {
				k++;
			}
			else {
				ans += (k * (k - 1)) >> 1;
				k = 1;
			}
		}
	}
	cout << ans + ((k * (k - 1)) >> 1);
	return 0;
}//mldugv