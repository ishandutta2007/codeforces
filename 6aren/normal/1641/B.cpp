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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (auto it : cnt) {
		if (it.second % 2 == 1) {
			cout << -1 << '\n';
			return;
		}
	}
	vector<int> parts;
	vector<pair<int, int>> res;
	int curCut = 0;
	while (a.size() > 0) {
		int id = 1;
		for (int i = 1; i < a.size(); i++) {
			if (a[i] == a[0]) {
				id = i;
				break;
			}
		}
		vector<int> added;
		for (int i = 1; i < id; i++) {
			res.emplace_back(a[i], curCut + id + i);
			added.push_back(a[i]);
		}
		parts.push_back(2 * id);
		curCut += 2 * id;
		a.erase(a.begin(), a.begin() + id + 1);
		reverse(a.begin(), a.end());
		for (int e : added) 
			a.push_back(e);
		reverse(a.begin(), a.end());
	}
	cout << res.size() << '\n';
	for (auto [u, v] : res) {
		cout << v << ' ' << u << '\n';
	}
	cout << parts.size() << '\n';
	for (int e : parts) 
		cout << e << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

}