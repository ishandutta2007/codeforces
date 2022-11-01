#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		string s;
		cin >> n >> s;
		vi a(n, -1);
		int tmp = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == '>') continue;
			int j = i;
			while (j > 0 && s[j - 1] == '<') {
				j--;
			}
			for (int k = j; k <= i; k++) {
				a[k] = ++tmp;
			}
			i = j;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == -1) {
				a[i] = ++tmp;
			}
		}
		for (int x : a) {
			cout << x << ' ';
		}
		cout << '\n';
		
		a.assign(n, -1);
		tmp = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == '<') {
				a[i] = ++tmp;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == -1) {
				a[i] = ++tmp;
			}
		}
		for (int x : a) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}