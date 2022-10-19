#include<bits/stdc++.h>

using namespace std;

int n, a[200005], cnt[200005];

vector<pair<int, pair<int, int>>> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	int mx = -1, index = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i <= 200000; i++) {
		if (cnt[i] > mx) {
			mx = cnt[i];
			index = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == index) {
			index = i;
			mx = a[i];
			break;
		}
	}
	for (int i = index - 1; i >= 1; i--) {
		int u;
		if (a[i] < mx) u = 1;
		else u = 2;
		v.push_back(make_pair(u, make_pair(i, i + 1)));
	}
	for (int i = index + 1; i <= n; i++) {
		if (a[i] == mx) continue;
		int u;
		if (a[i] < mx) u = 1;
		else u = 2;
		v.push_back(make_pair(u, make_pair(i, i - 1)));
	}
	cout << v.size() << endl;;
	for (auto u : v) {
		cout << u.first << ' ' << u.second.first << ' ' << u.second.second << endl;
	}
	return 0;
}