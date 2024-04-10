#define _CTR_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

struct Node {
	map<char, int> to;
	int mxln;
	int lk;
	Node() : to(), mxln(0), lk(-1) {}
	Node(int mxln) : to(), mxln(mxln), lk(-1) {}
	Node(const map<char, int>& to, int mxln, int lk) : to(to), mxln(mxln), lk(lk) {}
};

vector<Node> au(1);
int lst;

void append(char ch) {
	int cur = sz(au);
	au.emplace_back(au[lst].mxln + 1);
	int pv = lst;
	for (; pv != -1 && !au[pv].to.count(ch); pv = au[pv].lk) {
		au[pv].to[ch] = cur;
	}
	if (pv == -1) {
		au[cur].lk = 0;
	}
	else {
		int nxt = au[pv].to[ch];
		if (au[nxt].mxln == au[pv].mxln + 1) {
			au[cur].lk = nxt;
		}
		else {
			int cl = sz(au);
			au.emplace_back(au[nxt].to, au[pv].mxln + 1, au[nxt].lk);
			au[cur].lk = au[nxt].lk = cl;
			for (; pv != -1 && au[pv].to[ch] == nxt; pv = au[pv].lk) {
				au[pv].to[ch] = cl;
			}
		}
	}
	lst = cur;
}

vector<pii> tps;
vector<vi> dp;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<string> a(1);
	cin >> a[0];
	int n;
	cin >> n;
	a.resize(n + 1);
	vi l(n + 1), r(n + 1);
	l[0] = 1;
	r[0] = 1e9;
	for (auto c : a[0]) {
		append(c);
	}
	append('A');
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1] >> l[i + 1] >> r[i + 1];
		for (auto c : a[i + 1]) {
			append(c);
		}
		append('A' + i + 1);
	}
	dp.resize(sz(au), vi(n + 1, 0));
	int v = 0;
	for (int i = 0; i < n + 1; i++) {
		for (auto c : a[i]) {
			v = au[v].to[c];
			dp[v][i]++;
		}
		v = au[v].to['A' + i];
	}
	tps.resize(sz(au));
	for (int i = 0; i < sz(au); i++) {
		tps[i] = mp(au[i].mxln, i);
	}
	sort(all(tps));
	reverse(all(tps));
	ll ans = 0;
	tps.pop_back();
	for (auto el : tps) {
		auto v = el.second;
		bool ok = true;
		for (int i = 0; i < n + 1; i++) {
			ok &= (l[i] <= dp[v][i] && dp[v][i] <= r[i]);
		}
		if (ok) {
			ans += (au[v].mxln - au[au[v].lk].mxln);
		}
		for (int i = 0; i < n + 1; i++) {
			dp[au[v].lk][i] += dp[v][i];
		}
	}
	cout << ans;
}