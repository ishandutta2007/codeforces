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

ll n;
string s, ans;
vector<pll> e;
bool viv = false;

void work(int pos, string &ans) {
	if (viv)
		cout << "stand at " << pos << endl;
	if (!e[pos].F && !e[pos].S)
		return;
	int will = pos - 1;
	int alt = pos + 1;
	if (e[pos].F == 0)
		swap(will, alt);

	if (e[pos].S && e[pos].F == 1)
		swap(will, alt);

	if (will < pos) {
		e[pos].F--;
		e[will].S--;
	} else {
		e[pos].S--;
		e[will].F--;
	}

	if (will > pos)
		ans += '1';
	else
		ans += '0';
	work(will, ans);
}

void solve() {
	cin >> s;
	n = s.size();
	e.assign(2 * n + 1, {0, 0});
	int pos = n;
	for (auto i : s) {
		int will = pos + (i == '1') - (i == '0');
		e[pos].F += (will < pos);
		e[pos].S += (will > pos);
		e[will].F += (pos < will);
		e[will].S += (pos > will);
		pos = will;
	}	
	ans = "";
	work(n, ans);
	if (viv)
		cout << "\tstpd = " << ans << '\n';

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