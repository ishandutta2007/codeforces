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

ll n, m, p;
vector<string> v;
vector<ll> vals;
string ans;
bool viv = false;

int rnd(int n) {
	return uniform_int_distribution<int>(0, n - 1)(rng);
}

int cnt(string &s) {
	int res = 0;
	for (auto i : s)
		res += (i == '1');
	return res;
}
void upd(string s) {
	if (cnt(s) > cnt(ans))
		ans = s;
}

ll value(string s) {
	ll res = 0;
	for (auto v : s) {
		res <<= 1;
		res |= (v - '0');
	}
	return res;
}

/*string str(ll value) {
	string res;
	while (res.size() != ans.size()) {
		res += char('0' + (value & 1));
		value >>= 1;
	}
	reverse(res.begin(), res.end());
	return res;
}
*/
void build() {
	for (auto &s : v)
		vals.push_back(value(s));
}

int get_mask(vector<bool> &need) {
	int res = 0;
	for (auto i : need) {
		res <<= 1;
		res |= i;
	}
	return res;
}

string get_str(string &s, vector<bool> need) {
	string res;
	int nxt = 0;
	for (auto i : s) {
		if (i == '0')
			res += '0';
		else {
			if (need[nxt++])
				res += '1';
			else
				res += '0';
		}
	}
	return res;
}

vector<bool> get_need(int mask, int ones) {
	vector<bool> need;
	for (int i = 0; i < ones; i++) {
		need.push_back((mask >> i) & 1);
	}
	reverse(need.begin(), need.end());	
	return need;
}

vector<int> get_spmasks(int val, int ones) {
	int fl = (1 << ones) - 1;
	val = val ^ fl;
	vector<int> res(1, val);
	int fk = val;
	while (fk != 0) {
		fk = val & (fk - 1);
		res.push_back(fk);
	}
	for (auto &i : res)
		i = i ^ fl;
	return res;
}

int gmask(string s, string ss) {
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			res <<= 1;
			if (ss[i] == '1')
				res++;
		}
	}
	return res;
}

void work(int ind) {
	string s = v[ind];
	ll val = vals[ind];
	int ones = cnt(s);
	if (viv) {
		cout << "work(" << ind << ")" << endl;
		cout << "\ts = " << s << endl;
		cout << "\tval = " << val << endl;
		cout << "\tones = " << ones << endl;
	}
	vector<int> cnt(1 << ones, 0);
	for (auto ss : v) {
		int mask = gmask(s, ss);
		cnt[mask]++;
	}

	vector<pii> masks;
	for (int mask = 0; mask < (1 << ones); mask++) {
		vector<bool> need = get_need(mask, ones);
		int sz = 0;
		for (auto i : need)
			sz += i;
		masks.push_back({sz, mask});
	}
	sort(masks.rbegin(), masks.rend());
	vector<int> lans(1 << ones, 0);
	ll sum = 0;
	for (auto pr : masks) {
		int sz = pr.F;
		int mask = pr.S;
		vector<bool> need = get_need(mask, ones);
		assert(need.size() == ones);
		assert(sz <= ones);
		vector<int> spmasks = get_spmasks(mask, ones);
		for (auto smask : spmasks) {
			sum++;
			if ((smask & mask) != mask) {
				cout << smask << ' ' << mask << endl;
				exit(0);
			}
			if (smask >= cnt.size()) {
				cout << "smask = " << smask << endl;
				exit(0);
			}
 			lans[mask] += cnt[smask];
		}
		if (viv && lans[mask] > 1)
			cout << "lans[" << mask << "] = " << lans[mask] << endl;
		if (lans[mask] * 2 >= n) {
			// cout << "\tNICE: " << get_str(s, need) << endl;			
			upd(get_str(s, need));
		}
	}
	// cout << "see: " << sum << endl;
}


void solve() {
	cin >> n >> m >> p;
	v.resize(n);
	for (auto &s : v)
		cin >> s;
	ans.resize(m, '0');
	build();

	vector<int> g;
	for (int i = 0; i < n; i++)
		g.push_back(i);
	shuffle(g.begin(), g.end(), rng);
	while (g.size() > 15)
		g.pop_back();
	for (auto ind : g) {
		work(ind);
	}
	cout << ans << '\n';
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