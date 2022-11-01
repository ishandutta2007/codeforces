#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	ll ans = 0;
	int suf = 0;
	vector<pair<int, int>> st;
	ll sum = 0;
	auto relax = [&](int e) {
		int cnt = 0;
		while (!st.empty() && st.back().first <= e) {
			cnt += st.back().second;
			sum -= 1LL * st.back().first * st.back().second;
			st.pop_back();
		}
		if (cnt) {
			st.emplace_back(e, cnt);
			sum += 1LL * e * cnt;
		}
	};
	auto add = [&](int e) {
		if (!st.empty() && e == st.back().first) {
			st.back().second++;
		}
		else {
			st.emplace_back(e, 1);
		}
		sum += e;
	};
	for (char c : s) {
		if (c == '0') {
			for (int x = suf; x > 0; x--) {
				add(x);
			}
			suf = 0;
			add(0);
		}
		else {
			suf++;
		}
		relax(suf);
		ans += sum + 1LL * suf * (suf + 1) / 2;
	}
	cout << ans << endl;
}