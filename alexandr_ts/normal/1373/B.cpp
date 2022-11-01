#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <cstring>
#include <array>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

int calc(string& s) {
	for (int i = 1; i < (int)s.size(); ++i) {
		if (s[i] != s[i - 1]) {
			string t = s.substr(0, i - 1) + s.substr(i + 1);
			s = t;
			return 1;
		}	
	}
	return 0;
}

void solve() {
	string s;
	cin >> s;
	int cnt = 0;
	while (true) {
		int rez = calc(s);
		if (rez) {
			cnt++;	
		} else {
			break;	
		}
	}
	if (cnt % 2) {
		cout << "DA\n";	
	} else {
		cout << "NET\n";	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();	
	}
}