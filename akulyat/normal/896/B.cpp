#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
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
 
ll n, m, c;
vector<ll> v;
bool viv = false;

void get() {
	ll val;
	cin >> val;
	ll now;
	if (val <= c / 2) {
		now = 0;
		while (now < n - 1 && v[now] <= val)
			now++;
	} else {
		now = n - 1;
		while (now > 0 && v[now] != mod && v[now] >= val)
			now--;
	}

	v[now] = val;
	cout << now + 1 << endl;
}

bool bad() {
	for (ll i = 0; i < n - 1; i++)
		if (v[i] > v[i + 1])
			return true;
	for (auto i : v)
		if (i == mod)
			return true;
	return false;	
}

void solve() {
	cin >> n >> m >> c;
	v.resize(n, mod);
	while (bad() && m) {
		get();
		m--;		
		if (viv) {
			for (auto i : v)
				cout << i << ' ';
			cout << endl;
		}
	}
	if (viv) {
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}

}


int main() {
//	viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}