#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 1015;
int n, p[N], q[N];
ll L;
pair<ll, ll> ans[N];
mt19937 rnd(114);

ll ask(int i, ll x) {
	ll r;
	cout << "? " << i << ' ' << x << endl;
	cin >> r;
	return r;
}

ll find(int i, ll o, ll l, ll r) {
	ll ans = 0;

	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (ask(i, mid) >= o) ans = mid, r = mid - 1;
		else l = mid + 1;
	}

	return ans;
}

void solve(int l, int r, ll x, ll y) {
	if (l == r) return ans[p[l]] = mp(x, y), void();
	int mid = (l + r) >> 1;
	ll o = L / n * mid;
	int lb = l, rb = r;

	while (1) {
		int u = lb + rnd() % (rb - lb + 1);
		ll v = find(p[u], o, x, y);
		int hd = lb, tl = rb;

		rep(i, lb, rb) if (i != u) {
		    if (ask(p[i], v - 1) >= o) q[hd++] = p[i];
			else if (ask(p[i], v) < o) q[tl--] = p[i];
			else if (rnd() & 1) q[hd++] = p[i];
			else q[tl--] = p[i];
		}

		q[hd] = p[u];
		rep(i, lb, rb) p[i] = q[i];

		if (hd == mid) {
			solve(l, mid, x, v), solve(mid + 1, r, v, y);
			return;
		} else if (hd < mid) {
			lb = hd + 1;
		} else {
			rb = hd - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> L;
	rep(i, 1, n) p[i] = i;
	solve(1, n, 0, 1e18);
	cout << "!\n";
	rep(i, 1, n) cout << ans[i].fi << ' ' << ans[i].se << '\n';
	return 0;
}