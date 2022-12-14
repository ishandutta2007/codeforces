#include <iostream>
#include <algorithm>
#include <map>
#define S second
#define F first
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
int n, q, a[maxn], b[maxn];
pair <ll, ll> seg[4 * maxn];

pair <ll, ll> gett (int id, int l, int r, int idx){
//	cout << l << " " << r << " " << seg[id].F << " " << seg[id].S << endl;
	if (l + 1 == r)
		return seg[id];
	int mid = (l + r) / 2;
	if (mid > idx)
		return max (gett (2 * id + 0, l, mid, idx), seg[id]);
	else
		return max (gett (2 * id + 1, mid, r, idx), seg[id]);
		
}

void change (int id, int l, int r, int L, int R, int m, int t){
	if (l == L and r == R){
		seg[id] = MP(t, m);
		return;
	}
	int mid = (l + r) / 2;
	if (mid > L)
		change (id * 2 + 0, l, mid, L, min (mid, R), m, t);
	if (mid < R)
		change (id * 2 + 1, mid, r, max (mid, L), R, m, t);
}

void build (int id, int l, int r){
	if (l + 1 == r){
		seg[id] = MP(1, b[l]);
		return;
	}
	int mid = (l + r) / 2;
	build (2 * id + 0, l, mid);
	build (2 * id + 1, mid, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	build (1, 1, n + 1);

	for (int i = 2; i <= q + 1; i++){
		int tp;
		cin >> tp;
		if (tp == 1){
			int x, y, k;
			cin >> x >> y >> k;
			change (1, 1, n + 1, y, y + k, y - x, i);
		}
		else {
			int idx;
			cin >> idx;
			 if ((gett (1, 1, n + 1, idx)).F == 1)
				 cout << b[idx] << endl;
			 else
				 cout << a[idx - (gett (1, 1, n + 1, idx)).S] << endl; 
		}
	}
}