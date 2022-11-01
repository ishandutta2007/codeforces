#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = (int)1e6;
const int inf = (int)1e9 + 100;
const int mod = (int)1e9 + 7;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int n, q; cin >> n >> q; deque<int> a(n); int hi = -1;
	for (int& x : a) cin >> x, hi = max(hi, x);
	int pos = 0; while (a[pos] != hi) pos++;
	vi A(n, -1), B(n, -1);
	int s = 0;
	while(a[0] != hi) {
		int x = a[0], y = a[1];
		a.pop_front(); a.pop_front();
		A[s] = x; B[s] = y;
		if (x > y) { a.push_front(x); a.push_back(y); }
		else { a.push_front(y); a.push_back(x); }
		s++;
	}
	while (q--) {
		ll i; cin >> i; --i;
		if (i < s) cout << A[i] << ' ' << B[i] << '\n';
		else {
			i -= s; i %= (n - 1); cout << hi << ' ' << a[1 + i] << '\n';
		}
	}
}