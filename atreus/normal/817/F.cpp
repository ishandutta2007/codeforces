#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
	long long sum;
	int lazy;
	node *lc, *rc;
	
	node() {
		sum = 0;
		lazy = 0;
		lc = rc = nullptr;
	}

	node *glc() {
		if (!lc)
			lc = new node();
		return lc;
	}
	node *grc() {
		if (!rc)
			rc = new node();
		return rc;
	}

	ll get(ll L, ll R) {
		if (L + 1 == R)
			return L;
		this->shift(L, R);
		ll mid = (L + R) >> 1;
		if (glc()->sum != mid - L)
			return glc()->get(L, mid);
		return grc()->get(mid, R);
	}
	
	void change(ll L, ll R, ll st, ll en, int q) { 
		if (en <= L or R <= st)
			return;
		if (st <= L and R <= en) {
			if (q == 1)
				sum = R - L, lazy = 1;
			else if (q == 2)
				sum = 0, lazy = 2;
			else
				sum = (R - L) - sum, lazy = 3 - lazy;
			return;
		}
		this->shift(L, R);
		ll mid = (L + R) >> 1;
		glc()->change(L, mid, st, en, q);
		grc()->change(mid, R, st, en, q);
		sum = lc->sum + rc->sum;
	}

	void shift(ll L, ll R) {
		if (lazy == 0)
			return;
		ll mid = (L + R) >> 1;
		glc()->change(L, mid, L, mid, lazy);
		grc()->change(mid, R, mid, R, lazy);
		lazy = 0;
	}
};

const int maxn = 1e5 + 10;
ll t[maxn], l[maxn], r[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	node *seg = new node();
	vector<ll> cmp;
	cmp.push_back(1);
	cmp.push_back(1e18 + 1);
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> l[i] >> r[i];
		r[i]++;
		cmp.push_back(l[i]);
		cmp.push_back(r[i]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	int m = cmp.size();
	for (int i = 1; i <= n; i++) {	
		int le = lower_bound(cmp.begin(), cmp.end(), l[i]) - cmp.begin();
		int ri = lower_bound(cmp.begin(), cmp.end(), r[i]) - cmp.begin();
		seg->change(0, m, le, ri, t[i]);
		cout << cmp[seg->get(0, m)] << '\n';
	}
}