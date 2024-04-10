#include<bits/stdc++.h>

using namespace std;

int n;

void que(int x) {
	cout << "? " << x << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int u, v;
	cin >> n;
	n /= 2;
	que(1);
	cin >> u;
	que(1 + n);
	cin >> v;
	int vl = u - v, vr = v - u, l = 2, r = n;
	if (vl == 0) {
		cout << "! " << l << endl;
		return 0;
	}
	while (r - l > 1) {
		int mid = (l + r) / 2;
		que(mid);
		cin >> u;
		que(mid + n);
		cin >> v;
		if (u == v) {
			cout << "! " << mid << endl;
			return 0;
		}
		if (1LL * (u - v) * vl < 0) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	for (int i = r; i >= l; i--) {
		que(i);
		cin >> u;
		que(i + n);
		cin >> v;
		if (u == v) {
			cout << "! " << i << endl;
			return 0;
		}
	}
	cout << "! " << -1 << endl;
	return 0;
}