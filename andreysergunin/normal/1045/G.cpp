#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)1e5 + 10;

vector <int> p[maxn];
vector <int> t[maxn];

int x[maxn], r[maxn], q[maxn];

int id[maxn];

bool cmp(int a, int b) {
	return r[a] < r[b];
}

void change(int it, int pos) {
	for ( ; pos < (int)t[it].size(); pos |= pos + 1) {
		t[it][pos]++;
	}
}

int getsum(int it, int pos) {
	int ans = 0;

	for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += t[it][pos];
	}

	return ans;
}

int main() {
	int n, k;

	cin >> n >> k;

	vector <int> z;

	for (int i = 0; i < n; i++) {
		id[i] = i;
		scanf("%d %d %d", &x[i], &r[i], &q[i]);

		z.push_back(q[i]);
	}

	sort(z.begin(), z.end());

	z.resize(unique(z.begin(), z.end()) - z.begin());

	for (int i = 0; i < n; i++) {
		int ps = lower_bound(z.begin(), z.end(), q[i]) - z.begin();
		p[ps].push_back(x[i]);
	}

	for (int i = 0; i < (int)z.size(); i++) {
		sort(p[i].begin(), p[i].end());
		t[i].resize(p[i].size());
	}

	sort(id, id + n, cmp);

	ll ans = 0;

	for (int ii = 0; ii < n; ii++) {
		int i = id[ii];

		int ps = lower_bound(z.begin(), z.end(), q[i]) - z.begin();

		for (int j = ps; j < (int)z.size(); j++) {
			if (z[j] - z[ps] > k) {
				break;
			}

			int rm = upper_bound(p[j].begin(), p[j].end(), x[i] + r[i]) - p[j].begin();
			int lm = lower_bound(p[j].begin(), p[j].end(), x[i] - r[i]) - p[j].begin();
			rm--;
			lm--;

			ans += rm - lm - (getsum(j, rm) - getsum(j, lm));
		}

		for (int j = ps - 1; j >= 0; j--) {
			if (z[ps] - z[j] > k) {
				break;
			}

			int rm = upper_bound(p[j].begin(), p[j].end(), x[i] + r[i]) - p[j].begin();
			int lm = lower_bound(p[j].begin(), p[j].end(), x[i] - r[i]) - p[j].begin();
			rm--;
			lm--;

			ans += rm - lm - (getsum(j, rm) - getsum(j, lm));
		}

		int rm = lower_bound(p[ps].begin(), p[ps].end(), x[i]) - p[ps].begin();
		change(ps, rm);
	}

	cout << ans - n << endl;
}