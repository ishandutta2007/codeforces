#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <random>

#define endl '\n'
#define rn(n) int n; cin >> n
#define pb push_back
#define mp make_pair
#define fi(n) for(int i = 0; i < n; ++i)
#define fir(l, r) for(int i = l; i <= r; ++i)
#define fj(n) for(int j = 0; j < n; ++j)
#define fjr(l, r) for(int j = l; j <= r; ++j)
#define fv(i, n) for(int i = 0; i < n; ++i)
#define fvr(i, l, r) for(int i = l; i <= r; ++i)
//#define int ll

#pragma warning (disable : 4996)
//#pragma optimize (linker, "STACK:16777216")

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)2e9 + 10;
const int MOD = (int)1e9 + 7;
const int K = 20;

int maxx[2 << K];
int mod[2 << K];

void update(int v) {
	maxx[v] = max(maxx[v * 2], maxx[v * 2 + 1]);
	return;
}

void push(int v) {
	maxx[v * 2] += mod[v];
	maxx[v * 2 + 1] += mod[v];
	mod[v * 2] += mod[v];
	mod[v * 2 + 1] += mod[v];
	mod[v] = 0;
	return;
}

void change(int v, int L, int R, int l, int x) {
	if (L >= l) {
		maxx[v] += x;
		mod[v] += x;
		return;
	}
	if (R <= l)
		return;
	int M = (L + R) / 2;
	push(v);
	change(v * 2, L, M, l, x);
	change(v * 2 + 1, M, R, l, x);
	update(v);
	return;
}

int bins(vii& a, int x) {
	int l = -1, r = (int)a.size();
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (a[m].first > x)
			l = m;
		else
			r = m;
	}
	return r;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	rn(n); rn(m); rn(p);
	vector<pii> a(n), b(m);
	vector<pair<pii, int>> c(p);
	fi(n) cin >> a[i].first >> a[i].second;
	fi(m) cin >> b[i].first >> b[i].second;
	fi(p) cin >> c[i].first.first >> c[i].first.second >> c[i].second;
	sort(b.rbegin(), b.rend());
	sort(c.begin(), c.end());
	sort(a.begin(), a.end());
	vi cb(m + 1, INF);
	fi(m)
		cb[i + 1] = min(cb[i], b[i].second);
	int cur = n;
	for (int i = (1 << K); i < (2 << K); ++i) {
		while (cur && b[cur - 1].first <= (i - (1 << K)))
			--cur;
		maxx[i] = -cb[cur];
	}
	for (int i = (1 << K) - 1; i > 0; --i)
		update(i);
	int ans = -INF;
	int r = 0;
	fi(n) {
		while (r < p && c[r].first.first < a[i].first) {
			change(1, 0, 1 << K, c[r].first.second, c[r].second);
			++r;
		}
		ans = max(ans, maxx[1] - a[i].second);
	}
	cout << ans;

	return 0;
}