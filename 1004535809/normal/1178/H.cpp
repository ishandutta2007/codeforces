#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN = 4400;
const int INF = 0x3f3f3f3f;
const int MAXV = 2e4;
const int MAXE = 2e5;
int n, a[MAXN + 5], b[MAXN + 5];
template<int MAXV, int MAXE> struct MCMF {
	int S, T, hd[MAXV + 5], to[MAXE * 2 + 5], nxt[MAXE * 2 + 5], cap[MAXE * 2 + 5], cst[MAXE * 2 + 5], ec = 1;
	void init() {memset(hd, 0, sizeof(hd)); ec = 1;}
	void adde(int u, int v, int f, int c) {
//		printf("adde %d %d %d %d\n", u, v, f, c);
		to[++ec] = v; cap[ec] = f; cst[ec] = c; nxt[ec] = hd[u]; hd[u] = ec;
		to[++ec] = u; cap[ec] = 0; cst[ec] = -c; nxt[ec] = hd[v]; hd[v] = ec;
	}
	int dis[MAXV + 5], flw[MAXV + 5], pre[MAXV + 5], lste[MAXV + 5];
	bool inq[MAXV + 5];
	bool getdis(int S, int T) {
		memset(dis, 63, (T + 3) << 2); memset(flw, 0, (T + 3) << 2);
		queue<int> q; q.push(S); dis[S] = 0; flw[S] = INF; inq[S] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop(); inq[x] = 0;
			for (int e = hd[x]; e; e = nxt[e]) {
				int y = to[e], z = cap[e], w = cst[e];
				if (z && dis[y] > dis[x] + w) {
					dis[y] = dis[x] + w; flw[y] = min(flw[x], z);
					pre[y] = x; lste[y] = e;
					if (!inq[y]) inq[y] = 1, q.push(y);
				}
			}
		}
		return dis[T] < INF;
	}
	pii mcmf() {
		int mxfl = 0, mncst = 0;
		while (getdis(S, T)) {
			mxfl += flw[T]; mncst += flw[T] * dis[T];
			for (int i = T; i != S; i = pre[i]) {
				cap[lste[i]] -= flw[T]; cap[lste[i] ^ 1] += flw[T];
			}
		}
		return mp(mxfl, mncst);
	}
};
MCMF<MAXV, MAXE> F;
bool check(int T) {
	static int ord[MAXN + 5];
	for (int i = 1; i <= n * 2; i++) ord[i] = i;
	sort(ord + 1, ord + (n << 1) + 1, [&](int x, int y) {return (b[x] == b[y]) ? (a[x] > a[y]) : (b[x] < b[y]);});
	vector<ll> cur, nd;
	for (int i = n + 1; i <= n * 2; i++) nd.pb(1ll * a[i] * T + b[i]);
	sort(nd.begin(), nd.end());
	ll mx = 0;
	for (int i = 1; i <= (n << 1); i++) {
		chkmax(mx, 1ll * a[ord[i]] * T + b[ord[i]]);
		if (ord[i] <= n) cur.pb(mx);
	}
	sort(cur.begin(), cur.end());
	for (int i = 0; i < cur.size(); i++) if (cur[i] < nd[i]) return 0;
	return 1;
}
int work(int T) {
	F.init();
	static pair<ll, int> ord1[MAXN + 5], ord2[MAXN + 5];
	for (int i = 1; i <= n * 2; i++) ord1[i] = mp(b[i], i), ord2[i] = mp(1ll * a[i] * T + b[i], i);
	sort(ord1 + 1, ord1 + n * 2 + 1); sort(ord2 + 1, ord2 + n * 2 + 1);
	static int p1[MAXN + 5], p2[MAXN + 5], p3[MAXN + 5], p4[MAXN + 5], p5[MAXN + 5];
	int ncnt = 0;
	for (int i = 1; i <= n; i++) p1[i] = ++ncnt;
	for (int i = 1; i <= n << 1; i++) p2[i] = ++ncnt;
	for (int i = 1; i <= n << 1; i++) p3[i] = ++ncnt;
	for (int i = 1; i <= n << 1; i++) p4[i] = ++ncnt;
	for (int i = n + 1; i <= n << 1; i++) p5[i] = ++ncnt;
	F.S = ++ncnt; F.T = ++ncnt;
	for (int i = 1; i <= n; i++) F.adde(F.S, p1[i], 1, 0);
	for (int i = n + 1; i <= (n << 1); i++) F.adde(p5[i], F.T, 1, 0);
	for (int i = 1; i + 1 <= (n << 1); i++) {
		F.adde(p2[ord1[i + 1].se], p2[ord1[i].se], INF, 0);
		F.adde(p4[ord2[i + 1].se], p4[ord2[i].se], INF, 0);
	}
	for (int i = 1; i <= n << 1; i++) {
		F.adde(p2[i], p3[i], INF, 0);
		F.adde(p3[i], p4[i], INF, 0);
	}
	for (int i = 1; i <= n; i++) F.adde(p1[i], p3[i], 1, 0);
	for (int i = n + 1; i <= n << 1; i++) F.adde(p3[i], p5[i], 1, 0);
	for (int i = 1; i <= n; i++) {
		int pos = upper_bound(ord1 + 1, ord1 + (n * 2) + 1, mp((ll)b[i] + 1, 0)) - ord1 - 1;
		F.adde(p1[i], p2[ord1[pos].se], 1, 1);
	}
	for (int i = (n + 1); i <= (n << 1); i++) {
		int pos = lower_bound(ord2 + 1, ord2 + (n * 2) + 1, mp(1ll * T * a[i] + b[i], 0)) - ord2;
		F.adde(p4[ord2[pos].se], p5[i], 1, 1);
	}
	pii pp = F.mcmf(); //printf("%d\n", pp.fi);
	assert(pp.fi == n); return pp.se;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n * 2; i++) scanf("%d%d", &a[i], &b[i]);
	int l = 0, r = 1e9, p = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) p = mid, r = mid - 1;
		else l = mid + 1;
	}
	if (p < 0) return puts("-1"), 0;
	printf("%d %d\n", p, work(p));
	return 0;
}