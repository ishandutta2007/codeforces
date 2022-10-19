#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 200005;
const int INF = 1000000001;

int it[4 * N], n, q;

void build(int k, int l, int r) {
	if (l == r) {
		it[k] = INF;
		return;
	}
	int mid = (l + r) / 2;
	build(2 * k, l, mid);
	build(2 * k + 1, mid + 1, r);
	it[k] = min(it[2 * k], it[2 * k + 1]);
}

void update(int k, int l, int r, int id, int val) {
	if (l > id || r < id) {
		return;
	}
	if (l == id && r == id) {
		it[k] = min(it[k], val);
		return;
	}
	int mid = (l + r) / 2;
	update(2 * k, l, mid, id, val);
	update(2 * k + 1, mid + 1, r, id, val);
	it[k] = min(it[2 * k], it[2 * k + 1]);
}

int get(int k, int l, int r, int u, int v) {
	if (l > v || r < u) {
		return INF;
	}
	if (l >= u && r <= v) {
		return it[k];
	}
	int mid = (l + r) / 2;
	return min(get(2 * k, l, mid, u, v), get(2 * k + 1, mid + 1, r, u, v));
}

void solve() {
	cin >> n >> q;
	build(1, 1, n);
	set<int> possible;
	for (int i = 1; i <= n; i++) {
		possible.insert(i);
	}
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			if (x == 0) {
				while (true) {
					auto it = possible.lower_bound(l);
					if (it == possible.end() || *it > r) {
						break;
					}
					possible.erase(it);
				}
			} else {
				update(1, 1, n, l, r);
			}
		} else {
			int j;
			cin >> j;
			auto it = possible.find(j);
			if (it == possible.end()) {
				cout << "NO\n";
				continue;
			} else {
				int l = 0;
				if (it != possible.begin()) {
					it--;
					l = *it;
					it++;
				}
				int r = n + 1;
				it++;
				if (it != possible.end()) {
					r = *it;
				}
				l++, r--;
				bool ok = false;
				if (r >= l) {
					ok |= get(1, 1, n, l, r) <= r;
				}
				cout << (ok ? "YES\n" : "N/A\n");
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt = 1;
	while (tt--) {
		solve();
	}

}