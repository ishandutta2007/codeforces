#include<bits/stdc++.h>

using namespace std;

string s;
int n;
vector<int> v[2];

int calc(int k) {
	v[0].clear();
	v[1].clear();
	for (int i = k; i < min(n, k + 20); i++) {
		int u = s[i] - '0';
		for (auto j : v[u]) {
			if (2 * j - i < k) continue;
			if (s[2 * j - i] == '0' + u) return (n - i);
		}
		v[u].push_back(i);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> s;
	n = s.size();
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += calc(i);
	}
	cout << res;

	return 0;
}