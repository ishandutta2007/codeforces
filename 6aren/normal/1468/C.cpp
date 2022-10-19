#include <bits/stdc++.h>
using namespace std;

int m[500005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int q;
	cin >> q;

	set<int> mono;
	set<pair<int, int>> poly;
	int id = 0;

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			id++;
			cin >> m[id];
			mono.insert(id);
			poly.insert({-m[id], id});
		} else if (type == 2) {
			int foo = *mono.begin();
			mono.erase(mono.begin());
			poly.erase(make_pair(-m[foo], foo));
			cout << foo << ' ';
		} else {
			auto foo = *poly.begin();
			poly.erase(poly.begin());
			mono.erase(foo.second);
			cout << foo.second << ' ';
		}
	}

	cout << '\n';


	return 0;
}