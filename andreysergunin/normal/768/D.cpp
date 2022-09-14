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
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const double EPS = 1e-7;

int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> p(q);
	for (int i = 0; i < q; ++i) {
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(all(p));
	int pos = 0;

	vector<double> cur(n + 1), next(n + 1);

	cur[0] = 1;
	
	vector<int> ans(q);

	for (int d = 0; ; ++d) {
		next[0] = 0;
		for (int j = 1; j <= n; ++j) {
			next[j] = 0;
			next[j] += cur[j - 1] * (double)(n - j + 1) / (double)(n);
			next[j] += cur[j] * (double)(j) / (double)(n);
		}
		double r = next[n];
		for (; pos < q && r > ((double)p[pos].first - EPS) / (double)2000; ++pos) {
			ans[p[pos].second] = d + 1;
		}
		cur.swap(next);
		if (pos == q)
			break;
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << endl;
	}
}