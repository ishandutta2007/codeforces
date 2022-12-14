#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

ll a[maxn], ans[maxn];
pair<ll, int> q[maxn];
ll seg[4 * maxn];

void add(int id, int L, int R, int l, int r, ll val){
	if (L == l and R == r){
		seg[id] += val;
		return;
	}
	int mid = (L + R) >> 1;
	if (l < mid)
		add(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		add(2 * id + 1, mid, R, max(l, mid), r, val);
}

ll get(int id, int L, int R, int idx){
	if (L + 1 == R)
		return seg[id];
	int mid = (L + R) >> 1;
	if (idx < mid)
		return seg[id] + get(2 * id + 0, L, mid, idx);
	else
		return seg[id] + get(2 * id + 1, mid, R, idx);
}

int fen[maxn];

void add(int idx){
	idx ++;
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] ++;
}

int get(int idx){
	idx ++;
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		ll l, r;
		cin >> l >> r;
		q[i] = {r - l + 1, i};
	}
	sort(q, q + m);
	add(1, 0, m, 0, m, -a[0]);
	for (int i = 0; i < n - 1; i++){
		ll diff = a[i + 1] - a[i] + 1;
		int lo = -1, hi = m;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (q[mid].first < diff)
				lo = mid;
			else
				hi = mid;
		}
		if (lo != -1){
			add(1, 0, m, 0, hi, +a[i] - a[i + 1]);
			add(lo);
		}
	}
	add(1, 0, m, 0, m, +a[n - 1]);
	add(m - 1);
	for (int i = 0; i < m; i++){
		int idx = q[i].second;
		ll x = get(1, 0, m, i);
		ll cnt = get(m - 1) - get(i - 1);
		ans[idx] = x + cnt * q[i].first;
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << " ";
	cout << endl;
}