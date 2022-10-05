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

ll n, m;
vector<int> v, ans;
vector<bool> r;
bool viv = false;

pii ML, MR;
pii bad = {-1, -1};

void work(vector<pii> a) {
	int n = a.size();
	vector<pii> st;
	vector<pii> freed;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (r[a[i].S])
			st.push_back(a[i]);
		else {
			if (st.size()) {
				pii prev = st.back();
				st.pop_back();
				int x1 = prev.F;
				int x2 = a[i].F;
				int t = (x2 - x1) / 2;
				if (viv)
					cout << "head " << "[" << prev.S << ' ' << prev.F << "]" << x1 << ' ' << x2 << endl;
				ans[prev.S] = ans[a[i].S] = t;
			} else {
				freed.push_back(a[i]);
			}
		}
	}
	ML = MR = bad;
	for (int i = 1; i < freed.size(); i += 2) {
		int x1 = freed[i - 1].F;
		int x2 = freed[i].F;
		if (viv)
			cout << "\t\tLLLL " << x1 << ' ' << x2 << endl;;
		int t = x1 + (x2 - x1) / 2;
		ans[freed[i - 1].S] = t;
		ans[freed[i].S] = t;
	}
	reverse(st.begin(), st.end());
	for (int i = 1; i < st.size(); i += 2) {
		int x1 = st[i - 1].F;
		int x2 = st[i].F;
		int t = (m - x1) + abs((m - x2) - (m - x1)) / 2;
		if (viv)
			cout << "\t\tRRRR " << x1 << ' ' << x2 << endl;;
		ans[st[i - 1].S] = t;
		ans[st[i].S] = t;
	}
	if (freed.size() & 1) 
		ML = freed.back();
	if (st.size() & 1) 
		MR = st.back();

	if (ML != bad && MR != bad) {
		int x1 = ML.F;
		int x2 = m - MR.F;
		int t1 = min(x1, x2);
		int t2 = max(x1, x2) - min(x1, x2);		
		int t = t1 + t2 + (m - t2) / 2;
		if ((m - t2) & 1) {
			cout << "BAD\n";
			exit(1);
		}
		ans[ML.S] = t;
		ans[MR.S] = t;
	}
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	for (auto i : v) {
		char c;
		cin >> c;
		r.push_back(c == 'R');
	}
	r.clear();
	if (viv) {
		cout << "r = ";
		for (auto i : r)
			cout << i << ' ';
		cout << endl;
	}
	ans.assign(n, -1);
	vector<pii> a, b;
	for (int i = 0; i < n; i++) {
		if (v[i] & 1)
			a.push_back({v[i], i});
		else
			b.push_back({v[i], i});
	}
	work(a);
	work(b);
	if (viv)
		cout << "ANS = ";
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}