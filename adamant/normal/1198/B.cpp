#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int mul(int a, int b) {
	return a * b % mod;
}
int add(int a, int b) {
	return (a + b) % mod;
}

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = -1;
	}
	int q;
	cin >> q;
	vector<int> last = {0}, val = {0};
	for(int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int p, x;
			cin >> p >> x;
			a[p - 1] = x;
			b[p - 1] = i;
			//cout << p - 1 << ' ' << "!!" << endl;
		} else {
			int x;
			cin >> x;
			last.push_back(i);
			val.push_back(x);
		}
	}
	int m = last.size();
	vector<int> rev(m);
	rev.back() = val.back();
	for(int i = m - 2; i >= 0; i--) {
		rev[i] = max(rev[i + 1], val[i]);
	}
	for(int i = 0; i < n; i++) {
		if(b[i] >= last.back()) {
			cout << a[i] << ' ';
		} else {
			auto it = lower_bound(all(last), b[i]) - begin(last);
			//cout << i << ' ' << a[i] << ' ' << b[i] << ' ' << it << ' ' << rev[it] << endl;
			cout << max(a[i], rev[it]) << ' ';
		}
	}
	return 0;
}