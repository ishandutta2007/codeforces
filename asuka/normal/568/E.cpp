#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 100015;
template<class T>
void cmax(T &a, T b) {if (a < b) a = b;}
pii operator + (pii a, int b) {return mp(a.fi + b, a.se);}
int n, m, a[N], b[N], pre[N], up[N], res[N];
pii f[N], g[N << 1];

bool used[N];
void getpath(int x) {
	used[x] = 1;
	if (x) getpath(f[x].se);
}

pii D[N << 1];
int V;
void upd(int p, pii v) {for ( ; p <= V; p += lowbit(p)) D[p] = max(D[p], v);}
pii ask(int p) {pii res = mp(-1, -1); for (; p; p -= lowbit(p)) res = max(res, D[p]); return res;}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	a[n + 1] = 1e9 + 1;
	rep(i, 1, n + 1) pre[i] = pre[i - 1] + (a[i] == -1);
	scanf("%d", &m);
	rep(i, 1, m) scanf("%d", &b[i]);
	sort(b + 1, b + m + 1);
	int mm = unique(b + 1, b + m + 1) - b - 1;
	// rep(i, 1, m) printf("%d ", b[i]); printf("\n");
	vector<int> num;
	rep(i, 0, n + 1) if (~a[i]) num.pb(a[i]);
	rep(i, 1, mm) num.pb(b[i]);
	sort(all(num)); num.erase(unique(all(num)), num.end());
	V = SZ(num);
	rep(i, 0, n + 1) if (~a[i]) a[i] = lower_bound(all(num), a[i]) - num.begin() + 1;
	rep(i, 1, m) b[i] = lower_bound(all(num), b[i]) - num.begin() + 1;
	rep(i, 0, n + 1) up[i] = upper_bound(b + 1, b + mm + 1, a[i]) - b;
	rep(i, 0, n + 1) {
		if (a[i] == -1) continue;
		if (i == 0 || a[i - 1] == -1) {
			rep(j, 0, i - 1) {
				if (a[j] == -1) continue;
				int c = pre[i] - pre[j];
				if (c == 0 || up[j] + c - 1 > mm) continue;
				cmax(g[b[up[j] + c - 1]], mp(f[j].fi + c, j));
			}
			rep(i, 1, V) cmax(g[i], g[i - 1]);
		}
		f[i] = max(ask(a[i] - 1), g[a[i] - 1]); f[i].fi++;
		upd(a[i], mp(f[i].fi, i));
		// fprintf(stderr, "%d %d\n", f[i].fi, f[i].se);
	}
	// fprintf(stderr, "ok\n");
	getpath(n + 1);
	int pl = 1;
	rep(i, 0, n + 1) if (used[i]) res[i] = a[i];
	rep(i, 1, n) {
		if (a[i] == -1) {
			int bef = 0, aft = 0;
			per(j, 0, i - 1) {
				if (res[j]) {
					bef = a[j];
					break;
				}
			}
			rep(j, i + 1, n + 1) {
				if (res[j]) {
					aft = a[j];
					break;
				}
			}
			while (pl <= mm && b[pl] <= bef) pl++;
			if (pl <= mm && b[pl] < aft) res[i] = b[pl], b[pl] = -1, pl++;
		}
	}
	pl = 1;
	rep(i, 1, n) {
		if (res[i]) continue;
		while (pl <= m && b[pl] == -1) pl++;
		if (~a[i]) res[i] = a[i];
		else res[i] = b[pl], pl++;
	}
	rep(i, 1, n) printf("%d ", num[res[i] - 1]);
	return 0;
}