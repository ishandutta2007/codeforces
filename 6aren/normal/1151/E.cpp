#include<bits/stdc++.h>

using namespace std;

int n, a[100005];

long long calc1(int x, int y) {
	if (x == y) return 0;
	if (x < y) return 1LL * (y - x) * x;
	if (x > y) return 1LL * (x - y) * (n + 1 - x); 
}

long long calc2(int x, int y, int z) {
	if (x < min(y, z)) {
		return calc1(x, min(y, z));
	}
	if (x > max(y, z)) {
		return calc1(x, max(y, z));
	}
	int mn = min(y, z), mx = max(y, z);
	return 1LL * (x - mn) * (mx - x);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) return cout << 1, 0;
	long long lr = 0, res = 0;
	lr += calc1(a[1], a[2]);
	lr += calc1(a[n], a[n - 1]);
	res += 1LL * a[1] * (n - a[1] + 1);
	res += 1LL * a[n] * (n - a[n] + 1);
	for (int i = 2; i <= n - 1; i++) {
		res += calc1(a[i], a[i - 1]) + calc1(a[i], a[i + 1]);
		lr += calc2(a[i], a[i - 1], a[i + 1]);
	}
	cout << (res - 2 * lr + calc1(a[1], a[2]) + calc1(a[n], a[n - 1])) / 2 + lr;
	return 0;
}