#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int count_in_rnage(vector<int>& a, int l, int r) {
	return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}

int solve(vector<int> a, vector<int> b) {
	if (a.empty() || b.empty()) {
		return 0;
	}
	unordered_set<int> present;
	for (auto x : b) {
		present.insert(x);
	}
	vector<int> suf_match(a.size() + 1);
	for (int i = a.size() - 1; i >= 0; i--) {
		suf_match[i] = suf_match[i + 1] + present.count(a[i]);
	}
	int best = 0;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] < a[0]) {
			continue;
		}
		int lf = 0, rg = a.size() - 1;
		while (lf < rg) {
			int md = (lf + rg + 1) >> 1;
			if (a[md] <= b[i] + md) {
				lf = md;
			}
			else {
				rg = md - 1;
			}
		}
		best = max(best, count_in_rnage(b, b[i], b[i] + lf) + suf_match[lf + 1]);
	}
	return best;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> al, ar;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			al.push_back(x);
		}
		else {
			ar.push_back(-x);
		}
	}
	sort(al.begin(), al.end());
	sort(ar.begin(), ar.end());
	vector<int> bl, br;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			bl.push_back(x);
		}
		else {
			br.push_back(-x);
		}
	}
	sort(bl.begin(), bl.end());
	sort(br.begin(), br.end());
	cout << solve(al, bl) + solve(ar, br) << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}