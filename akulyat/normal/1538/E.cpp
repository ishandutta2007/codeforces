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

bool viv = false;


struct STR {
	string pref, suf;
	ll cnt = 0;
	STR() {}
	STR(const string &s) {
		build(s);
	}
	void build(string s) {
		pref = suf = s;
		for (int i = 3; i < s.size(); i++)
			cnt += (s.substr(i - 3, 4) == "haha");
		if (viv)
			cout << "CNT " << s << " is " << cnt << endl;
	}
};

STR merge(STR a, STR b) {
	STR c;
	c.pref = a.pref;
	c.suf = b.suf;
	for (auto i : b.pref) {
		if (c.pref.size() <= 10)
			c.pref += i;
	}
	for (int i = (int)a.suf.size() - 1; i >= 0; i--) {
		if (c.suf.size() <= 10)
			c.suf = a.suf[i] + c.suf;
	}
	c.cnt = a.cnt + b.cnt;
	for (int i = 0; i < min((int)b.pref.size(), 3); i++) {
		int lb = i + 1;
		int la = 4 - lb;
		string sl = b.pref.substr(0, lb);
		if (a.suf.size() >= la) {
			sl = a.suf.substr(a.suf.size() - la, la) + sl;
			c.cnt += (sl == "haha");
		}
	}
	if (viv) {
		cout << "A " << a.cnt << ": " << a.pref << " - " << a.suf << endl;
		cout << "B " << b.cnt << ": " << b.pref << " - " << b.suf << endl;
		cout << "C " << c.cnt << ": " << c.pref << " - " << c.suf << endl;
	}
	return c;
}


ll n;
vector<string> v;
map<string, STR> mp;
ll ans;

bool is_make_str(string s) {
	for (auto i : s)
		if (i == ':')
			return true;
	return false;
}

void make_str(string s) {
	string name, res;	
	int tp = 0;
	for (auto i : s) {
		if (i == ':') {
			tp = 1;
		} else {
			if (i != '=' && i != ' ') {
				if (!tp)
					name += i;
				else
					res += i;
			}
		}
	}
	if (viv)
		cout << "make_str: '" << name << "' = '" << res << "'" << endl;
	mp[name] = STR(res);
	ans = mp[name].cnt;
}

void make_concat(string s) {
	string a, b, c;
	int tp = 0;
	for (auto i : s) {
		if (i == '=' || i == '+')
			tp++;
		else {
			if (i != ' ') {
				if (tp == 0)
					a += i;
				if (tp == 1)
					b += i;
				if (tp == 2)
					c += i;
			}
		}
	}	
	if (viv)
		cout << "merge '" << a << "' '" << b << "' '" << c << "'" << endl;
	mp[a] = merge(mp[b], mp[c]);
	ans = mp[a].cnt;
}

void solve() {
	cin >> n; 
	{
		string s;
		getline(cin, s);
	}
	v.resize(n);
	for (auto &s : v) {
		getline(cin, s);
		if (viv)
			cout << s << endl;
	}
	for (auto s : v) {
		if (is_make_str(s)) 
			make_str(s);
		else
			make_concat(s);
	}
	cout << ans << '\n';
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