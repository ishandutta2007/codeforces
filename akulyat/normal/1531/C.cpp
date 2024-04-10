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
vector<string> v;
bool viv = false;

void printer() {
	reverse(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto s : v)
		cout << s << '\n';
	if (viv)
		cout << "------" << endl;
	else
		exit(0);
}

void solve() {
	cin >> n;
	if (n == 2) {
		cout << "-1\n";
		return;
	}
	int sz = 1;
	while (sz * sz < n)
		sz++;
	v.assign(sz, string(sz, 'o'));
	int del = sz * sz - n;
	if (del & 1) {
		v[sz - 1][sz - 1] = '.';
		del--;
		int pl = sz - 2;
		while (del) {
			v[sz - 1][pl] = v[pl][sz - 1] = '.';
			del -= 2;
			pl--;
		}
		printer();
		return;
	} else {
		if (!del) {
			printer();
			return;
		}
		del -= 4;
		v[sz - 1][sz - 1] = '.';
		v[sz - 1][sz - 2] = '.';
		v[sz - 2][sz - 1] = '.';
		v[sz - 2][sz - 2] = '.';
		if (del == -2) {
			for (int i = 0; i < sz; i++)
				v[i] += '.';
			v.push_back("");
			for (int i = 0; i <= sz; i++)
				v[sz] += '.';
			v[sz][0] = v[0][sz] = 'o';
			printer();
			return;
		}
		int pl = sz - 3;
		while (del) {
			v[sz - 1][pl] = v[pl][sz - 1] = '.';
			del -= 2;
			pl--;
		}
		printer();
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	if (viv)	
		cin >> t;
	while (t--)
		solve();

	return 0;
}