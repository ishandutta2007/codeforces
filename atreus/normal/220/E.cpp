#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
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
const int maxn = 1e5 + 100;
const int  mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int base = 31;
ll n, k, a[maxn], lef[maxn], rig[maxn], seg[4 * maxn];
pair <ll, ll> b[maxn];

ll get (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	ll ret = 0;
	int mid = (L + R) / 2;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l ,mid), r);
	return ret;
}

void change (int id, int L, int R, int idx, int x){
	seg[id] += x;
	if (R - L == 1)
		return;
	int mid = (L + R) / 2;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, x);
	else
		change (2 * id + 1, mid, R, idx, x);
}

ll find_inversion(){
	for (int i = 1; i <= n; i++){
		lef[i] = get (1, 1, maxn, a[i] + 1, maxn);
		change (1, 1, maxn, a[i], 1);
	}

	memset (seg, 0, sizeof seg);
	ll tmp = 0;
	for (int i = n; i >= 1; i--){
		rig[i] = get (1, 1, maxn, 1, a[i]);
		change (1, 1, maxn, a[i], 1);
		tmp += rig[i];
	}
	memset (seg, 0, sizeof seg);
	return tmp;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = MP (a[i], i);
	}
	int cnt = 0;
	sort (b + 1, b + n + 1);
	int ret = 1;
	for (int i = 1; i <= n; i++){
		cnt += (b[i].F > b[i - 1].F);
		a[b[i].S] = cnt;
	}
	ll inv = find_inversion(), myinv = 0, ans = 0;
	int r = 2;
	for (int l = 1; l < n; l++){
		r = max (r, l + 1);
		while (inv - k > myinv and r <= n){
			myinv += lef[r] + rig[r] - get (1, 1, maxn, a[r] + 1, maxn);
			change (1, 1, maxn, a[r], 1);
			r ++;
		}
		if (r <= n)
			ans += n - r + 1;
		if (r > l + 1)
			myinv -= lef[l + 1] + rig[l + 1] - get (1, 1, maxn, 1, a[l + 1]);
		change (1, 1, maxn, a[l + 1], -1);
	}
	cout << ans << endl;
}