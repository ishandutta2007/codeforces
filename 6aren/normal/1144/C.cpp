#include<bits/stdc++.h>

using namespace std;

int n, a[200005], cnt[200005];

vector<int> v[2];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 0; i <= 200000; i++) {
		if (cnt[i] > 2) return cout << "NO", 0;
	}
	bool sw = 0;
	for (int i = 1; i <= n; i++) {
		v[sw].push_back(a[i]);
		sw ^= 1;
	}
	cout << "YES" << endl;
	cout << v[0].size() << endl;
	for (int u : v[0]) {
		cout << u << ' ';
	}
	cout << endl;
	cout << v[1].size() << endl;
	for (int i = (int) v[1].size() - 1; i >= 0; i--) {
		cout << v[1][i] << ' ';
	}
	cout << endl;
	return 0;
}