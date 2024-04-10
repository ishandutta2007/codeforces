/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, LOG = 60;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		vector<ll> cnt(LOG, 0);
		for (auto& v : a) {
			for (int b = 0; b < LOG and v; ++b) {
				cnt[b] += v % k;
				v /= k;
			}
		}
		if (*max_element(cnt.begin(), cnt.end()) < 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}