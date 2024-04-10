#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

const int maxn = 2e5 + 42;
int cnt[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	cout << "YES" << endl;
	cout << string(n, '.') << endl;
	if(k % 2 == 0) {
		string t(n, '.');
		for(int i = 1; i <= k / 2; i++) {
			t[i] = '#';
		}
		cout << t << endl;
		cout << t << endl;
	} else {
		string t(n, '.');
		int k1 = min(k, n - 2);
		int L = (n - k1) / 2, R = n - (n - k1) / 2 - 1;
		for(int i = L; i <= R; i++) {
			t[i] = '#';
		}
		cout << t << endl;
		if(k > (n - 2)) {
			k -= n - 2;
			string t(n, '.');
			for(int i = 0; i < k / 2; i++) {
				t[i + 1] = t[n - i - 2] = '#';
			}
			cout << t << endl;
		} else {
			cout << string(n, '.') << endl;	
		}
	}
	cout << string(n, '.') << endl;
	return 0;
}