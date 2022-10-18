#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

point cmul(point a, point b) {
    return conj(a) * b;
}
ftype dot(point a, point b) {
    return cmul(a, b).x();
}
ftype cross(point a, point b) {
    return cmul(a, b).y();
}

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;


signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	set<pair<int, int>> all_elems;
	set<int> poses[q + 1];
	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		if(a[i]) {
			poses[a[i]].insert(i);
		}
		all_elems.insert({i, a[i]});
	}
	bool colored_fin = !poses[q].empty();
	for(int i = q; i >= 1; i--) {
		while(poses[i].size()) {
			auto it1 = poses[i].begin();
			rep:
			auto it2 = next(all_elems.lower_bound({*it1, 0}));
			if(it2 != end(all_elems) && it2->second != i && poses[i].size() != 1) {
				if(it2->second == 0) {
					a[it2->first] = i;
					all_elems.erase(it2);
					goto rep;
				}
				cout << "NO" << endl;
				return 0;
			}
			poses[i].erase(it1);
			all_elems.erase(prev(it2));
		}
	}
	if(!colored_fin) {
		for(int i = 0; i < n; i++) {
			if(b[i] == 0) {
				b[i] = q;
				colored_fin = true;
				break;
			}
		}
		if(!colored_fin) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i = 1; i < n; i++) {
		b[i] = b[i] ? b[i] : b[i - 1];
	}
	for(int i = n - 2; i >= 0; i--) {
		b[i] = b[i] ? b[i] : b[i + 1];
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++) {
		cout << (b[i] ? b[i] : 1) << ' ';
	}
	return 0;
}