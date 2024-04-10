/*input
4
1 2 3 4

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
#include <stack>

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

const int MAXN = 200007;
int N;
vector<int> vec;
int depL[MAXN], depR[MAXN];

void solve(int dep[MAXN])
{
	stack<pii> st;
	st.emplace(1, 0);
	FOR(i, 1, N - 1) {
		int x = vec[i];

		if (st.top().fi < x) {
			dep[i] = max(dep[i - 1], (int) st.size());
			st.emplace(x, 0);
		} else {
			int curDep = -1;
			while (st.top().fi > x) {
				curDep = max(curDep + 1, st.top().se);
				st.pop();
			}
			++curDep;

			dep[i] = max(dep[i - 1], curDep + (int) st.size());
			st.emplace(x, curDep);
		}
	}
// 	FORA(i, vec) cout << i << ' ' ; cout << endl;
// 	FOR(i, 0, N - 1) cout << dep[i] << ' '; cout << endl << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	vec.resize(N);
	FOR(i, 0, N - 1) cin >> vec[i];
	int rot = find(ALL(vec), 1) - vec.begin();
	rotate(vec.begin(), vec.begin() + rot, vec.end());
	solve(depR);
	reverse(vec.begin() + 1, vec.end());
	solve(depL);

	// cout << rot << endl;

	int minDep = N, bestRot = -1;
	FOR(i, 0, N - 1) {
		if (minDep > max(depL[i], depR[N - 1 - i])) {
			minDep = max(depL[i], depR[N - 1 - i]);
			// cout << i << ": " << minDep << endl;
			bestRot = rot - i;
		}
	}
	if (bestRot < 0) bestRot += N;
	cout << minDep + 1 << ' ' << bestRot << endl;
	return 0;
}