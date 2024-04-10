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
const int N = 200015;
int n, a[N], fir[N], las[N];
pii operator & (const pii &a, const pii &b) {
	return mp(max(a.fi, b.fi), min(a.se, b.se));
}
bool empty(pii u) {return u.fi > u.se;}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) las[a[i]] = i;
	per(i, 1, n) fir[a[i]] = i;
	vector<pii> vec, stk, nvec;
	rep(i, 1, n) if (fir[i] < las[i]) vec.emplace_back(fir[i], las[i]);
	sort(all(vec), [](pii u, pii v) {
		return u.se < v.se;
	});
	for (auto x : vec) {
		while (SZ(stk) > 0 && (x & stk.back()) == stk.back()) stk.pop_back();
		stk.push_back(x);
	}
	swap(vec, stk);
	for (int l = 0, r; l < SZ(vec); l = r) {
		r = l;
		while (r + 1 < SZ(vec) && !empty(vec[l] & vec[r + 1])) r++;
		nvec.pb(vec[l]);
		if(l == r) r++;
	}
	swap(vec, nvec);
	int ans = 0;
	for (int l = 0, r; l < SZ(vec); l = r + 1) {
		r = l;
		while (r + 1 < SZ(vec) && !empty(vec[r] & vec[r + 1])) r++;
		ans += (vec[r].se - vec[l].fi + 1) - (r - l + 1) - 1;
	}
	printf("%d\n", ans);
	return 0;
}