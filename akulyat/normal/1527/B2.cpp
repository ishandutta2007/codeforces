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
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	string s;
	cin >> s;
	int A, B;
	A = 0, B = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && s[n - 1 - i] == '1') {
			B++;
			s[i] = '1';
		}
	}
	int cnt = 0;
	for (auto i : s)
		cnt += (i == '0');
	if (B) {
		if (B == 1 && cnt == 1)
			cout << "DRAW\n";
		else
			cout << "ALICE\n";
		return;
	}
	if (cnt) {
		if (n & 1 && s[n / 2] == '0') {
			if (cnt == 1) {
				A += 1;
			} else {
				B += 1;
			}
		} else {
			A += 2;
		}
	}
	if (A > B) {
		cout << "BOB\n";
	}
	if (A < B) {
		cout << "ALICE\n";
	}
	if (A == B) {
		cout << "DRAW\n";
	}
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