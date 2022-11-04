#include <bits/stdc++.h>
#define PLL pair <ll, ll>
#define x first
#define y second
#define M 2010

using namespace std;

typedef long long ll;

const ll Lim = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll tot = 0;

unordered_map <ll, ll> mmp;

ll query(ll w, ll x) {
	if(mmp.count((w << 31) + x)) return mmp[(w << 31) + x];
	ll v;
	if(++tot == 2e5) exit(0);
	printf("? %lld %lld\n", w, x), fflush(stdout);
	scanf("%lld", &v);
	return mmp[(w << 31) + x] = v;
}

ll findx(ll w, ll x, ll L, ll R) {
	for(; L <= R; ) {
		ll md = (L + R) / 2, v = query(w, md);
		if(v == x) return md;
		if(v < x) L = md + 1; else R = md - 1;
	}
}

PLL Ans[M];

ll det;

void Solve(vector <int> V, ll rL, ll rR, ll vL, ll vR) {
	if(vL + 1 == vR) {
		assert(V.size() == 1);
		Ans[V[0]] = PLL(query(V[0], rL) == vL * det ? rL : findx(V[0], vL * det, rL, rR), query(V[0], rR) == vR * det ? rR : findx(V[0], vR * det, rL, rR));
		return;
	}
	ll md = (vL + vR) / 2, lsz = md - vL, rsz = vR - md;
	vector <int> LV(0), RV(0);
	for(; ;) {
		int w = V[rng() % V.size()];
		ll o = findx(w, md * det, rL, rR);
		vector <int> tmpL(0), tmpR(0), tmpmd(0);
		for(int i = 0; i < V.size(); i++) {
			ll tmp = query(V[i], o);
			if(tmp < md * det) tmpR.push_back(V[i]);
			else if(tmp == md * det) tmpmd.push_back(V[i]);
			else tmpL.push_back(V[i]);
		}
		if((int) tmpL.size() + (int) LV.size() > lsz) {
			RV.insert(RV.end(), tmpR.begin(), tmpR.end());
			RV.insert(RV.end(), tmpmd.begin(), tmpmd.end());
			V = tmpL;
		} else if((int) tmpR.size() + (int) RV.size() > rsz) {
			LV.insert(LV.end(), tmpL.begin(), tmpL.end());
			LV.insert(LV.end(), tmpmd.begin(), tmpmd.end());
			V = tmpR;
		} else {
			LV.insert(LV.end(), tmpL.begin(), tmpL.end());
			RV.insert(RV.end(), tmpR.begin(), tmpR.end());
			LV.insert(LV.end(), tmpmd.begin(), tmpmd.begin() + (lsz - LV.size()));
			RV.insert(RV.end(), tmpmd.end() - (rsz - RV.size()), tmpmd.end());
			Solve(LV, rL, o, vL, md);
			Solve(RV, o, rR, md, vR);
			return;
		}
	}
}

int main() {
	ll n, L;
	scanf("%lld%lld", &n, &L), det = L / n;
	vector <int> V(n);
	for(int i = 0; i < n; i++) V[i] = i + 1;
	Solve(V, 0, Lim, 0, n);
	putchar('!');
	putchar('\n');
	for(int i = 1; i <= n; i++) printf("%lld %lld\n", Ans[i].x, Ans[i].y);
	fflush(stdout);
	return 0;
}