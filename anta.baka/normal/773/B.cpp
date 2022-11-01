#include <bits/stdc++.h>

using namespace std;

int n, tourist[5], petr[5], cnt[5], send[5];

int cst(int x, int y) {
	for(int i = 5; i >= 0; i--) {
		if(x * (1 << i) <= y) {
			return (i + 1) * 500;
		}
	}
}

main() {
	cin >> n;
	for(int i = 0; i < 5; i++) {
		cin >> tourist[i];
		if(tourist[i] != -1) {
			cnt[i]++;
		}
	}
	for(int i = 0; i < 5; i++) {
		cin >> petr[i];
		if(petr[i] != -1) {
			cnt[i]++;
		}
	}
	for(int i = 2; i < n; i++) {
		for(int j = 0; j < 5; j++) {
			int x;
			cin >> x;
			if(x != -1) {
				cnt[j]++;
			}
		}
	}
	for(int i = 0; i < 5; i++) {
			if(tourist[i] != -1 && petr[i] != -1 && tourist[i] > petr[i]) {
				send[i] = 1;
			}
	}
	for(int x = 0; x <= 31 * n; x++) {
		double sum1 = 0, sum2 = 0;
		for(int i = 0; i < 5; i++) {
			int w;
			if(send[i] == 0) {
				w = cst(cnt[i], n + x);
			} else {
				w = cst(cnt[i] + x, n + x);
			}
			if(tourist[i] != -1) {
				sum1 += w * (1 - tourist[i] / 250.0);
			}
			if(petr[i] != -1) {
				sum2 += w * (1 - petr[i] / 250.0);
			}
		}
		if(sum1 > sum2) {
			cout << x;
			return 0;
		}
	}
	cout << -1;
}