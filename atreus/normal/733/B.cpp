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
int l[maxn], r[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, L = 0, R = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		L += l[i];
		R += r[i];
	}
	int ans = abs (R - L), cmp = 0;
	for (int i = 1; i <= n; i++) {
		int k = L - l[i] + r[i];
		int m = R - r[i] + l[i];
		if (abs (k - m) > ans) {
			cmp = i;
			ans = abs (k - m);
		}
	}
	cout << cmp << endl;
}