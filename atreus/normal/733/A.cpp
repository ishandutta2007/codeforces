#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);

bool vow (char c) {
	return (c == 'A' or c == 'O' or c == 'U' or c == 'E' or c == 'Y' or c == 'I');
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	s = " " + s;
	int n = s.size();
	int last = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == n or vow(s[i])) {
			ans = max (ans, i - last);
			last = i;
		}
	}
	cout << ans << endl;
}