#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const int MAX = 5e5;
const int IM = 2e9;
const ld E = 1e-9;

int t[MAX * 4];

void build(int v, int l, int r, int *ar) {
	if(l > r)
		return;
	if (l == r) {
		t[v] = ar[l];
		return;
	}
	int x = (l + r) / 2;
	build(v * 2, l, x, ar);
	build(v * 2 + 1, x + 1, r, ar);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void update(int v, int l, int r, int pos, int val) {
	if (l > r)
		return;
	if (l == r) {
		t[v] = val;
		return;
	}
	int x = (l + r) / 2;
	if (pos <= x)
		update(v * 2, l, x, pos, val);
	else
		update(v * 2 + 1, x + 1, r, pos, val);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int getMin(int v, int tl, int tr, int l, int r) {
	if (l > r || tl > tr)
		return IM;
	if (l == tl && r == tr)
		return t[v];
	int x = (tl + tr) / 2;
	return min(getMin(v * 2, tl, x, l, min(x, r)),
			getMin(v * 2 + 1, x + 1, tr, max(x + 1, l), r));
}

int main() {

	sync;

	int n, m;
	cin >> n >> m;

	int ar[n];
	for (int i = 0; i < n; i++)
	cin >> ar[i];

	for(int i = 0; i < MAX * 4; i++)
	t[i] = IM;

	int prev[n], next[n];
	for (int i = 0; i < n; i++)
	prev[i] = next[i] = IM;

	map<int, int> ma;

	for (int i = 0; i < n; i++) {
		int a = ma[ar[i]];
		a--;
		if (a >= 0) {
			prev[i] = i - a;
			next[a] = i;
		}
		ma[ar[i]] = i + 1;
	}

	build(1, 0, n - 1, prev);

	vector<pair<pair<int, int>, int> > v;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		v.push_back(make_pair(make_pair(l, r), i));
	}

	sort(v.begin(), v.end());

	int ans[m];
	ms(ans);

	for (int s = 0, i = 0; i < n; i++) {
		for (int t = s; t < (int) v.size() && v[t].x.x == i; t++) {
			ans[v[t].y] = getMin(1, 0, n - 1, i, v[t].x.y);
			assert(ans[v[t].y] != 0);
			s++;
		}
		if(next[i] < n)
		update(1, 0, n - 1, next[i], IM);
	}

	for (int i = 0; i < m; i++)
	cout << ((ans[i] == IM || ans[i] == 0) ? -1 : ans[i]) << endl;

}