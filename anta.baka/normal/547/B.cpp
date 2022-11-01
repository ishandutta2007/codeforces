#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int n; cin >> n;
	vi a(n); for (int& x : a) cin >> x;
	vi l(n), r(n);
	vi st; for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
		if (st.empty()) l[i] = -1; else l[i] = st.back();
		st.pb(i);
	}
	st.clear(); for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
		if (st.empty()) r[i] = n; else r[i] = st.back();
		st.pb(i);
	}
	vi ans(n, 0);
	for (int i = 0; i < n; i++) {
		int x = r[i] - l[i] - 1;
		ans[x - 1] = max(ans[x - 1], a[i]);
	}
	for (int i = n - 2; i >= 0; i--) ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}