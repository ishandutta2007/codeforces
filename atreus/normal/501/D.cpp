#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
int n, a[maxn], b[maxn], c[maxn], d[maxn], seg[4 * maxn], g[maxn], ans[maxn];
int get (int id, int L, int R, int l, int r){
	if (r == R and l == L)
		return seg[id];
	int mid = (L + R) / 2;
	ll ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (mid, l), r);
	return ret;
}

void change (int id, int l, int r, int x){
	seg[id] ++;
	if (r - l == 1)
		return;
	int mid = (r + l) / 2;
	if (mid > x)
		change (2 * id + 0, l, mid, x);
	else
		change (2 * id + 1, mid, r, x);
}

void build (){
	for (int i = 0; i < 4 * maxn; i++)
		seg[i] = 0;
}

void cal_per(){
	build();
	for (int i = 0; i < n; i++){
		int l = 0, r = n;
		while (r - l > 1){
			int mid = (r + l) / 2;
			if (mid - get (1, 0, n, 0, mid) <= g[i])
				l = mid;
			else
				r = mid;
		}
		ans[i] = l;
		change (1, 0, n, l);
	}
}

void cal_ord(){
	for (int i = 0; i < n; i++){
		c[i] = a[i] - get (1, 0, n, 0, a[i]);
		change (1, 0, n, a[i]);
	}
	build ();
}

int main (){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cal_ord();
	for (int i = 0; i < n; i++){
		int tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
		d[i] = c[i];
	}
	cal_ord();
	bool bm = 0;
	for (int i = n - 1; i >= 0; i--){
		g[i] = (c[i] + d[i] + bm) % (n - i);
		bm = (c[i] + d[i] + bm) / (n - i) ;
	}
	cal_per();
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}