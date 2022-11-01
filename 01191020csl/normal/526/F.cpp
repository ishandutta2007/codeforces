#include<bits/stdc++.h>
using namespace std;
int a[300001], minn[300001], maxn[300001];
int cnt[1000001], *pt = &cnt[330000];
long long solve(int l, int r) {
	if (l == r) return 1;
	int mid = (l + r) / 2;
	long long ans = solve(l, mid) + solve(mid + 1, r);
	minn[mid] = maxn[mid] = a[mid];
	for (int i = mid - 1; i >= l; i--) minn[i] = min(minn[i+1], a[i]), maxn[i] = max(maxn[i+1], a[i]);
	minn[mid+1] = maxn[mid+1] = a[mid+1];
	for (int i = mid + 2; i <= r; i++) minn[i] = min(minn[i-1], a[i]), maxn[i] = max(maxn[i-1], a[i]);
	for (int i = l; i <= mid; i++) {
		int len = maxn[i] - minn[i], j = i + len;
		if (j <= mid || j > r) continue;
		if (maxn[j] < maxn[i] && minn[j] > minn[i]) ++ans;
	}
	for (int i = mid + 1; i <= r; i++) {
		int len = maxn[i] - minn[i], j = i - len;
		if (j < l || j > mid) continue;
		if (maxn[j] < maxn[i] && minn[j] > minn[i]) ++ans;
	}
	int p1 = r + 1, p2 = r;
	for (int i = l; i <= mid; i++) {
		while (p1 > mid && maxn[p1-1] > maxn[i]) --p1, ++*(pt+maxn[p1]-p1);
		while (p2 > mid && minn[p2] <= minn[i]) --*(pt+maxn[p2]-p2), --p2;
		if (p1 > p2) continue;
		ans += *(pt+minn[i]-i);
	}
	for (int i = mid + 1; i <= r; i++) *(pt+maxn[i]-i) = 0;
	p1 = r + 1, p2 = r;
	for (int i = l; i <= mid; i++) {
		while (p1 > mid && minn[p1-1] < minn[i]) --p1, ++*(pt+minn[p1]+p1);
		while (p2 > mid && maxn[p2] >= maxn[i]) --*(pt+minn[p2]+p2), --p2;
		if (p1 > p2) continue;
		ans += *(pt+maxn[i]+i);
	}
	for (int i = mid + 1; i <= r; i++) *(pt+minn[i]+i) = 0;
	return ans;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, c;
		cin >> r >> c;
		a[r] = c;
	}
	cout << solve(1, n) << endl;
}