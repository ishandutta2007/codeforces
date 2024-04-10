#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <string>
#include <cassert>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

const int KEK = 1e6;

int pv[KEK];
int n, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//ifstream cin("in.txt");
	memset(pv, -1, sizeof(pv));
	cin >> n >> x;
	int hi = -1;
	int rm = -1;
	set<int> vals;
	int KEKOS = x - 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		--x;
		if (hi > x) {
			pv[x] = max(pv[x], hi);
			rm = max(rm, x);
		}
		hi = max(hi, x);
		auto it = vals.insert(x).first;
		auto nxt = next(it);
		if (nxt != vals.end()) {
			KEKOS = min(KEKOS, *nxt);
		}
	}
	ll ans = 0;
	int max_open = -1;
	for (int i = 0; i <= KEKOS; i++) {
		int cur_bound = max({ i, rm, max_open });
		//cout << i << ' ' << cur_bound << endl;
		ans += (x - cur_bound);
		max_open = max(max_open, pv[i]);
	}
	cout << ans;
}