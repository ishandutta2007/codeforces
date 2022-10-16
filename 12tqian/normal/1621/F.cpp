#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) { 
	int n;
	long long a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	cin >> s;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = s[i] - '0';
	}
	long long ans = 0;
	for (int t = 0; t < 2; ++t) {
		int one = 0;
		for (int i = 0; i < n - 1; ++i) {
			one += v[i] * v[i + 1];
		}
		int ends_zero = 0;
		int ends = 0;
		int single = 0;
		int i1 = 0, i2 = 0;
		multiset<int> gaps;
		while (i1 != n) {
			while (i2 < n - 1 && s[i1] == s[i2 + 1]) {
				++i2;
			}
			if (v[i1] == 0) {
				if (i1 == 0 || i2 == n - 1) {
					ends_zero += i2 - i1;
					++ends;
				} else {
					if (i2 - i1) {
						gaps.insert(i2 - i1);
					} else {
						++single;
					}
				}
			}
			i1 = ++i2;
		}
		long long cur = 0;
		if (t) {
			if (one == 0) {
				continue;
			}
			--one;
			cur += b;
			ans = max(ans, cur);
		}
		while (true) {
			if (one) {
				if (!gaps.empty()) {
					int gap = *gaps.begin();
					gaps.erase(gaps.begin());
					if (gap - 1) {
						gaps.insert(gap - 1);
					} else {
						++single;
					}
					cur += a;
				} else {
					if (ends_zero) {
						cur += a;
						--ends_zero;
					} else {
						if (single) {
							cur -= c;
							--single;
							++one;
						} else {
							if (ends) {
								cur -= c;
								--ends;
							} else {
								break;
							}
						}
					}
				}
			} else {
				if (!gaps.empty() || ends_zero) {
					ans = max(ans, cur + a);
				}
				if (single) {
					cur -= c;
					--single;
					++one;
				} else {
					break;
				}
			}
			ans = max(ans, cur);
			if (one == 0) {
				break;
			}
			--one;
			cur += b;
			ans = max(ans, cur);
		}
	}
	cout << ans << '\n';
}

/**
 * 0. 00 -> 0, a
 * 1. 11 -> 1, b
 * 2. 0 -> nothing, -c
 * Have to alternate between removing 0's and 1's
 * We do casework on start with 0 or 1
 * Then we always prioritize removing 0's in doubles and 1's in doubles
 * Remove from the minimum length runs always
 * Where you remove the 1's don't matter?
 * We just keep doing as many times as possible and keep track of running maximum?
 * 
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}