#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <numeric>
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
	int n; string s; cin >> n >> s;
	map<char, int> cnt;
	int hi = 0;
	for (char c : s) hi = max(hi, ++cnt[c]);
	int count = 0;
	for (auto it : cnt) count += (it.second == hi);
	int ans = 1;
	int mod = (int)1e9 + 7;
	for (int i = 0; i < n; i++) ans = 1LL * ans * count % mod;
	cout << ans;
}