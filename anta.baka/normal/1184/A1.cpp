#include <iostream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	ll r; cin >> r;
	for (ll x = 1; x * x + x + 1 < r; x++) if ((r - x * x - x - 1) % (2 * x) == 0) return cout << x << ' ' << (r - x * x - x - 1) / (2 * x), 0;
	cout << "NO";
}