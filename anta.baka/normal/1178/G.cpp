#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = 2e5;
const int B = 160;
const int C = (N + B - 1) / B;

int n, q;
vi g[N];
int a[N], b[N];
int in[N], out[N], tik_tak = -1, eu[N];

void dfs(int v) {
	in[v] = ++tik_tak;
	eu[tik_tak] = v;
	for (int to : g[v]) {
		a[to] += a[v];
		b[to] += b[v];
		dfs(to);
	}
	out[v] = tik_tak;
}

struct Line {
	ll k, b;
	int id;
	bool operator < (const Line& l) const {
		return k < l.k;
	}
};

inline ld isec(const Line& u, const Line& v) {
	return ((ld)u.b - v.b) / (v.k - u.k);
}

int s[C];
Line H[C][2 * B];
int s1[C];
Line L[C][2 * B];
ld xs[C][2 * B];
ll x[C];
int pt[C];

void push(int i) {
	while (pt[i] < s[i] - 1 && x[i] >= xs[i][pt[i]]) {
		pt[i]++;
	}
}

void add(int i, const Line& l) {
	if (s[i] > 0) {
		if (l.k == H[i][s[i] - 1].k) {
			if(l.b <= H[i][s[i] - 1].b) {
				return;
			}
			s[i]--;
		}
	}
	while (s[i] > 1 && xs[i][s[i] - 2] >= isec(l, H[i][s[i] - 1])) {
		s[i]--;
	}
	if (s[i]) {
		xs[i][s[i] - 1] = isec(l, H[i][s[i] - 1]);
	}
	H[i][s[i]++] = l;
}

ll eval(int i) {
	return H[i][pt[i]].k * x[i] + H[i][pt[i]].b;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int p; cin >> p; --p; g[p].pb(i + 1);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	dfs(0);
	for (int i = 0; i < (n + B - 1) / B; i++) {
		int l = B * i, r = min(n - 1, B * (i + 1) - 1);
		for (int j = l; j <= r; j++) {
			if (b[j] < 0) {
				b[j] = -b[j];
			}
			int id = eu[j];
			L[i][s1[i]++] = { b[id], 1LL * a[id] * b[id], j };
			L[i][s1[i]++] = { -b[id], -1LL * a[id] * b[id], j };
		}
		sort(L[i], L[i] + s1[i]);
		for (int j = 0; j < s1[i]; j++) {
			add(i, L[i][j]);
		}
		push(i);
	}
	while (q--) {
		int type, v;
		cin >> type >> v;
		--v;
		int l = in[v], r = out[v];
		int LL = l / B, RR = r / B;
		if (type == 1) {
			int d;
			cin >> d;
			for (int p : { LL, RR }) {
				s[p] = pt[p] = 0;
				for (int i = 0; i < s1[p]; i++) {
					Line& u = L[p][i];
					if (l <= u.id && u.id <= r) {
						if (u.k >= 0) {
							u.b += 1LL * d * b[eu[u.id]];
						}
						else {
							u.b -= 1LL * d * b[eu[u.id]];
						}
					}
					add(p, u);
				}
				push(p);
				if (LL == RR) {
					break;
				}
			}
			LL++; RR--;
			for (int i = LL; i <= RR; i++) {
				x[i] += d;
				push(i);
			}
		}
		else {
			ll ans = 0;
			for (int p : { LL, RR }) {
				for (int i = 0; i < s1[p]; i++) {
					const Line& u = L[p][i];
					if (l <= u.id && u.id <= r) {
						ans = max(ans, u.k * x[p] + u.b);
					}
				}
				if (LL == RR) {
					break;
				}
			}
			LL++; RR--;
			for (int i = LL; i <= RR; i++) {
				ans = max(ans, eval(i));
			}
			cout << ans << '\n';
		}
	}
}