#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, m;
vector<ll> v;
vector<vector<int>> c;

struct tup {
	ll sum, k;
	int ind;
};

void bad(vector<tup> &ord) {
	if (viv)
		cout << "NICE" << endl;
	vector<string> ans(m);
	for (int i = 0; i < m; i++) {
		string s;
		s.resize(c[i].size(), '0');		
		ans[ord[i].ind] = s;	
	}
	for (auto s : ans)
		cout << s;
	cout << '\n';
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v) {
		cin >> i;
	}
	v.push_back(mod);
	sort(v.begin(), v.end());

	vector<tup> ord;
	c.resize(m);
	int cnt = 0;
	for (auto &l : c) {
		ll k, sum = 0;
		cin >> k;
		l.resize(k);
		for (auto &val : l)
			cin >> val, sum += val;

		ord.push_back({sum, k, cnt});
		cnt++;
	}
	sort(ord.begin(), ord.end(), [](tup a, tup b){
		return a.sum * b.k < b.sum * a.k;
	});
	vector<vector<int>> c2(m);
	for (int i = 0; i < m; i++)
		c2[i] = c[ord[i].ind];
	c = c2;

	if (viv) {
		cout << "new c" << endl;
		for (auto l : c) {
			for (auto i : l)
				cout << i << ' ';
			cout << endl;
		}
		for (auto t : ord)
			cout << t.k << ' ' << t.sum << "; ";
		cout << endl;
		cout << "/new c" << endl;
	}

	int pl = 0;
	vector<int> gift;
	vector<bool> used(v.size(), false);
	for (int i = 0; i < m; i++) {
		while (pl < v.size() && v[pl] * ord[i].k < ord[i].sum)
			pl++;
		if (pl == v.size()) {
			bad(ord);
			return;
		}
		gift.push_back(pl);
		used[pl] = true;
		pl++;
	}
	for (int i = (int)gift.size() - 1; i > 0; i--) {
		if (v[gift[i - 1]] * ord[i].k >= ord[i].sum)
			gift[i - 1] = gift[i];
	}

	int best = v.size() - 1;
	while (used[best])
		best--;

	if (viv) {
		cout << "gift = ";
		for (auto i : gift)
			cout << i << ' ';
		cout << endl;
		cout << "best = " << best << endl;
	}


	vector<string> ans(m);
	for (int i = 0; i < m; i++) {
		string s;
		int lbest = gift[i];
		if (max(best, lbest) != n) {
			s.resize(c[i].size(), '0');
		} else {
			if (viv)
				cout << " see " << best << ' ' << lbest << endl;
			lbest = min(lbest, best);
			ll lsum = ord[i].sum;
			ll lk = ord[i].k;
			for (auto value : c[i]) {
				lsum -= value;
				lk--;
				if (viv)
					cout << "\t" << lk << " with " << lsum << endl;
				if (v[lbest] * lk >= lsum)
					s += '1';
				else
					s += '0';
				lk++;
				lsum += value;
			}
		}
		ans[ord[i].ind] = s;
	}

	for (auto s : ans)
		cout << s;
	cout << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}