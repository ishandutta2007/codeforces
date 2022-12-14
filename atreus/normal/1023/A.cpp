#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int maxm = 2e3 + 100;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int block = 317;

ull base = 31;

int main () {
	ios_base::sync_with_stdio (false);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			idx = i;
		}
	}
	if (idx == -1) {
		if (s == t) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}
	if (t.size() < s.size() - 1)
		return cout << "NO" << endl, 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*')
			break;
		if (s[i] != t[i]) {
			return cout << "NO" << endl, 0;
		}
	}
	int pnt = m - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '*')
			break;
		if (s[i] != t[pnt]) {
			return cout << "NO" << endl, 0;
		}
		pnt --;
	}
	cout << "YES" << endl;
}