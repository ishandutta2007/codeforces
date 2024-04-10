#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <random>
#include <bitset>
#include <numeric>
#include <complex>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

//#ifndef LOCALFILE
//#define _getchar_nolock getchar_unlocked
//#define _putchar_nolock putchar_unlocked
//#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld PI = 3.141592653589793;
const ld EPS = 1e-8;
const int N = (int)3e5 + 10;
const int INF = (int)3e5 + 10;
const int MOD = (int)1e9 + 7;

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int t;
	cin >> t;
	for (int j1 = 0; j1 < t; ++j1) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> c(n);
		vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			cnt[a[i] - 1]++;
		}
		for (int i = 0; i < n; ++i) {
			if (i == 0)
				c[a[i] - 1]++;
			if (i == n - 1)
				c[a[i] - 1]++;
			if (i != 0 && a[i - 1] == a[i])
				c[a[i] - 1]++;
			if (i != n - 1 && a[i + 1] == a[i])
				c[a[i] - 1]++;
		}
		sort(cnt.rbegin(), cnt.rend());
		if (cnt[0] > (n + 1) / 2) {
			cout << -1 << endl;
			continue;
		}
		multiset<int> s;
		for (int i : c) {
			if (i)
				s.insert(-i);
		}
		int ans = 0;
		while (s.size() > 1) {
			if (s.size() == 2 && *s.begin() == -1)
				break;
			int x = -*s.begin();
			s.erase(s.begin());
			int y = -*s.begin();
			s.erase(s.begin());
			--x; --y;
			++ans;
			if (x)
				s.insert(-x);
			if (y)
				s.insert(-y);
		}
		if (s.size() == 1)
			ans += -*s.begin() - 2;
		cout << ans << endl;
	}

	return 0;
}