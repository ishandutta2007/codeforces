#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-8;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct fenwick_tree {
	int *t, n;
	fenwick_tree(int n) {
		t = new int[n];
		for (int i = 0; i < n; i++)
			t[i] = 0;
		this->n = n;
	}
	void inc(int pos, int val) {
		for (int i = pos; i < n; i |= (i + 1))
			t[i] += val;

	}
	int sum(int pos) {
		int ans = 0;
		for (int i = pos; i >= 0; i &= (i + 1), i--)
			ans += t[i];

		return ans;
	}
	int sum(int l, int r) {
		if(r < l)
			return 0;
		return sum(r) - sum(l - 1);
	}
};

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n;
	cin >> n;

	int a[n], b[n];
	vector<int> vec;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		vec.push_back(a[i]);
		vec.push_back(b[i]);
	}
	sort(vec.begin(), vec.end());
	map<int, int> m;
	for(int i = 0; i < (int) vec.size(); i++) {
		m[vec[i]] = i;
	}

	vector<iii> v;

	for(int i = 0; i < n; i++) {
		a[i] = m[a[i]];
		b[i] = m[b[i]];
		v.push_back(make_pair(make_pair(a[i], 0), make_pair(b[i], i)));
		v.push_back(make_pair(make_pair(b[i], 1), make_pair(a[i], i)));
	}

	sort(v.begin(), v.end());
	fenwick_tree tree(m.size());

	int ans[n];
	ms(ans);

	for(int i = 0; i < (int) v.size(); i++) {
		if(v[i].first.second == 0) {

		} else {
			ans[v[i].second.second] = tree.sum(v[i].second.first, v[i].first.first - 1);
			tree.inc(v[i].second.first, 1);
		}
	}

	for(int i = 0; i < n; i++)
	cout << ans[i] << endl;
}