#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10;
const ll inf = 2e9;

ll mn[maxn];
ll seg[4 * maxn], lazy[4 * maxn];

void shift(int,int,int);

void add(int id, int L, int R, int l, int r, ll val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	shift(id, L, R);
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
	seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

void shift(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, lazy[id]);
	add(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

ll arr[maxn];

void build(int id, int L, int R){
	if (L + 1 == R){
		seg[id] = -arr[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, p;
	cin >> n >> m >> p;
	memset(mn, 63, sizeof mn);
	int N = 1000001;
	ll minA = inf, minD = inf;
	for (int i = 0; i < n; i++){
		ll a, c;
		cin >> a >> c;
		minA = min(minA, c);
		mn[a] = min(mn[a], c);
	}
	memset(arr, 63, sizeof arr);
	for (int i = 0; i < m; i++){
		ll b, c;
		cin >> b >> c;
		arr[b] = min(arr[b], c);
		minD = min(minD, c);
	}
	build(1, 1, N + 1);
	for (int i = N; i >= 1; i--)
		mn[i] = min(mn[i], mn[i + 1]);
	vector<pair<pair<int,int>, int> > mon(p);
	for (int i = 0; i < p; i++){
		int x, y, z;
		cin >> x >> y >> z;
		mon[i] = {{x, y}, z};
	}
	sort(mon.begin(), mon.end());
	ll answer = - minA - minD;
	for (int i = 0; i < p; i++){
		int x = mon[i].first.first, y = mon[i].first.second, z = mon[i].second;
		add(1, 1, N + 1, y + 1, N + 1, +z);
		ll t = seg[1] - mn[x + 1];
		answer = max(answer, t);
	}
	cout << answer << endl;
}