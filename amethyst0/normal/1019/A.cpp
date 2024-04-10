#define _CRT_SECURE_NO_WARNINGS
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
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = 3010;
int p[maxn], c[maxn];

vector <pii> v[maxn];
bool used[maxn];

int n, m;

vector <pii> h;

ll go(int cnt) {
	if (cnt == 0) {
		return -1;
	}

	memset(used, 0, sizeof used);
	ll ans = 0;

	int g = cnt - (int)v[1].size();

	for (int i = 2; i <= m; i++) {
		int num = (int)v[i].size() - cnt + 1;
		g -= max(0, num);

		for (int j = 0; j < num; j++) {
			ans += v[i][j].first;
			used[v[i][j].second] = true;
		}
	}

	if (g < 0) {
		return -1;
	}

	for (int i = 0; i < (int)h.size(); i++) {
		if (g == 0) {
			break;
		}

		if (used[h[i].second]) {
			continue;
		}

		g--;
		ans += h[i].first;
	}

	if (g != 0) {
		throw 1;
	}

	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i], &c[i]);
		v[p[i]].push_back(mp(c[i], i));
		if (p[i] != 1) {
			h.push_back(mp(c[i], i));
		}
	}

	sort(h.begin(), h.end());

	for (int i = 1; i <= m; i++) {
		sort(v[i].begin(), v[i].end());
	}

	ll res = (ll)1e18;

	for (int i = (int)v[1].size(); i <= n; i++) {
		ll ans = go(i);

		if (ans != -1) {
			res = min(res, ans);
		}
	}

	cout << res << endl;

	//system("pause");
}