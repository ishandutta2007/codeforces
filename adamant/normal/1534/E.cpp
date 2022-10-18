#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % mod;
}

int mul(int a,int b) {
	return a * b % mod;
}

int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

int inv(int x) {
	return bpow(x, mod - 2);
}

int sub(int a, int b) {
	return (a + mod - b) % mod;
}

int dv(int a, int b) {
	return mul(a, inv(b));
}

const int maxn = 5e5 + 42;

#define all(x) begin(x), end(x)

int ask(vector<int> pos) {
	cout << "? ";
	for(auto it: pos) {
		cout << it << ' ';
	}
	cout << endl;
	int r;
	cin >> r;
	return r;
}

int ask(int r, int k) {
	vector<int> que(k);
	iota(all(que), r - k + 1);
	return ask(que);
}
vector<vector<int>> ques3(size_t n, size_t k) {
	vector<vector<int>> res;
	for(size_t a = 0; a <= n; a++) {
	for(size_t c = 0; c + a <= n; c++) {
	for(size_t d = 0; c + d + a <= n; d++) {
		size_t b = n - a - c;
		if((3 * a + b + 5 * c + 7 * d) % k == 0) {
			vector<int> sup(n);
			fill(begin(sup), begin(sup) + d, 7);
			fill(begin(sup) + d, begin(sup) + d + c, 5);
			fill(begin(sup) + d + c, begin(sup) + d + c + a, 3);
			fill(begin(sup) + d + c + a, end(sup), 1);
			int p[n];
			iota(p, p + n, 0);
			vector<vector<int>> ques;
			size_t cnt = 3 * a + b + 5 * c + 7 * d;
			while(cnt) {
				vector<int> cur;
				for(size_t i = 0; i < n && cur.size() < k; i++) {
					if(sup[p[i]]) {
						sup[p[i]]--;
						cur.push_back(p[i]);
					}
				}
				sort(p, p + n, [&](int x, int y){return sup[x] > sup[y];});
				if(cur.size() != k) {
					goto nxt;
				} else {
					cnt -= k;
					ques.push_back(cur);
				}
			}
			if(res.empty() || ques.size() < res.size()) {
				res = ques;
				cnt -= k;
			}
			nxt:;
		}
	}}}
	return res;
}

vector<vector<int>> ques2(size_t n, size_t k) {
	vector<vector<int>> res;
	for(size_t a = 0; a <= n; a++) {
	for(size_t c = 0; c + a <= n; c++) {
		size_t b = n - a - c;
		if((3 * a + b + 5 * c) % k == 0) {
			vector<int> sup(n);
			fill(begin(sup), begin(sup) + c, 5);
			fill(begin(sup) + c, begin(sup) + a + c, 3);
			fill(begin(sup) + a + c, end(sup), 1);
			int p[n];
			iota(p, p + n, 0);
			vector<vector<int>> ques;
			size_t cnt = 3 * a + b + 5 * c;
			while(cnt) {
				vector<int> cur;
				for(size_t i = 0; i < n && cur.size() < k; i++) {
					if(sup[p[i]]) {
						sup[p[i]]--;
						cur.push_back(p[i]);
					}
				}
				sort(p, p + n, [&](int x, int y){return sup[x] > sup[y];});
				if(cur.size() != k) {
					goto nxt;
				} else {
					cnt -= k;
					ques.push_back(cur);
				}
			}
			if(res.empty() || ques.size() < res.size()) {
				res = ques;
				cnt -= k;
			}
			nxt:;
		}
	}}
	return res;
}

vector<vector<int>> ques(size_t n, size_t k) {
	bool inv = false;
	if(n % 2 == 0 && 2 * k > n && k % 2 == 1) {
		k = n - k;
		inv = true;
	}
	vector<vector<int>> res;
	int sup[n];
	for(size_t a = 0; a <= k; a++) {
		size_t b = n - a;
		if((3 * a + b) % k == 0) {
			fill(sup, sup + a, 3);
			fill(sup + a, sup + n, 1);
			int p[n];
			iota(p, p + n, 0);
			vector<vector<int>> ques;
			size_t cnt = 3 * a + b;
			while(cnt) {
				vector<int> cur;
				cur.reserve(k);
				for(size_t i = 0; i < n && cur.size() < k; i++) {
					if(sup[p[i]]) {
						sup[p[i]]--;
						cur.push_back(p[i]);
					}
				}
				sort(p, p + n, [&](int x, int y){return sup[x] > sup[y];});
				if(cur.size() != k) {
					goto nxt;
				} else {
					cnt -= k;
					ques.push_back(cur);
				}
			}
			if(res.empty() || ques.size() < res.size()) {
				assert(a <= k);
				res = ques;
				cnt -= k;
			}
			nxt:;
		}
	}
	if(inv) {
		int usd[n];
		for(auto &it: res) {
			memset(usd, 0, sizeof usd);
			for(auto jt: it) {
				usd[jt] = 1;
			}
			it.clear();
			it.reserve(n - k);
			for(size_t i = 0; i < n; i++) {
				if(!usd[i]) {
					it.push_back(i);
				}
			}
		}
	}
	return res;
}

void solve() {
	size_t n, k;
	cin >> n >> k;
	if(k % 2 == 0 && n % 2 == 1) {
		cout << -1 << endl;
	} else {
		int ans = 0;
		for(auto it: ques(n, k)) {
			cout << "? ";
			for(auto jt: it) {
				cout << jt + 1 << ' ';
			}
			cout << endl;
			int x;
			cin >> x;
			ans ^= x;
		}
		cout << "! " << ans << endl;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*for(int n = 400; n <= 500; n++) {
		for(int k = 1; k <= n; k++) {
			if(k % 2 != 0 || n % 2 != 1) {
				assert(ques(n, k).size());
			} else {
				assert(!ques(n, k).size());
			}
		}
		cout << n << endl;
	}
	*/
	//ignore = freopen("input.txt", "r", stdin);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
}