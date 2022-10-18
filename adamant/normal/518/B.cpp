#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	map<char, int> cnt[2];
	for(auto it: a) {
		cnt[0][it]++;
	}
	for(auto it: b) {
		cnt[1][it]++;
	}
	int A = 0, B = 0;
	for(auto it: cnt[0]) {
		char c = it.first;
		int t = min(cnt[0][c], cnt[1][c]);
		A += t;
		cnt[0][c] -= t;
		cnt[1][c] -= t;
	}
	for(auto it: cnt[0]) {
		char c = it.first;
		char C = islower(c) ? toupper(c) : tolower(c);
		int t = min(cnt[0][c], cnt[1][C]);
		B += t;
		cnt[0][c] -= t;
		cnt[1][C] -= t;
	}
	cout << A << ' ' << B << endl;
	return 0;
}