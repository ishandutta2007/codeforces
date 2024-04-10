#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());


const ll INF = 1e18;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int a, b, c;
	int n;
	cin >> a >> b >> c;
	cin >> n;

	vector<ll> p;
	vector<ll> q;

	for (int i = 0; i < n; ++i) {
		string s;
		ll val;
		cin >> val >> s;
		if (s[0] == 'U')
			p.push_back(val);
		else
			q.push_back(val);
	}

	sort(all(p));
	sort(all(q));
	int ans = 0;
	ll cost = 0;

	int x = min(sz(p), a);
	ans += x;
	for (int i = 0; i < x; ++i) {
		cost += p[i];
	}

	int y = min(sz(q), b);
	ans += y;
	for (int i = 0; i < y; ++i) {
		cost += q[i];
	}

	int z = min(c, sz(p) - x + sz(q) - y);
	ans += z;

	vector<ll> prefP(sz(p) - x + 1);
	vector<ll> prefQ(sz(q) - y + 1);
	prefP[0] = 0;
	prefQ[0] = 0;

	for (int i = x; i < sz(p); ++i)
		prefP[i - x + 1] = prefP[i - x] + p[i];

	for (int i = y; i < sz(q); ++i)
		prefQ[i - y + 1] = prefQ[i - y] + q[i];

	ll u = INF;
	for (int i = 0; i <= z; ++i) {
		if (i < sz(prefQ) && z - i < sz(prefP))
			u = min(u, prefQ[i] + prefP[z - i]);
	}

	cost += u;

	cout << ans << " " << cost << endl;

	return 0;
}