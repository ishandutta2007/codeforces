#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

#ifdef LOCAL
const int MAX = 1e4;
#else
const int MAX = 1e5;
#endif

struct segment_tree {
private:
	int n, *t;
	void build(int v, int l, int r) {
		t[v] = INT_MAX;
		if (l == r)
			return;
		int x = (l + r) >> 1;
		build(v * 2, l, x);
		build(v * 2 + 1, x + 1, r);
	}
	int get_min(int v, int tl, int tr, int l, int r) {
		if (l == tl && r == tr)
			return t[v];
		if (tr < l || r < tl)
			return INT_MAX;
		int x = (tl + tr) >> 1;
		return min(get_min(v * 2, tl, x, l, min(x, r)),
				get_min(v * 2 + 1, x + 1, tr, max(x + 1, l), r));
	}
	void update(int v, int tl, int tr, int pos, int val){
		if(tl == tr){
			t[v] = min(t[v], val);
			return;
		}
		int x = (tl + tr) >> 1;
		if(pos <= x)
			update(v * 2, tl, x, pos, val);
		else
			update(v * 2 + 1, x + 1, tr, pos, val);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
public:
	segment_tree(int n){
		t = new int[n * 4];
		this->n = n;
		build(1, 0, n - 1);
	}
	int get_min(int l, int r){
		return get_min(1, 0, n - 1, l, r);
	}
	void update(int pos, int val){
		update(1, 0, n - 1, pos, val);
	}
};

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	ii ar[n];
	for(int i = 0; i < n; i++)
	cin >> ar[i].first >> ar[i].second;

	vector<int> vec[MAX * 2 + 1];
	int t[MAX * 2 + 1];
	ms(t, 0);

	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec[a + MAX].push_back(i);
	}

	sort(ar, ar + n);

	int ans[n], num[n];

	for(int i = 0; i < n; i++) {
		int q = ar[i].second - ar[i].first + MAX;
		if(t[q] == (int) vec[q].size()) {
			cout << "NO";
			return 0;
		}
		num[i] = vec[q][t[q]++];
		ans[num[i]] = i;
	}

	segment_tree tree(MAX + 1);

	for(int i = n - 1; i >= 0; i--){
		if(tree.get_min(ar[i].second, MAX) < num[i]){
			cout << "NO";
			return 0;
		}
		tree.update(ar[i].second, num[i]);
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
	cout << ar[ans[i]].first << " " << ar[ans[i]].second << endl;

}