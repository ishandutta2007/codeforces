/*input
8
7 6 5 4 3 2 2 3

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

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> vec(n);
	FOR(i, 0, n - 1) cin >> vec[i];
	sort(ALL(vec));

	int cnt = 0;
	vector<bool> used(n, 0);
	FOR(i, 0, n - 1) if (!used[i]) {
		++cnt;
		FOR(j, i, n - 1) if (vec[j] % vec[i] == 0) used[j] = 1;
	}
	cout << cnt << endl;

	return 0;
}