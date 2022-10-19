/*input
5
3 4 1 5 2


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
#include <set>

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
int n, a[MAXN], p[MAXN];
set<int> done;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n; FOR(i, 1, n) { cin >> a[i]; p[a[i]] = i; }
	done.insert(0); done.insert(n+1);
	int ans = 0;
	FORB(x, n, 3) {
		int m = p[x], l, r;
		auto it = done.upper_bound(m); r = (*it); --it; l = (*it);
		
		if (m - l < r - m) {
			FOR(i, l + 1, m - 1) {
				int j = p[x - a[i]];
				if (m < j && j < r) ++ ans;
			}
		} else {
			FOR(i, m + 1, r - 1) {
				int j = p[x - a[i]];
				if (l < j && j < m) ++ ans;
			}
		}

		done.insert(m);
	}

	cout << ans << endl;

	return 0;
}