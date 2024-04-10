#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

bool is_prime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int z;
	cin >> z;
	for(int n = z; n <= z; n++) {
		if(n == 4) {
			cout << 5 << endl;
			cout << "1 2" << endl;
			cout << "2 3" << endl;
			cout << "3 4" << endl;
			cout << "4 1" << endl;
			cout << "1 3" << endl;
			continue;
		}
		int m = n;
		while(!is_prime(m)) {
			m++;
		}
		vector<vector<int>> cycles;
		for(int i = 0; i + 3 <= n; i += 3) {
			cycles.push_back({i, i + 1, i + 2});
		}
		if(n % 3 == 1) {
			cycles.back().push_back(n - 1);
		} else if(n % 3 == 2) {
			cycles.back().push_back(n - 1);
			cycles.back().push_back(n - 2);
		}
		cout << m << endl;
		for(auto it: cycles) {
			for(size_t i = 0; i < it.size(); i++) {
				cout << it[i] + 1 << ' ' << it[(i + 1) % it.size()] + 1 << endl;
			}
		}
		m -= n;
		for(size_t i = 0; i + 1 < cycles.size(); i += 2) {
			if(m >= 9) {
				for(int it = 0; it < 3; it++) {
					for(int jt = 0; jt < 3; jt++) {
						cout << cycles[i][it] + 1 << ' ' << cycles[i + 1][jt] + 1 << endl;
					}
				}
				m -= 9;
			} else {
				for(int z = 0; z < min<int>(3, m); z++) {
					cout << cycles[i][z] + 1 << ' ' << cycles[i + 1][z] + 1 << endl;
				}
				m -= min<int>(3, m);
			}
		}
		assert(m == 0);
	}
	return 0;
}