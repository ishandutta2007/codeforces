#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

long long bit[N];

void update(int k, long long val) {
	for (int i = k; i < N; i += (i & (-i))) {
		bit[i] += val;
	}
}

void update(int l, int r, long long val) {
	update(l, val);
	update(r + 1, -val);
}

long long get(int k) {
	long long res = 0;
	for (int i = k; i > 0; i -= (i & (-i))) {
		res += bit[i];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	set<tuple<int, int, int>> s;
	s.insert(make_tuple(1, n, 1));
	vector<long long> offset(n + 1);
	while (q--) {
		string type;
		cin >> type;
		if (type == "Color") {
			int l, r, col;
			cin >> l >> r >> col;
			// cerr << "Color" << ' ' << l << ' ' << r << ' ' << col << endl;
			// split first seg
			{
				auto it = s.lower_bound(make_tuple(l + 1, 0, 0));
				it--;
				int u = get<0>(*it);
				int v = get<1>(*it);
				int preCol = get<2>(*it);
				s.erase(*it);
				if (l > u) {
					s.insert(make_tuple(u, l - 1, preCol));
				}
				s.insert(make_tuple(l, v, preCol));
			}
			// split last seg
			{
				auto it = s.lower_bound(make_tuple(r + 1, 0, 0));
				it--;
				int u = get<0>(*it);
				int v = get<1>(*it);
				int preCol = get<2>(*it);
				s.erase(*it);
				if (r < v) {
					s.insert(make_tuple(r + 1, v, preCol));
				}
				s.insert(make_tuple(u, r, preCol));
			}

			// erase
			{
				vector<tuple<int, int, int>> toDelete;
				auto it = s.lower_bound(make_tuple(l, 0, 0));
				while (true) {
					if (it == s.end() || get<0>(*it) > r) 
						break;
					// cerr << get<0>(*it) << ' ' << get<1>(*it) << ' ' << get<2>(*it) << endl;
					update(get<0>(*it), get<1>(*it), offset[get<2>(*it)]);
					toDelete.emplace_back(*it);
					it++;
				}
				for (auto e : toDelete) {
					s.erase(e);
				}
				s.insert(make_tuple(l, r, col));
				update(l, r, -offset[col]);
			}
		} else if (type == "Add") {
			int c, x;
			cin >> c >> x;
			offset[c] += x;
		} else {
			int i;
			cin >> i;
			long long res = get(i);
			auto it = s.lower_bound(make_tuple(i + 1, 0, 0));
			it--;
			// cerr << "res " << res << endl;
			res += offset[get<2>(*it)];
			cout << res << '\n';
		}
	}
}