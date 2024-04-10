#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)

namespace SA {
const int MaxN = (int) 2e5 + 9;
int sa[MaxN], lcp[MaxN], rnk[MaxN], n, g[MaxN], b[MaxN], h;

inline bool comp(int i, int j) {
	if (i == j || g[i] != g[j])
		return g[i] < g[j];
	return g[i + h] < g[j + h];
}
void init(const string &t) {
	n = SZ(t);
	REP(i, 0, n)
		sa[i] = i, g[i] = t[i];
	g[n] = -1;
	h = b[0] = b[n] = 0;
	sort(sa, sa + n + 1, comp);
	for (h = 1; b[n] != n; h *= 2) {
		sort(sa, sa + n + 1, comp);
		FOR(i, n)
			b[i + 1] = b[i] + comp(sa[i], sa[i + 1]);
		REP(i, 0, n)
			g[sa[i]] = b[i];
	}
	FOR(i, n)
		sa[i] = sa[i + 1]; // 1-based -> 0-based
	FOR(i, n)
		rnk[sa[i]] = i; // Kasai algorithm for LCP:
	for (int i = 0, k = 0; i < n; i++) {
		if (k > 0)
			k--;
		if (rnk[i] == n - 1) {
			lcp[n - 1] = -1;
			k = 0;
			continue;
		}
		int j = sa[rnk[i] + 1];
		while (t[i + k] == t[j + k])
			k++;

		lcp[rnk[i]] = k;
	}
}
}

int cs[(int) 2e5 + 9];
int dpL[(int) 2e5 + 9];
int dpR[(int) 2e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s, t;
	cin >> n >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	SA::init(s);

	stack<int> stck;

	auto &&lcp = SA::lcp;
	for (int i = 0; i < n - 1; ++i) {
		while (!stck.empty() && lcp[i] <= lcp[stck.top()])
			stck.pop();
		dpL[i] = stck.empty() ? 0 : stck.top() + 1;
		stck.push(i);
	}

	stck = stack<int>();
	for (int i = n - 2; i >= 0; --i) {
		while (!stck.empty() && lcp[i] <= lcp[stck.top()])
			stck.pop();
		dpR[i] = stck.empty() ? n - 2 : stck.top() - 1;
		stck.push(i);
	}

	for (int i = 0; i < n; ++i) {
		cs[i] = (i ? cs[i - 1] : 0) + (t[SA::sa[i]] == '0');
	}

	ll ans = t.end() - find(t.begin(), t.end(), '0');
	for (int i = 0; i < n - 1; ++i) {
		const int l = dpL[i];
		const int r = dpR[i] + 1;
		const ll sum = cs[r] - (l ? cs[l - 1] : 0);
		ans = max(ans, sum * lcp[i]);
	}
	cout << ans;
	return 0;
}