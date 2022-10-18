#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> rem;

void parse(string &s, int l, int r) {
	if(l >= r) {
		return;
	} else if(s[l] == '(' && s[r] == ')') {
		rem.insert(l);
		rem.insert(r);
		l++, r--;
	} else {
		l += s[l] == ')';
		r -= s[r] == '(';
	}
	parse(s, l, r);
}

void solve() {
	string s;
	cin >> s;
	parse(s, 0, s.size() - 1);
	cout << (rem.size() ? 1 : 0) << endl;
	if(rem.size()) {
		cout << rem.size() << endl;
		for(auto it: rem) {
			cout << it + 1 << ' ';
		}
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}