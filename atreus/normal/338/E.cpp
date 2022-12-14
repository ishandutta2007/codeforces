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
const int maxn = 2e5 + 100;
const int  mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int base = 31;
int seg[4 * maxn], lazy[4 * maxn], a[maxn], b[maxn], val[maxn], n, len, h;
pair <int, pair <int, int> > p[maxn * 2];

void setlazy (int id, int L, int R){
	int idk = 2 * id + 0, idb = 2 * id + 1;
	seg[idk] += lazy[id];
	seg[idb] += lazy[id];
	lazy[idk] += lazy[id];
	lazy[idb] += lazy[id];
	lazy[id] = 0;
	return;
}

void modifiyer (int id, int L, int R, int l, int r, int x){
	if (L == l and R == r){
		seg[id] += x;
		lazy[id] += x;
		return;
	}
	if (lazy[id] != 0)
		setlazy (id, L, R);

	int mid = (L + R) / 2;
	if (mid > l)
		modifiyer (2 * id + 0, L, mid, l, min (mid, r), x);
	if (mid < r)
		modifiyer (2 * id + 1, mid, R, max (l, mid), r, x);
	seg[id] = min (seg[2 * id + 0], seg[2 * id + 1]);
	return;
}

void build (int id, int L, int R){
	if (L + 1 == R){
		seg[id] = val[L];
		return;
	}
	int mid = (L + R) / 2;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	seg[id] = min (seg[2 * id + 0], seg[2 * id + 1]);
	return;
}

void comp (){
	for (int i = 1; i <= len; i++)
		b[i] = h - b[i];
	sort (b + 1, b + len + 1);
	int tmp = 1;
	for (int i = 1; i <= len; i++)
		p[tmp ++] = MP (b[i], MP (i, 2));
	for (int i = 1; i <= n; i++)
		p[tmp ++] = MP (a[i], MP (i, 1));
	sort (p + 1, p + tmp);
	int ret = 0;
	for (int i = 1; i < tmp; i++){
		ret += (p[i].F > p[i - 1].F);
		if (p[i].S.S == 2)
			b[p[i].S.F] = ret;
		else
			a[p[i].S.F] = ret;
	}
	b[len + 1] = ret + 1;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> len >> h;
	for (int i = 1; i <= len; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	comp();
	for (int i = 1; i <= n; i++)
		val[i] = i - len - 1;
	build (1, 1, maxn);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		int idx = upper_bound (b + 1, b + len + 1, a[i]) - b;
		if (idx > 1)
			modifiyer (1, 1, maxn, 1, idx, 1);
		if (i > len){
			idx = upper_bound (b + 1, b + len + 1, a[i - len]) - b;
			if (idx > 1)
			modifiyer (1, 1, maxn, 1, idx, -1);
		}
		if (seg[1] >= 0){
			cnt ++;
		}
	}
	cout << cnt << endl;
}