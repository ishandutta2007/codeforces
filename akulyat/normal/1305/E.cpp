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


bool viv = false;

void work(ll n, ll b) {
	vector<ll> m;
	ll wb = b;
	if (n == 1) {
		if (b == 0) 
			cout << 1 << '\n';
		else
			cout << -1 << '\n';
		return;
	}
	m.push_back(1);
	m.push_back(2);
	ll cnt = 0;
	for (ll i = 2; i < n; i++) {
		ll can = i / 2;
		can = min(can, b);
		b -= can;
		if (can == i / 2) {
			m.push_back(i + 1);
		} else {
			if (can == 0) {
				m.push_back(100 * ml + cnt * (20 * kk));
				cnt++;	
			} else {
				m.push_back(2 * i + 1 - can * 2);				
			}
		}
	}
	if (b != 0) {
		cout << "-1\n";
		return;
	}
	for (auto i : m)
		cout << i << ' ';
	cout << endl;
	if (!viv)
		return;

	ll res = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = i + 1; j < n; j++)
			for (ll u = j + 1; u < n; u++)
				if (m[i] + m[j] == m[u])
					res++;
	if (res != wb) {
		cout << "Bad" << endl;
		cout << n << ' ' << wb << endl;
		exit(0);
	}
}

void solve() {
	ll n, b;
	cin >> n >> b;
	work(n, b);
	if (viv) {
		for (ll i = 1; i < 20; i++)
			for (ll j = 0; j < min(i * i + 3, 200ll); j++)	
				work(i, j);
	}
}

int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}