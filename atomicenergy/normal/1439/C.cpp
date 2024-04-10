using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


ll n;

struct segt {

	struct node {
		ll t, mx, lazyby, lazyto;
		ll length, s, e;
		bool set;
		node* l;
		node* r;
	};

	node* rt;

	void build(ll i, ll j, node* v) {
		v->mx = v->t = v->lazyby = v->lazyto = 0;
		v->length = j - i + 1;
		v->s = i;
		v->e = j;
		if (i == j) return;
		v->l = new node();
		v->r = new node();
		build(i, (i + j) / 2, v->l);
		build((i + j) / 2 + 1, j, v->r);
	}

	segt() {}
	segt(ll n) {
		rt = new node();
		build(0, n - 1, rt);
	}

	inline void prop(node* v) {
		if (v->l != nullptr) {
			if (v->set) {
				v->l->lazyby = v->r->lazyby = 0;
				v->l->lazyto = v->r->lazyto = v->lazyto;
				v->l->set = v->r->set = true;
			}
			v->l->lazyby += v->lazyby;
			v->r->lazyby += v->lazyby;
		}
		if (v->set) {
			v->t = v->lazyto * v->length;
			v->mx = v->lazyto;
		}
		v->t += v->lazyby * v->length;
		v->mx += v->lazyby;
		v->set = v->lazyby = v->lazyto = 0;
	}

	void update(ll i, ll j, ll val, bool by, node* v) {
		if (j < v->s || v->e < i) return;
		if (i <= v->s && v->e <= j) {
			prop(v);
			if (by) v->lazyby += val;
			else {
				v->lazyto = val;
				v->set = true;
			}
			prop(v);
			return;
		}
		prop(v);
		update(i, j, val, by, v->l);
		update(i, j, val, by, v->r);
		prop(v->l);
		prop(v->r);
		v->t = v->l->t + v->r->t;
		v->mx = max(v->l->mx, v->r->mx);

	}

	void updateby(ll i, ll j, ll val) { update(i, j, val, true, rt); }
	void updateto(ll i, ll j, ll val) { update(i, j, val, false, rt); }


	ll query(ll i, ll j, bool m, node* v) {
		if (j < v->s || v->e < i) {
			if (m) return -1000000000;
			return 0;
		}
		prop(v);
		if (i <= v->s && v->e <= j) {
			if (m) return v->mx;
			return v->t;
		}
		ll l = query(i, j, m, v->l);
		ll r = query(i, j, m, v->r);
		prop(v);
		if (m) return max(l, r);
		return l + r;
	}

	ll firstLessThan(node* v, ll mx) {
		prop(v);

		if (v->mx <= mx) return v->s;
		if (v->s - v->e == 0) {
			return v->e + 1;
		}
		prop(v->r);
		prop(v->l);

		if (v->r->mx <= mx) return firstLessThan(v->l, mx);
		else return firstLessThan(v->r, mx);

	}

	pair<ll, ll> lastSumLessThan(node* v, ll start, ll mx) {
		prop(v);

		if (start > v->e) return { v->e + 1, 0 };
		if (start == v->s && v->t <= mx) return { v->e + 1, v->t };
		if (start == v->s && v->s - v->e == 0) {
			return { v->s, 0 };
		}
		prop(v);
		auto p = lastSumLessThan(v->l, start, mx);
		if (p.first < v->l->e + 1) return p;
		auto q = lastSumLessThan(v->r, max((ll)start, v->r->s), mx - p.second);
		return { q.first, q.second + p.second };

	}

	ll queryFirstLessThan(ll val) { return firstLessThan(rt, val); }
	pair<ll, ll> queryLastSumLessThan(ll start, ll val) { return lastSumLessThan(rt, start, val); }

	ll querysum(ll i, ll j) { return query(i, j, false, rt); }
	ll querymax(ll i, ll j) { return query(i, j, true, rt); }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll q;
	cin >> n >> q;
	segt s(n);
	vector<ll> v;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
		s.updateto(i, i, x);
	}
	for (ll w = 0; w < q; w++) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			y--;
			ll i = s.queryFirstLessThan(z);
			if (i <= y) {
				s.updateto(i, y, z);
			}
		}
		else {
			y--;
			ll tot = 0;
			while (z > 0 && y < n) {
				ll i = s.queryFirstLessThan(z);
				if (i > y) y = i;
				if (y >= n) break;
				auto p = s.queryLastSumLessThan(y, z);
				tot += p.first - y;
				y = p.first;
				z -= p.second;
			}
			cout << tot << endl;
		}
	}


}