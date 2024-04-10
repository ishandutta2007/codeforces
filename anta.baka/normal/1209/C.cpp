#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool ok = true;
		for (int i = 1; i < n; i++) {
			ok &= (s[i - 1] <= s[i]);
		}
		if (ok) {
			cout << string(n, '1') << '\n';
			continue;
		}
		bool done = false;
		for (int d = 1; d <= 9; d++) {
			vector<bool> was(n, false);
			char last = char('0' + d - 1);
			string s1;
			for (int i = n - 1; i >= 0; i--) {
				if (s[i] <= last) {
					s1.pb(s[i]);
					last = s[i];
					was[i] = true;
				}
			}
			reverse(all(s1));
			//cout << s1 << endl;
			for (int i = 0; i < n; i++) {
				if (!was[i]) {
					s1.pb(s[i]);
				}
			}
			bool ok = true;
			for (int i = 1; i < n; i++) {
				ok &= (s1[i - 1] <= s1[i]);
			}
			if (ok) {
				done = true;
				for (int i = 0; i < n; i++) {
					cout << 1 + !was[i];
				}
				cout << '\n';
				break;
			}
		}
		if (!done) {
			cout << '-' << '\n';
		}
	}
}