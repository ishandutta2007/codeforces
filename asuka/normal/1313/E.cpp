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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 1000015, Mod[] = {1000000007, 1000000009}, base = 114;
int n, m, la[N], lb[N], pd[2][N];
char a[N], b[N], s[N];
void init() {
	rep(p, 0, 1) pd[p][0] = 1;
	rep(i, 1, n << 1) rep(p, 0, 1) pd[p][i] = (ll) pd[p][i - 1] * base % Mod[p];
}
struct Hasher {
	int hs[2][N];
	void geths(char o[]) {
		for(int i = 1; o[i]; ++i) {
			rep(p, 0, 1) hs[p][i] = ((ll) hs[p][i - 1] * base % Mod[p] + o[i]) % Mod[p];
		}
	}
	int query(int p, int l, int r) {
		return (hs[p][r] - (ll) hs[p][l - 1] * pd[p][r - l + 1] % Mod[p] + Mod[p]) % Mod[p];
	}
} X, Y;
namespace BIT {
	ll D1[N], D2[N];
	void clear() {memset(D1, 0, sizeof D1); memset(D2, 0, sizeof D2);}
	void add(int p, int v) {
		int vv = v * p;
		for(; p <= m; p += lowbit(p)) D1[p] += v, D2[p] += vv;
	}
	ll query(ll *D, int p) {
		ll res = 0;
		for(; p; p -= lowbit(p)) res += D[p];
		return res;
	}
	void Add(int l, int r, int v) {
		add(l, v); add(r + 1, -v);
	}
	ll Query(int l, int r) {
		l = max(l, 1);
		return (ll) (r + 1) * query(D1, r) - (ll) l * query(D1, l - 1) - (query(D2, r) - query(D2, l - 1));
	}
}
using namespace BIT;
void prework() {
	init();
	Y.geths(s);
	X.geths(a);
	rep(i, 1, n) {
		int l = i, r = min(n, i + m - 1);
		while(l <= r) {
			int mid = (l + r) >> 1;
			bool flag = 1;
			rep(p, 0, 1) flag &= X.query(p, i, mid) == Y.query(p, 1, mid - i + 1);
			if(flag) la[i] = mid - i + 1, l = mid + 1;
			else r = mid - 1;
		}
	}
	X.geths(b);
	rep(i, 1, n) {
		int l = max(1, i - m + 1), r = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			bool flag = 1;
			rep(p, 0, 1) flag &= X.query(p, mid, i) == Y.query(p, m - i + mid, m);
			if(flag) lb[i] = i - mid + 1, r = mid - 1;
			else l = mid + 1;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%s%s%s", &n, &m, a + 1, b + 1, s + 1);
	prework();
	ll ans = 0;
	rep(i, 1, n) if(la[i] > 0) Add(1, la[i], 1);
	rep(i, 1, n) if(lb[i] > 0) ans += Query(m - lb[i], m - 1);
	clear();
	rep(i, 1, n) {
		if(la[i] > 0) ans -= Query(m - la[i], m - 1);
		if(lb[i] > 0) Add(1, lb[i], 1);
	}
	clear();
	per(i, 1, n - m + 1) {
		if(lb[i + m - 1] > 0) Add(1, lb[i + m - 1], 1);
		if(la[i] > 0) ans -= Query(m - la[i], m - 1);
	}
	printf("%lld\n", ans);
	return 0;
}