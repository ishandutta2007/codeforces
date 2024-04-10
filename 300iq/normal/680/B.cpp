#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
bool can[MAXN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int sum = 0, ans = 0;
	int n, a, x;
	cin >> n >> a;
	a--;
	vector <int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && abs(i - a) == abs(j - a) && !(b[i] && b[j]) && (b[i] || b[j])) {
				can[i] = can[j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ans += !can[i] * b[i];
	}
	cout << ans << endl;
}