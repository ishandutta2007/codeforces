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
vector<ll> v, p;
bool viv = false;
ll ch;

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	p.assign(n + 1, 0);
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i];
		if (i & 1)
			p[i + 1] -= v[i];
		else
			p[i + 1] += v[i];
	}
	// for (auto i : p)
	// 	cout << i << ' ';
	// cout << endl;
	ll dif = p.back();
	if (dif & 1) {
		cout << "NO\n";
		return;
	}
 	ch = dif / 2;

 	int pr = 0;
 	while (pr != n + 1 && ((pr & 1) && (p[pr] >= 0) || !(pr & 1) && (p[pr] <= 0)))
 		pr++;
 	int suf = n;
 	while (suf != -1 && ((suf & 1) && (p[suf] - dif >= 0) || !(suf & 1) && (p[suf] - dif <= 0)))
 		suf--;
 	if (pr == n + 1 && dif == 0)
		return void(cout << "YES\n");
 	int r = pr;
 	int l = suf;
 	l = max(l, 1);
 	r = min(r, (int)n - 1);
 	for (int i = l; i <= r; i++) {
 		int pl1 = i - 1;
 		int pl2 = i;
 		if (pl2 & 1) {
 			if (v[pl1] - ch == v[pl2] && p[pl2] - ch >= 0)
 				return void(cout << "YES\n");
 		} else {
 			if (v[pl1] + ch == v[pl2] && p[pl2] - ch <= 0)
 				return void(cout << "YES\n"); 			
 		}
 	}
 	cout << "NO\n";
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