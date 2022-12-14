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
ll seg[4 * maxn][15], a[maxn];

ll get (int id, int L, int R, int l, int r, int k){
	if (L == l and R == r)
		return seg[id][k];
	int mid = (L + R) / 2;
	ll ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r), k);
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l, mid), r, k);
	return ret;
}

void change (int id, int L, int R, int idx, ll x, int k){
	seg[id][k] += x;
	if (L + 1 == R)
		return;
	int mid = (L + R) / 2;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, x, k);
	else
		change (2 * id + 1, mid, R, idx, x, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = 0;
	if (k == 0)
		return cout << n << endl, 0;
	for (int i = 1; i <= n; i++){
		for (int j = k + 1; j >= 2; j--){
			ll ret = get (1, 0, M, 0, a[i], j - 1);
			change (1, 0, M, a[i], ret, j);
			if (j == k + 1){
				ans += ret;
			}
		}
		change (1, 0, M, a[i], 1, 1);
	}
	cout << ans << endl;
}