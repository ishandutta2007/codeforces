#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#define S second
#define F first
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 100;
int seg[4 * maxn], n, a[maxn], lef[maxn], rig[maxn];
set <pair <int, int> > s;

ll get (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) / 2;
	ll ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (mid, l), r);
	return ret;
}

void change (int id, int L, int R, int idx){
	if (L + 1 == R){
		seg[id] ++;
		return;
	}
	seg[id] ++;
	int mid = (L + R) / 2;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx);
	else
		change (2 * id + 1, mid, R, idx);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s.insert (MP(a[i], i));
	}
	int mex = 0, pre = -1;
	while (!s.empty()){
		int u = (*s.begin()).S;
		if (a[u] != pre){
			pre = a[u];
			mex ++;
		}
		a[u] = mex;
		s.erase (s.begin());
	}
	for (int i = 1; i <= n; i++){
		if (a[i] != n)
			lef[i] = get (1, 1, n + 1, a[i] + 1, n + 1);

		change (1, 1, n + 1, a[i]);
	}
	memset (seg, 0, sizeof seg);
	for (int i = n; i >= 1; i--){
		if (a[i] != 1)
			rig[i] = get (1, 1, n + 1, 1, a[i]);

		change (1, 1, n + 1, a[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += 1ll * lef[i] * rig[i];
	cout << ans << endl;
}