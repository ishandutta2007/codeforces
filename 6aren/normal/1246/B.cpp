#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k, a[100005], minp[100005], dem[100005];

int calc(int u) {
	int res = 1;
	while (u != 1) {
		int p = minp[u];
		int cnt = 0;
		while (u % p == 0) {
			cnt++;
			u /= p;
		}
		cnt %= k;
		for (int i = 1; i <= cnt; i++) {
			res *= p;
		}
	}
	return res;
} 

int rev(int u) {
	long long res = 1;
	while (u != 1) {
		int p = minp[u];
		int cnt = 0;
		while (u % p == 0) {
			cnt++;
			u /= p;
		}
		cnt %= k;
		cnt = k - cnt;
		for (int i = 1; i <= cnt; i++) {
			res = res * p;
			if (res > 100000) res = 100001;
		}
	}
	return res;
}

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= 100000; i++) {
		minp[i] = i;
	}
	for (int i = 2; i <= 100000; i++) {
		if (minp[i] == i) {
			for (int j = i * i; j <= 100000; j += i) {
				if (minp[j] == j) minp[j] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = calc(a[i]);
	}
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += dem[rev(a[i])];
		dem[a[i]]++;
	}
	cout << res;
	return 0;
}