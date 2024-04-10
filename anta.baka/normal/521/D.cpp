#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = (int)1e5 + 100;

struct add {
	int b, t, id;
	bool operator < (const add& h) const {
		return b > h.b;
	}
};

int k, n, m;
int a[N];
pii st[N];
vector<add> ad[N];

struct ev {
	ll p, q;
	int t;
	int id;
	int who;
	ev(ll p, ll q, int t, int id, int who) : p(p), q(q), t(t), id(id), who(who) {}
	bool operator < (const ev& h) const {
		return p * h.q > h.p * q;
	}
};

#define tm keko
vector<ev> tm;
vector<ev> fm[N];
vi ans;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> k >> n >> m;
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		int t, id, b; cin >> t >> id >> b; --id;
		if (t == 1) st[id] = max(st[id], { b, i });
		else if (t == 2) ad[id].pb({ b, 1, i });
		else tm.pb(ev(b - 1, 1, 2, i, id));
	}
	for (int i = 0; i < k; i++) {
		if (st[i].first > a[i]) {
			ad[i].pb({ st[i].first - a[i], 0, st[i].second });
		}
		sort(all(ad[i]));
		ll den = a[i];
		for (auto b : ad[i]) {
			tm.pb(ev(b.b, den, b.t, b.id, i));
			den += b.b;
		}
	}
	sort(all(tm));
	for (int i = 0; i < min(m, sz(tm)); i++) {
		fm[tm[i].who].pb(tm[i]);
	}
	for (int i = 0; i < k; i++) {
		vector<bool> ban(sz(fm[i]), false);
		for (int j = 0; j < sz(fm[i]); j++) if (fm[i][j].t == 0) ans.pb(fm[i][j].id), ban[j] = true;
		for (int j = 0; j < sz(fm[i]); j++) if (!ban[j] && fm[i][j].t == 1) ans.pb(fm[i][j].id), ban[j] = true;
		for (int j = 0; j < sz(fm[i]); j++) if (!ban[j]) ans.pb(fm[i][j].id);
	}
	cout << sz(ans) << '\n';
	for (int x : ans) cout << x + 1 << ' ';
}