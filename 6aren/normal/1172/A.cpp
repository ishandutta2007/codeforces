#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, a[N], b[N], diff[N];

void case1() {
	for (int i = 1; i <= n; i++) {
		diff[b[i]] = n - i + 1;
	}
	int maxi = 0;
	for (int i = 1; i < n; i++) {
		maxi = max(maxi, diff[i] - n + i);
	}
	cout << n + maxi;
	exit(0);
}

void case2(int mark) {
	for (int i = 1; i <= n; i++) {
		diff[i] = 0;
	}
	for (int i = mark - 1; i >= 1; i--) {
		diff[b[i]] = mark - i;
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		maxi = max(maxi, diff[i] - n + i);
	}
	cout << n + maxi + n - mark + 1;
	exit(0);
}

void case3(int mark, int u) {
	for (int i = n; i > mark; i--) {
		diff[b[i]] = n + 1 - i;
	}
	bool flag = false;
	for (int i = 1; i <= u; i++) {
		if (u - i < diff[i]) {
			flag = true;
			break;
		}
	}
	if (flag) {
		case2(mark);
	} else {
		cout << u;
		exit(0);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0) a[i] = n + 1 - a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i] != 0) b[i] = n + 1 - b[i];
	}
	for (int i = 1; i <= n / 2; i++) {
		swap(b[i], b[n + 1 - i]);
	}
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (a[i] == n) {
			flag = true;
			break;
		}
	}

	if (flag) {
		case1();
	}
	int mark = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == n) {
			mark = i;
			break;
		}
	}
	for (int i = mark - 1; i >= 1; i--) {
		if (n - b[i] != mark - i) {
			flag = true;
			break;
		}
	}
	if (flag) {
		case2(mark);
	} else {
		case3(mark, n - mark);
	}
	return 0;
}