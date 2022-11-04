#include <bits/stdc++.h>
using namespace std;
const int N = 35005;
int n;
long long a[N], l[N], r[N];
inline long long calc(long long x) {
	priority_queue<long long> L;
	priority_queue<long long, vector<long long>, greater<long long> > R;
	long long mn = abs(x), tagL = 0, tagR = 0;
	for (int i = 1; i <= n + 5; i++) {
		L.push(x);
		R.push(x);
	}
	for (int i = 2; i <= n; i++) {
		tagL += a[i] - r[i];
		tagR += a[i] - l[i];
		if (L.top() + tagL >= 0) {
			long long p = L.top();
			L.pop();
			mn += abs(p + tagL);
			R.push(p + tagL - tagR);
			L.push(-tagL);
			L.push(-tagL);
		} else if (R.top() + tagR <= 0) {
			long long p = R.top();
			R.pop();
			mn += abs(p + tagR);
			L.push(p + tagR - tagL);
			R.push(-tagR);
			R.push(-tagR);
		} else {
			L.push(-tagL);
			R.push(-tagR);
		}
	}
	long long tl = l[1] - a[1] + x, tr = r[1] - a[1] + x;
	if (L.top() + tagL <= tr && R.top() + tagR >= tl) return mn;
	else if (L.top() + tagL > tr) {
		long long slp = 1, lst = L.top();
		L.pop();
		while (!L.empty()) {
			long long p = L.top();
			L.pop();
			if (p + tagL <= tr) return mn + (lst + tagL - tr) * slp;
			mn += (lst - p) * slp;
			slp++;
			lst = p;
		}
	} else {
		long long slp = 1, lst = R.top();
		R.pop();
		while (!R.empty()) {
			long long p = R.top();
			R.pop();
			if (p + tagR >= tl) return mn + (tl - lst - tagR) * slp;
			mn += (p - lst) * slp;
			slp++;
			lst = p;
		}
	}
	assert(false);
	return -1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i], &l[i], &r[i]);
	long long lo = -2e9, hi = 2e9;
	while (lo < hi) {
		long long mid = lo + ((hi - lo) >> 1);
		if (calc(mid) < calc(mid + 1)) hi = mid;
		else lo = mid + 1;
	}
	printf("%lld\n", calc(hi));
	return 0;
}