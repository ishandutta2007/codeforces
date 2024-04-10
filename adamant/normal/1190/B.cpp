#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string pa = "sjfnb";
	string pb = "cslnb";
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if(n == 1) {
		cout << (a[0] % 2 ? pa : pb) << endl;
	} else {
		int cnt = 0;
		for(int i = 1; i < n; i++) {
			cnt += a[i] == a[i - 1];
		}
		int moves = 0;
		if(cnt > 1) {
			cout << pb << endl;
			return 0;
		} else if(cnt == 1) {
			for(int i = 1; i < n; i++) {
				if(a[i] == a[i - 1]) {
					a[i - 1]--;
					if(a[i] == 0) {
						cout << pb << endl;
						return 0;
					}
				}
			}
			moves++;
			for(int i = 1; i < n; i++) {
				if(a[i] == a[i - 1]) {
					cout << pb << endl;
					return 0;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			moves += a[i] - i;
		}
		int winner = (moves % 2);
		cout << (winner ? pa : pb) << endl;
	}
	return 0;
}