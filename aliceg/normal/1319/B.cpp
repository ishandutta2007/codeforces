#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <random>

#define endl '\n'
#define rn(n) int n; cin >> n
#define pb push_back
#define mp make_pair
#define fi(n) for(int i = 0; i < n; ++i)
#define fir(l, r) for(int i = l; i <= r; ++i)
#define fj(n) for(int j = 0; j < n; ++j)
#define fjr(l, r) for(int j = l; j <= r; ++j)
#define fv(i, n) for(int i = 0; i < n; ++i)
#define fvr(i, l, r) for(int i = l; i <= r; ++i)
#define int ll

#pragma warning (disable : 4996)
//#pragma optimize (linker, "STACK:16777216")

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	rn(n);
	vi a(n);
	fi(n) cin >> a[i];
	map<int, int> m;
	int ans = 0;
	fi(n) {
		int x = a[i] - i;
		if (m.find(x) == m.end())
			m[x] = 0;
		m[x] += a[i];
	}
	for (auto x : m)
		ans = max(ans, x.second);
	cout << ans;

	return 0;
}