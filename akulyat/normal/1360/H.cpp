#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll del, len, lef, more;
vector<string> v;
bool viv = false;

bool check(ll ch) {
	string str;
	auto fch = ch;
	for (int j = 0; j < len; j++)
		str += char('0' + (fch & 1)), fch >>= 1;
	reverse(str.begin(), str.end());
	if (viv)
		cout << "check " << str << endl;
	ll me_more = (1ll << len) - (ch + 1);
	for (auto i : v) {
		if (i == str)
			return false;
		if (i > str)
			me_more--;
	}
	if (viv)
		cout << "\t Get " << me_more << endl;
	if (me_more == more) {
		if (viv)
			cout << "ANS = ";
		cout << str << '\n';
		return true;
	}
	return false;
}

void solve() {
	cin >> del >> len;
	v.resize(del);
	for (auto &str : v)
		cin >> str;
	lef = (1ll << len) - del;
	more = lef / 2;
	if (viv)
		cout << "\t want " << more << '\n';
	for (int j = 0; j < 2 * del + 2; j++) {
		ll int_ch = (1ll << (len - 1)) - j;
		if (int_ch < (1ll << len)) 
			if (int_ch >= 0) {
				if (check(int_ch))
					return;
			}
	}
	for (int j = 0; j < 2 * del + 2; j++) {
		ll int_ch = (1ll << (len - 1)) - 1 + j;
		if (int_ch >= 0) 
			if (int_ch < (1ll << len)) {
				if (check(int_ch))
					return;
			}
	}
	if (viv)
		cout << "Looser" << endl;
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}