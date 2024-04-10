#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

vector<Pii> oper;

int seisoku(vector<int>& v) {
	oper.clear();
	int cnt = 0;

	bool used[ten(4)] = {};
	for (int i = 29; i >= 0; i--) {
		int ch = -1;
		FOR(j, sz(v)) if (v[j] & (1 << i)) {
			if (j < cnt) continue;
			ch = j;
			break;
		}
		if (ch == -1) continue;

		if (cnt != ch) {
			swap(v[cnt], v[ch]);
			oper.emplace_back(cnt, ch);
			oper.emplace_back(ch, cnt);
			oper.emplace_back(cnt, ch);
		}

		FOR(j, sz(v)) {
			if (j == cnt) continue;
			if (v[j] & (1 << i)) {
				v[j] ^= v[cnt];
				oper.emplace_back(j, cnt);
			}
		}

		cnt++;
	}

	return cnt;
}

bool check(vector<int> se, vector<int> y) {
	for (auto s : se) {
		int mlb = -1;
		for (int i = 29; i >= 0; i--) if (s & (1 << i)) {
			mlb = i;
			break;
		}
		for (auto &v : y) {
			if (v & (1 << mlb)) {
				v ^= s;
			}
		}
	}
	for (auto v : y) if (v != 0) return false;
	return true;
}

void HHH(vector<int>& x, vector<Pii>& p) {
	FOR(i, sz(p)) {
		auto a = p[i];
		x[a.first] ^= x[a.second];
		printf("x[%d] ^= x[%d]\n", a.first + 1, a.second + 1);
		for (auto d : x) printf("%d ", d);
		puts("");
	}
}

void asssert(vector<int>& x, vector<int>& y, vector<Pii>& ans) {
	HHH(x, ans);
	FOR(i, sz(x)) if (x[i] != y[i]) {
		printf("x[%d](= %d) != y[%d] (= %d)\n",i,x[i],i,y[i]);
		assert(false);
	}
}

int n;

int main() {
	cin >> n;
	vector<int> x(n), y(n);

	FOR(i, n) cin >> x[i];
	FOR(i, n) cin >> y[i];

	vector<int> _x_ = x, _y_ = y;

	int x_secnt = seisoku(x);
	vector<Pii> fst = oper;
	vector<int> xse;
	FOR(i, x_secnt) xse.push_back(x[i]);

	bool b = check(xse, y);
	if (!b) {
		puts("-1");
		return 0;
	}

	int y_secnt = seisoku(y);
	vector<Pii> last = oper;
	reverse(last.begin(), last.end());

	vector<int> yse;
	FOR(i, y_secnt) yse.push_back(y[i]);

	vector<Pii> middle;

	FOR(i,x_secnt){
		int mlb = -1;
		for (int j = 29; j >= 0; j--) if (xse[i] & (1 << j)) {
			mlb = j;
			break;
		}
		bool use = false;
		FOR(j, i + 1) {
			if (j >= y_secnt) break;
			if (yse[j] & (1 << mlb)) use = true;
		}
		if (!use) {
			middle.emplace_back(i, i);
			xse[i] ^= xse[i];
			continue;
		}
		FOR(j, i) {
			if (j >= y_secnt) break;
			if (yse[j] & (1 << mlb)) {
				middle.emplace_back(j, i);
				xse[j] ^= xse[i];
			}
		}
		if (i < y_secnt && (yse[i] & (1 << mlb)) == 0) {
			middle.emplace_back(i, i);
			xse[i] ^= xse[i];
		}
	}
	for (int i = y_secnt; i < x_secnt; i++) {
		middle.emplace_back(i, i);
		xse[i] ^= xse[i];
	}

	vector<Pii> ans;
	for (auto a : fst) ans.push_back(a);
	for (auto a : middle) ans.push_back(a);
	for (auto a : last) ans.push_back(a);

	// asssert(_x_, _y_, ans);

	printf("%d\n",sz(ans));
	for (auto a : ans) printf("%d %d\n",a.first + 1,a.second + 1);

	return 0;
}