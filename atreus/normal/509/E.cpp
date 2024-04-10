#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
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
const int maxn = 5e5 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int par[maxn];

bool vow (char c) {
	return c == 'A' or c == 'O' or c == 'E' or c == 'I' or c == 'Y' or c == 'U';
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; i++ )
		par[i] = par[i - 1] + vow(s[i]);
	ll sum = 0;
	long double ans = 0;
	for (int i = 0; i <= n; i++ ){
		sum += par[n - i] - par[i];
		ans += 1.0 * sum / (i + 1);
	}
	cout << fixed << setprecision (6) << ans << endl;
}