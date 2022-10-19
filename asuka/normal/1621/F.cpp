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
const int N = 100015;
int n, a, b, c, p[N];
ll calc(int o, VI vec, int _cnt[], int _rem[]) {
	int cnt[2], rem[2];
	rep(p, 0, 1) cnt[p] = _cnt[p], rem[p] = _rem[p];
	ll cur = 0, ans = 0;
	while (1) {
		ans = max(ans, cur);
		if (o == 0) {
			auto Try = [&]() -> int{
				if (SZ(vec) > 0) {
					if (vec.back() > 1) {
						cnt[0]--;
						vec.back()--, cur += a;
						return 1;
					} else {
						vec.pop_back();
						if (b >= c) {
							cnt[1]++;
							cur -= c;
							return 1;
						}
						return 0;
					}
				} else {
					if (cnt[0] > 0) {cnt[0]--; cur += a; return 1;}
					rep(x, 0, 1) {if (rem[x] > 0) {rem[x]--; cur -= c; return 1;}}
					return -1;
				}
			};
			while (1) {
				int x = Try();
				if (x == 1) break;
				if (x == 0) continue;
				return ans;
			}
		} else {
			if (cnt[1] == 0) return ans;
			cnt[1]--;
			cur += b;
		}
		o ^= 1;
	}
	return ans;
}
void solve() {
	scanf("%d%d%d%d", &n, &a, &b, &c);
	rep(i, 1, n) scanf("%1d", &p[i]);
	vector<pii> vec;
	VI v;
	for (int l = 1, r; l <= n; l = r + 1) {
		r = l;
		while (r < n && p[r + 1] == p[l]) r++;
		vec.emplace_back(r - l + 1, p[l]);
	}
	int cnt[2] = {0, 0}, rem[2] = {0, 0}, tot = 0;
	rep(i, 0, SZ(vec) - 1) {
		cnt[vec[i].se] += vec[i].fi - 1;
		if (vec[i].se == 1) continue;
		if (i == 0 || i == SZ(vec) - 1) rem[tot++] = 1;
		else v.emplace_back(vec[i].fi);
	}
	sort(all(v), greater<int>());
	ll ans = 0;
	rep(o, 0, 1) {
		ans = max(ans, calc(o, v, cnt, rem));
	}
	printf("%lld\n", ans);
}
int T;
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}