
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



struct uf {
	vector<long long> rt, sz;

	uf(long long n) {
		rt.resize(n);
		sz.resize(n);
		for (long long i = 0; i < n; i++) {
			rt[i] = i;
			sz[i] = 1;
		}
	}

	long long id(long long x) {
		if (rt[x] == x) return x;
		return rt[x] = id(rt[x]);
	}

	bool join(long long x, long long y) {
		x = id(x);
		y = id(y);
		if (x == y) return false;
		rt[x] = rt[y];
		sz[y] += sz[x];
		sz[x] = 0;
		return true;
	}
};





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, m;
	cin >> m >> n;
	uf uf(n + m);

	vector<long long> a;
	for (long long i = 0; i < m; i++) {
		long long x;
		cin >> x;
		a.push_back(x);
	}

	vector<long long> b;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		b.push_back(x);
	}

	vector<pair<long long, pair<long long, long long> > > v;

	for (long long i = 0; i < m; i++) {
		long long s;
		cin >> s;
		for (long long j = 0; j < s; j++) {
			long long x;
			cin >> x;
			v.push_back({ a[i] + b[x - 1] , {i, x - 1} });
		}
	}


	sort(v.rbegin(), v.rend());
	long long ans = 0;
	for (auto p : v) {
		if (!uf.join(p.second.first, p.second.second + m)) {
			ans += p.first;
		}
	}

	cout << ans << endl;




}