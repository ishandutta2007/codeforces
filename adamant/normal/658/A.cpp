#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	int p[n], t[n];
	double A = 0, B = 0;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	int ta = 0, tb = 0;
	for(int i = 0; i < n; i++) {
		ta += t[i];
		tb += t[n - i - 1];
		A += max<int>(0, p[i] - (ta * c));
		B += max<int>(0, p[n - i - 1] - tb * c);
	}
	if(A > B) {
		cout << "Limak" << endl;
	} else if(A == B) {
		cout << "Tie" << endl;
	} else {
		cout << "Radewoosh" << endl;
	}
	return 0;
}