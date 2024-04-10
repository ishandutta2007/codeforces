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

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
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

int solve(vector<Pii> a[2],int x) {
	int t = 0;
	bool used[2][2000] = {};
	int ans = 0;
	int hi = x;
	while (true) {
		int selected = -1;
		Pii selected_p(-1, -1);
		FOR(i, sz(a[t])) {
			if (used[t][i]) continue;
			if (hi >= a[t][i].first) {
				if (a[t][i].second > selected_p.second) {
					selected = i;
					selected_p = a[t][i];
				}
			}
		}
		if (selected == -1) return ans;
		hi += selected_p.second;
		used[t][selected] = true;
		t ^= 1;
		ans++;
	}
}

int main() {
	int n, x; cin >> n >> x;
	vector<Pii> a[2]; 
	FOR(i, n) {
		int t, h, m; cin >> t >> h >> m;
		a[t].emplace_back(h, m);
	}

	FOR(i, 2) sort(a[i].begin(), a[i].end(),
		[](const Pii&l, const Pii& r) {
		return l.first < r.first;
	});

	int ans = 0;
	FOR(i, 2) {
		int tmp = solve(a,x);
		ans = max(ans, tmp);
		swap(a[0], a[1]);
	}

	cout << ans << endl;
}