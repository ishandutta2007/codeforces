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
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
const int M = 1e5 + 10;
int seg[4 * maxn], a[maxn], dp[maxn], ans[maxn];
pair <pair <int, int>, int> p[maxn];

int get (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) / 2;
	int ret = 0;
	if (mid > l)
		ret = max (ret, get (2 * id + 0, L, mid, l, min (mid, r)));
	if (mid < r)
		ret = max (ret, get (2 * id + 1, mid, R, max (l, mid), r));
	return ret;
}

void change (int id, int L, int R, int idx, int val){
	if (L + 1 == R){
		seg[id] = val;
		return;
	}
	int mid = (L + R) / 2;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, val);
	else
		change (2 * id + 1, mid, R, idx, val);
	seg[id] = max (seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i].F.F >> p[i].F.S;
		p[i].F.F += 1e8 + 1;
		p[i].S = i;
	}
	sort (p + 1, p + n + 1);
	for (int i = n; i >= 1; i--){
		int idx = upper_bound (p + 1, p + n + 1, MP (MP (p[i].F.F + p[i].F.S, -1), -1)) - p;
		dp[i] = i;
		dp[i] = max (dp[i], get (1, 0, M, i, idx));
		change (1, 0, M, i, dp[i]);
	}
	for (int i = 1; i <= n; i++)
		ans[p[i].S] = dp[i] - i + 1;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}