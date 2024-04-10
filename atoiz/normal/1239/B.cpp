/*input
12
)(()(()())()

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string str; cin >> str;
	if (count(str.begin(), str.end(), '(') != count(str.begin(), str.end(), ')')) return cout << "0\n1 1", 0;
	vector<int> a(n * 2, 0);
	for (int i = 1; i < n; ++i) a[i] = a[i - 1] + (str[i] == '(' ? 1 : -1);
	
	int tmp_min = *min_element(a.begin(), a.begin() + n);
	for (int i = 0; i < n; ++i) a[i] -= tmp_min;

	copy(a.begin(), a.begin() + n, a.begin() + n);
	vector<int> ids;
	ids.push_back(find(a.begin(), a.begin() + n, 0) - a.begin());
	while (ids.back() != ids.front() + n) {
		ids.push_back(find(a.begin() + ids.back() + 1, a.begin() + ids.front() + n, 0) - a.begin());
	}

	int best_cnt = ids.size() - 1, best_i1 = 0, best_i2 = 0;
	for (int i = 0; i < (int) ids.size() - 1; ++i) {
		int l = ids[i], r = ids[i + 1];

		// 1 -> -1
		int cnt_down = count(a.begin() + l, a.begin() + r, 1);
		if (cnt_down > best_cnt) {
			best_cnt = cnt_down, best_i1 = l + 1, best_i2 = r;
		}

		// 2 -> 0
		for (int p = find(a.begin() + l, a.begin() + r, 2) - a.begin(); p != r;) {
			int q = p, tmp_q;
			while (true) {
				tmp_q = find(a.begin() + q + 1, a.begin() + r, 2) - a.begin();
				if (tmp_q == r) break;
				if (count(a.begin() + q, a.begin() + tmp_q, 1)) break;
				q = tmp_q;
			}
			int cnt = count(a.begin() + p, a.begin() + q + 1, 2) + ids.size() - 1;
			if (cnt > best_cnt) {
				best_cnt = cnt, best_i1 = p, best_i2 = q + 1;
			}
			p = find(a.begin() + q + 1, a.begin() + r, 2) - a.begin();
		}
	}

	cout << best_cnt << '\n' << best_i1 % n + 1 << ' ' << best_i2 % n + 1 << endl;

	return 0;
}