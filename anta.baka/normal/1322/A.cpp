#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <map>
#include <iomanip>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <random>
#include <queue>

#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<ll, ll>;

const int N = 2e5;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int b = 0;
	for (char c : s) {
		b += (c == '(' ? 1 : -1);
	}
	if (b != 0) {
		return cout << -1, 0;
	}
	int ans = 0;
	vi st;
	int cb = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '(') {
			cb++;
			st.pb(i);
		}
		else {
			cb--;
			if (!st.empty() && s[st.back()] == '(') {
				st.pop_back();
			}
			else {
				st.pb(i);
			}
		}
		if (cb == 0 && !st.empty()) {
			ans += i - st[0] + 1;
			st.clear();
		}
	}  
	cout << ans;
}