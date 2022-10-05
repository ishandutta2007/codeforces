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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;
vector<ll> v;
bool viv = false;
vector<int> cnt;

vector<int> fw(int val) {
	vector<int> res;
	for (int i = 0; i < k; i++)
		res.push_back(val + i);
	for (int i = 0; i < k; i++)
		res[i] %= n;
	return res;
}

ll ask(vector<int> a) {
	cout << "? ";
	for (auto i : a) {
		cnt[i] ^= 1;
		cout << i + 1 << ' ';
	}
	cout << endl;
	ll res;
	cin >> res;
	return res;
}

int get_bad() {
	int res = 0;
	for (auto i : cnt)
		res += (i & 1);
	return res;
}

bool tr(bool fin = false) {
	if (viv) {
		cout << "\ttr: ";
		for (auto i : cnt)
			cout << i << ' ';
		cout << endl;
	}
	set<pii> h;
	for (int i = 0; i < n; i++)
		if (cnt[i])
			h.insert({-cnt[i], i});
	vector<vector<int>> asker;
	while (h.size()) {
		if (h.size() < k) {
			return false;
		}
		auto z = h.begin();
		vector<int> lask;
		for (int i = 0; i < k; i++) {
			lask.push_back((*z).S);
			z++;
		}
		asker.push_back(lask);
		for (auto v : lask) {
			h.erase({-cnt[v], v});
			cnt[v]--;
			if (cnt[v])
				h.insert({-cnt[v], v});
		}
		if (viv) {
			cout << "\t\tsee: ";
			for (auto i : cnt)
				cout << i << ' ';
			cout << endl;			
		}
	}
	if (!fin)
		return true;

	ll ans = 0;
	for (auto vec : asker)
		ans ^= ask(vec);
	cout << "! " << ans << endl;
	exit(0);
}

bool pr(int IT) {
	int all = IT / n;
	if (!(all & 1)) {
		all--;
	}
	if (all < 0)
		return false;
	cnt.assign(n, all);
	int dif = IT - all * n;
	if (dif & 1)
		return false;
	return true;	
}

bool can(int IT, bool fin = false) {
	if (viv)
		cout << "can " << IT << endl;
	int all = IT / n;
	if (!(all & 1)) {
		all--;
	}
	if (all < 0)
		return false;
	cnt.assign(n, all);
	int dif = IT - all * n;
	if (dif & 1)
		return false;
	int pl = 0;
	while (dif)
		cnt[pl] += 2, dif -= 2, pl++;

	return tr(fin);
}

void solve() {
	cin >> n >> k;
	cnt.resize(n);
	// if ((n & 1) && !(k & 1)) {
	// 	cout << "-1" << endl;
	// 	return;
	// }

	vector<int> cand;
	for (int i = 1; i <= 510; i++) 
		if (pr(i * k))
			cand.push_back(i);
	if (cand.empty()) {
		cout << "-1" << endl;
		exit(0);
	}
	int l = -1, r = cand.size();
	while (l + 1 < r) {
		int m = l + r >> 1;
		bool nice = false;
		for (int i = m - 1; i <= m + 1; i++)
			if (0 <= i && i < cand.size())
				if (can(cand[i] * k))
					nice = true;
		if (nice)
			r = m;
		else
			l = m;
	}
	for (int i = l - 10; i < l + 10; i++) {
		if (0 <= i && i < cand.size())
			can(cand[i] * k, true);
	}
	cout << "-1" << endl;
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}