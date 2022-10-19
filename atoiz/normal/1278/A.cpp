/*input
1
abacababasdfadddddddddd
b

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
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

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

	int tests;
	cin >> tests;
	while (tests--) {
		string a, b;
		cin >> a >> b;
		if (a.size() > b.size()) {
			cout << "NO" << endl;
			continue;
		}

		bool ok = 0;
		vector<int> cnt(300, 0);
		for (char ch : a) ++cnt[ch];
		for (int i = 0; i < (int) a.size(); ++i) --cnt[b[i]];
		if (count(cnt.begin(), cnt.end(), 0) == 300) ok = 1;
		for (int i = 0, j = a.size(); j < b.size(); ++i, ++j) {
			++cnt[b[i]];
			--cnt[b[j]];
			if (count(cnt.begin(), cnt.end(), 0) == 300) ok = 1;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}