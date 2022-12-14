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
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 700;

int redline = 1;

int ans[maxn], l[maxn], r[maxn], a[maxn];

bool cmp (int fi, int se) {
	if (max (l[fi], redline) != max (l[se], redline))
		return max (l[fi], redline) < max (l[se], redline);
	return r[fi] < r[se];
}

int main() {	
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	
	for (int i = 1; i <= n; i++)
		a[i] = i;

	for (int i = 1; i <= n; i++) {
		sort (a + i, a + n + 1, cmp);
		ans[a[i]] = max (l[a[i]], redline);
		redline = max (redline + 1, l[a[i]] + 1);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}