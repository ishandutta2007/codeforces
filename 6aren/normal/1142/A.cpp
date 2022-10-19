#include<bits/stdc++.h>

using namespace std;

long long n, k, a, b;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k >> a >> b;
	long long t = n * k;
	long long mx = 0, mn = 1e18;
	for (int i = 1; i <= n; i++) {
		long long temp = i * k + b - a;
		long long cnt = (n * k) / __gcd(n * k, temp);
		mx = max(mx, cnt);
		mn = min(mn, cnt);
	}
	if (b == 0) cout << mn << " " << mx;
	else {
		b = k - b;
		for (int i = 1; i <= n; i++) {
			long long temp = i * k + b - a;
			long long cnt = (n * k) / __gcd(n * k, temp);
			mx = max(mx, cnt);
			mn = min(mn, cnt);
		}
		cout << mn << " " << mx << endl;
	}
	return 0;
}