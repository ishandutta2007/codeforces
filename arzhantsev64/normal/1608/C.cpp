#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

struct PL {
	int num, a, b;
};

bool cmpa(PL a, PL b) {
	return a.a > b.a;
}

bool cmpb(PL a, PL b) {
	return a.b > b.b;
}

void solve() {
	int n;
	cin >> n;
	vector<PL> v(n);
	vector<bool> can_win(n);

	for (int i = 0; i < n; ++i) {
		v[i].num = i;
		cin >> v[i].a;
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i].b;
	}

	vector<PL> va = v;
	sort(va.begin(), va.end(), cmpa);

	vector<PL> vb = v;
	sort(vb.begin(), vb.end(), cmpb);

	int ia = 0;
	int ib = 0;

	int min_a = min(va[ia].a, vb[ib].a);
	int min_b = min(va[ia].b, vb[ib].b);

	can_win[va[ia].num] = 1;
	can_win[va[ib].num] = 1;

	while (ia != n || ib != n) {
		bool flag = false;

		if (ia != n && va[ia].a >= min_a) {
			can_win[va[ia].num] = 1;
			min_a = min(min_a, va[ia].a);
			min_b = min(min_b, va[ia].b);
			ia++;
			flag = true;
		}

		if (ib != n && vb[ib].b >= min_b) {
			can_win[vb[ib].num] = 1;
			min_a = min(min_a, vb[ib].a);
			min_b = min(min_b, vb[ib].b);
			ib++;
			flag = true;
		}

		if (!flag)
			break;
	}
	for (int i : can_win)
		cout << i;
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    	solve();

	return 0;
}