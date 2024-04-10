#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define pb emplace_back
#define mp make_pair

typedef long long ll;
typedef double lf;

int n, m;
std::unordered_map<string, pair<int, int> > d;
std::string cur;
std::map<int, int> q;

void rec(size_t pos, const std::string &s) {
	if (pos == s.size()) {
		if (d.count(cur)) {
			q.insert(d[cur]);
		}
		return;
	}
	if (s[pos] != '?') {
		cur += s[pos];
		rec(pos + 1, s);
		cur.pop_back();
	} else {
		rec(pos + 1, s);
		for (char c = 'a'; c <= 'e'; ++c) {
			cur += c;
			rec(pos + 1, s);
			cur.pop_back();
		}
	}
}

int main() {
	srand(131);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		++d[s].second;
		d[s].first = i;
	}
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		q.clear();
		rec(0, s);
		int ans = 0;
		for (const auto &p: q) {
			ans += p.second;
		}
		cout << ans << '\n';
	}
	return 0;
}