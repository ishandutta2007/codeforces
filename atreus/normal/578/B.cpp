#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 2e5 + 10;
const int mod = 1e9;

ll seg[4 * maxn], a[maxn];

void change(int id, int L, int R, int idx, ll val){
	if (L + 1 == R){
		seg[id] = val;
		return;
	}
	int mid = (L + R) >> 1;
	if (mid > idx)
		change(2 * id + 0, L, mid, idx, val);
	else
		change(2 * id + 1, mid, R, idx, val);
	seg[id] = seg[2 * id + 0] | seg[2 * id + 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, x;
	cin >> n >> k >> x;
	ll y = 1;
	for (int i = 1; i <= k; i++)
		y *= x;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		change(1, 0, n, i, a[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++){
		a[i] *= y;
		change(1, 0, n, i, a[i]);
		ans = max(ans, seg[1]);
		a[i] /= y;
		change(1, 0, n, i, a[i]);
	}
	cout << ans << endl;
}