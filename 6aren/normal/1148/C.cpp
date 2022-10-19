#include<bits/stdc++.h>

using namespace std;

int n, pos[300005], a[300005];
vector<pair<int, int>> res;

void mySwap(int i, int j) {
	if (i == j) return;
	if (2 * abs(i - j) >= n) {
		res.push_back(make_pair(i, j));
		return;
	}
	if ((i - 1) / (n / 2) == (j - 1) / (n / 2)) {
		int u;
		if ((i - 1) / (n / 2) == 0) u = n;
		else u = 1;
		res.push_back(make_pair(j, u));
		res.push_back(make_pair(i, u));
		res.push_back(make_pair(j, u));
	} else {
		int u, v;
		if ((i - 1) / (n / 2) == 0) {
			u = 1; v = n;
		} else {
			u = n; v = 1;
		}
		res.push_back(make_pair(u, j));
		res.push_back(make_pair(i, v));
		res.push_back(make_pair(u, v));
		res.push_back(make_pair(u, j));
		res.push_back(make_pair(i, v));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		pos[u] = i;
		a[i] = u;
	}
	for (int i = 1; i <= n; i++) {
		mySwap(pos[i], i);
		int temp = a[i];
		int temp2 = pos[i];
		a[i] = a[pos[i]];
		a[pos[i]] = temp;
		pos[i] = i;
		pos[temp] = temp2;
	}
	cout << res.size() << endl;;
	for (auto u : res) {
		cout << u.first << ' ' << u.second << endl;
	}
	return 0;
}