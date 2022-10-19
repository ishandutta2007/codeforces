/*input
3
2 2
1100
4 2
11001101
2 4
11001101

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
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAX = 1000007;
int addon[MAX];
bool colnonempty[MAX];
void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int ans = 0;
	FOR(i, 0, m-1) colnonempty[i] = 0, addon[i] = 0;
	FOR(i, 0, n*m-1) {
		int c = i % m;
		if (s[i] == '1' && !colnonempty[c]) colnonempty[c] = 1, ++ans;
		if (s[i] == '1') {
			int j = i+1;
			while (j < n*m && j < i+m && s[j] == '0') ++j;
			if (j < i+m) ++addon[c], --addon[j % m];
			else ++ans;
		}
		ans += addon[c];
		cout << ans << ' ';
	}
	cout << '\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}