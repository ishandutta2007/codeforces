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
int n;
string s;

string choose(string s, vector<int> pls) {
	vector<string> t;
	for (auto pl : pls) {
		t.push_back(s);
		while (t.back().size() > pl)
			t.back().pop_back();
		auto add = t.back();
		reverse(add.begin(), add.end());
		t.back() = t.back() + add;
	}
	if (viv) {
		for (auto str : t)
			cout << "\tsee " << str << endl;
	}
	for (int i = 0; i < t.size(); i++)
		if (t[i] < t[0])
			swap(t[i], t[0]);
	return t[0];
}

void solve() {
	cin >> n;
	cin >> s;
	string ins = s;
	vector<int> v;

	int pl = 1;
	while (pl < n && s[pl] <= s[pl - 1])
		pl++;
	v.push_back(pl);

	while (s.size() > 1 && s[s.size() - 2] == s[s.size() - 1])
		s.pop_back();
	pl = s.size();
	v.push_back(pl);
	v.push_back(1);

	string t = choose(ins, v);

	cout << t;
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