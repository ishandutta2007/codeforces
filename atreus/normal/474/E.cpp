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
ll n, d, a[maxn], b[maxn], up[maxn], down[maxn], minn[maxn], maxx[maxn], seg[4 * maxn], dp[maxn], par[maxn];
vector <ll> v;

ll get (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) / 2;
	ll ret = 0;
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
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v.PB (a[i]);
	}
	sort (v.begin(), v.end());
	auto it = unique (v.begin(), v.end());
	v.resize (distance (v.begin(), it));
	for (int i = 1; i <= n; i++){
		b[i] = lower_bound (v.begin(), v.end(), a[i]) - v.begin() + 1;	
		up[i] = lower_bound (v.begin(), v.end(), a[i] + d) - v.begin() + 1;
		down[i] = upper_bound (v.begin(), v.end(), a[i] - d) - v.begin() + 1;
	}
	int idx = 0;
	for (int i = 1; i <= n; i++){
		int ret = get (1, 0, M, 0, down[i]);
		int cur = get (1, 0, M, up[i], M);
		dp[i] = max (ret, cur) + 1;
		change (1, 0, M, b[i], dp[i]);
		if (cur > ret)
			par[i] = maxx[cur];
		else 
			par[i] = minn[ret];
		if (minn[dp[i]] == 0 or b[i] < b[minn[dp[i]]])
			minn[dp[i]] = i;
		if (maxx[dp[i]] == 0 or b[i] > b[maxx[dp[i]]])
			maxx[dp[i]] = i;
		if (dp[i] > dp[idx])
			idx = i;
	}
	cout << dp[idx] << endl;
	v.clear();
	while (idx != 0){
		v.PB (idx);
		idx = par[idx];
	}
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
}