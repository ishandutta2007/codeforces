#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <array>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;

struct Node {
	vi to;
	int lk;
	ll w;
	Node() : to(14), lk(0), w(0) {}
};

vector<Node> au(1);
int sz = 1;

void add(const string& s, int w) {
	int v = 0;
	for (char c : s) {
		c -= 'a';
		if (!au[v].to[c]) {
			au[v].to[c] = sz++;
			au.pb(Node());
		}
		v = au[v].to[c];
	}
	au[v].w += w;
}

void build() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		au[v].w += au[au[v].lk].w;
		for (char kek = 'a'; kek <= 'n'; kek++) {
			auto c = kek - 'a';
			if (au[v].to[c]) {
				int u = au[v].to[c];
				au[u].lk = (v ? au[au[v].lk].to[c] : 0);
				q.push(u);
			}
			else {
				au[v].to[c] = au[au[v].lk].to[c];
			}
		}
	}
}

ll dp[1 << 14][1001];
ll dp_new[1 << 14][1001];

const ll inf = 1e18 + 228;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string s;
		int w;
		cin >> s >> w;
		add(s, w);
	}
	build();
	string s;
	cin >> s;
	string KEK = s;
	int n = sz(s);
	const ll inf = 1e18 + 228;
	vi bpc(1 << 14);
	for (int msk = 1; msk < (1 << 14); msk++) {
		bpc[msk] = 1 + bpc[msk & (msk - 1)];
	}
	vi qps;
	ll ans_add = 0;
	int v = 0;
	int lst = -sz;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') qps.pb(i), v = 0, lst = i;
		else v = au[v].to[s[i] - 'a'];
		if(i - lst >= sz) ans_add += au[v].w;
	}
	for (int i = 0; i < (1 << 14); i++) {
		for (int j = 0; j < sz; j++) {
			dp[i][j] = dp_new[i][j] = -inf;
		}
	}
	dp[0][0] = 0;
	int pi = (qps.empty() || qps[0] < sz ? 0 : qps[0] - sz);
	int yet = 0;
	vector<vi> msks(15);
	for (int m = 0; m < (1 << 14); m++) {
		msks[bpc[m]].pb(m);
	}
	for (int i : qps) {
		pi = max(pi, i - sz);
		for(int m : msks[yet]) {
			for (int s = 0; s < sz; s++) {
				dp_new[m][s] = -inf;
			}
		}
		for (int s = 0; s < sz; s++) {
			int ss = s;
			for (int j = pi; j < i; j++) {
				ss = au[ss].to[KEK[j] - 'a'];
			}
			for(int m : msks[yet]) {
				if (dp[m][s] == -inf) continue;
				dp_new[m][ss] = max(dp_new[m][ss], dp[m][s]);
			}
		}
		memcpy(dp, dp_new, sizeof(dp));
		for(int m : msks[yet]) {
			for (int b = 0; b < 14; b++) {
				if (m >> b & 1) continue;
				int mm = m | (1 << b);
				for (int s = 0; s < sz; s++) {
					if (dp[m][s] == -inf) continue;
					int ss = au[s].to[b];
					dp[mm][ss] = max(dp[mm][ss], dp[m][s] + au[ss].w);
				}
			}
		}
		yet++;
		pi = i + 1;
		while (pi < n && pi - i < sz && s[pi] != '?') pi++;
		for (int s = 0; s < sz; s++) {
			int ss = s;
			ll add = 0;
			for (int j = i + 1; j < pi; j++) {
				ss = au[ss].to[KEK[j] - 'a'];
				add += au[ss].w;
			}
			for(int m : msks[yet]) {
				if (dp[m][s] == -inf) continue;
				dp_new[m][ss] = max(dp_new[m][ss], dp[m][s] + add);
			}
		}
		memcpy(dp, dp_new, sizeof(dp));
	}
	ll ans = -inf;
	for (int i = 0; i < (1 << 14); i++) {
		if (bpc[i] != sz(qps)) continue;
		for (int j = 0; j < sz; j++) {
			if (ans < dp[i][j]) {
				ans = dp[i][j];
			}
		}
	}
	cout << ans + ans_add;
}