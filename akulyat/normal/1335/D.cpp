#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n;
bool viv = false;
ll v[9][9];

void solve() {
	for (int i = 0; i < 9; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 9; j++)
			v[i][j] = s[j] - '1';
	}

	ll now = 0;
	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j+= 3) {
			v[i + j / 3][j + i  / 3]++;
			v[i + j / 3][j + i  / 3] %= 9;
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << 1 + v[i][j];
		cout << '\n';
	}
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}