#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
double l, r;
double x[20], y[20], a[20];
double dp[1 << 20];

double rec(int mask) {
	double &ref = dp[mask];
	if (ref == ref) return ref; 
	ref = l;
	for (int i = 0; i < n; i++) 
		if ((mask >> i) & 1) {
			double tmp = rec(mask ^ (1 << i));
			double alpha = a[i] + atan2(tmp - x[i], y[i]) * 180 / M_PI;
			if (alpha >= 90) return ref = r;
			ref = max(ref, x[i] + tan(alpha * M_PI / 180) * y[i]);
		}
	return ref;
}

int main() {
	
	scanf("%d%lf%lf", &n, &l, &r);
	
	for (int i = 0; i < n; i++) 
		scanf("%lf%lf%lf", &x[i], &y[i], &a[i]);
		
	memset(dp, -1, sizeof dp);
	dp[0] = l;
	printf("%.9lf\n", min(rec((1 << n) - 1), r) - l);
	
	return 0;
}