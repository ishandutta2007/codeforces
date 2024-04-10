#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int x[1000];
long double ans[1000];
int main() {
	int n, r, i, j;
	scanf("%d%d", &n, &r);
	for (i = 0; i < n; i++) scanf("%d", &x[i]);
	for (i = 0; i < n; i++) {
		ans[i] = (long double)r;
		for (j = 0; j < i; j++) {
			if (abs(x[i] - x[j]) <= 2 * r) ans[i] = max(ans[i], ans[j] + sqrtl((long double)(4*r*r-(x[i]-x[j])*(x[i]-x[j]))));
		}
	}
	for (i = 0; i < n; i++) printf("%.13Lf ", ans[i]);
}