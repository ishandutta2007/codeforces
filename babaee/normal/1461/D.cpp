#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int			    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN], q, ps[MAXN];
set<int> st;

void do_job(int L, int R) {
	if (R < L) return;
	st.insert(ps[R] - ps[L - 1]);
	if (R <= L) return;
	if (A[R] == A[L]) return;
	int mid = (1ll * A[L] + A[R]) / 2ll;
	int t_L = upper_bound(A + L, A + R + 1, mid) - A;
	do_job(L, t_L - 1);
	do_job(t_L, R);
}

int solve() {
	st.clear();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	ps[0] = 0;
	for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + A[i];
	do_job(1, n);
	while (q--) {
		int s;
		cin >> s;
		if (st.find(s) != st.end()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}