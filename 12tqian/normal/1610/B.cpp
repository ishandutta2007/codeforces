#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	vector<vector<int>> locs(n);
	for (int i = 0; i < n; ++i) {
		locs[a[i]].push_back(i);
	}
	Tree<int> t;
	vector<int> added;
	for (int i = 0; i < n; ++i) {
		for (int x : locs[i]) {
			t.insert(x);
		}
		if (!locs[i].empty()) {
			added.push_back(i);
		}
		vector<int> pos;
		for (int x : locs[i]) {
			pos.push_back(t.order_of_key(x));
		}
		int sz = (int)t.size();
		int cnt = (int)pos.size();
		bool fail = false;
		for (int i = 0; i < cnt; ++i) {
			if (pos[i] != sz - 1 - pos[cnt - 1 - i]) {
				fail = true;
				break;
			}
		}
		if (fail) {
			break;
		}
	}
	auto check = [&](int fail) {
		vector<int> use;
		for (int x : a) {
			if (x != fail) {
				use.push_back(x);
			}
		}
		int sz = (int)use.size();
		for (int i = 0; i < sz; ++i) {
			if (use[i] != use[sz - 1 - i]) {
				return false;
			}
		}
		return true;
	};
	bool ok = false;
	ok |= check(added[0]);
	ok |= check(added.back());
	if ((int)added.size() >= 3) {
		ok |= check(added[1]);
		ok |= check(added[(int)added.size() - 2]);
	}
	if (ok) {
		cout << "YES" << '\n';
	} else {
		int lst = added.back();
		added.pop_back();
		t.clear();
		for (int x : locs[lst]) {
			t.insert(x);
		}
		for (int i = 0; i < lst; ++i) {
			for (int x : locs[i]) {
				t.insert(x);
			}
			vector<int> pos;
			for (int x : locs[i]) {
				pos.push_back(t.order_of_key(x));
			}
			int sz = (int)t.size();
			int cnt = (int)pos.size();
			bool fail = false;
			for (int i = 0; i < cnt; ++i) {
				if (pos[i] != sz - 1 - pos[cnt - 1 - i]) {
					fail = true;
					break;
				}
			}
			if (fail) {
				if (check(i)) {
					cout << "YES" << '\n';
					return;
				} else {
					cout << "NO" << '\n';
					return;
				}
			}
			for (int x : locs[i]) {
				t.erase(x);
			}
		}
		cout << "NO" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}