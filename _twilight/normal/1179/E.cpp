#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e3 + 5;

#define ll long long
#define pll pair<ll, ll>

typedef vector<int> vec;

vec operator + (vec a, const vec& b) {
	for (auto x : b) {
		a.push_back(x);
	}
	return a;
}

class rnd {
	public:
		
		rnd() {
			srand((unsigned) time (NULL));
		}
		int rand(int l, int r) {
			return ::rand() % (r - l) + l;
		}
} rnd;

int n;
ll L, m;
pll ans[N];

ll query(int idx, ll x) {
	ll rt;
	printf("? %d %lld\n", idx, x);
	fflush(stdout);
	scanf("%lld", &rt);
	return rt;
}

ll _f(int idx, ll y, ll l = 0, ll r = 1e18) {
	ll mid, qy;
	while (true) {
		mid = (l + r) >> 1;
		qy = query(idx, mid);
		if (qy < y) {
			l = mid + 1;
		} else if (qy > y) {
			r = mid - 1;
		} else {
			return mid;
		}
	}
	assert(false);
	return -1;
}

pair<vec, vec> kth_element(vec a, int k, ll v, ll xl, ll xr, ll& xresult) {
	int p = a[rnd.rand(0, a.size())];
	ll xp = _f(p, v, xl, xr);
	xresult = xp;
	vec vL, vM, vR;
	for (auto idx : a) {
		if (idx == p) {
			vM.push_back(idx);
		} else {
			ll y = query(idx, xp);
			if (y < v) {
				vR.push_back(idx);
			} else if (y > v) {
				vL.push_back(idx);
			} else {
				vM.push_back(idx);
			}
		}
	}
	while ((signed) vL.size() < k && !vM.empty()) {
		vL.push_back(vM.back());
		vM.pop_back();
	}
	while (!vM.empty()) {
		vR.push_back(vM.back());
		vM.pop_back();
	}
	if ((signed) vL.size() == k) {
		return make_pair(vL, vR);
	}
	if ((signed) vL.size() < k) {
		pair<vec, vec> par = kth_element(vR, k - vL.size(), v, xp, xr, xresult);
		return make_pair(vL + par.first, par.second);
	}
	pair<vec, vec> par = kth_element(vL, k, v, xl, xp, xresult);
	return make_pair(par.first, vR + par.second);
}

void dividing(vec a, int l, ll xl, ll xr) {
	if ((signed) a.size() == 1) {
		ans[a.back()] = make_pair(xl, xr);
		return;
	}
	int hn = ((signed) a.size()) >> 1;
	ll xm;
	pair<vec, vec> par = kth_element(a, hn, (l + hn) * m, xl, xr, xm);
	dividing(par.first, l, xl, xm);
	dividing(par.second, l + hn, xm, xr);
}

int main() {
	scanf("%d%lld", &n, &L);
	m = L / n;
	vec idx (n);
	for (int i = 0; i < n; i++)
		idx[i] = i + 1;
	dividing(idx, 0, 0, 1e18);
	puts("!");
	for (int i = 1; i <= n; i++) {
		printf("%lld %lld\n", ans[i].first, ans[i].second);
	}
	fflush(stdout);
	return 0;
}