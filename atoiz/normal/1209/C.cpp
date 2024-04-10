/*input
5
12
040425524644
1
0
9
123456789
2
98
3
987

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
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

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

string solve()
{
	int n; string str;
	cin >> n >> str;

	string ans(n, '-');
	vector<int> cnt(10, 0);
	FORA(i, str) ++cnt[i - 48];
	int nxt = 0;

	FOR(i, 0, n - 1) {
		while (nxt < 10 && cnt[nxt] == 0) ++nxt;
		if (str[i] == nxt + '0' && ans[i] == '-') {
			ans[i] = '1';
			--cnt[nxt];
		}
	}

	FOR(i, 0, n - 1) {
		while (nxt < 10 && cnt[nxt] == 0) ++nxt;
		if (str[i] == nxt + '0' && ans[i] == '-') {
			ans[i] = '2';
			--cnt[nxt];
		}
	}

	while (nxt < 10 && cnt[nxt] == 0) ++nxt;
	if (nxt < 10) return "-";
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int t; cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}