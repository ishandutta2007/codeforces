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

ll n, k;
vector<ll> v;
map<int, int> cool;
bool viv = false;

ll LCA(int a, int b) {
	ll res = (ll)a * b / __gcd(a, b);
	return res;
}

void solve() {
	cin >> n >> k;
	v.clear();
	for (int i = 3; i < k; i++)
		v.push_back(1), n--;
	int a = 1;
	for (int i = 3; i < 50; i++) {
		if (n % i == 0 && (LCA(n / i, n / i * (i - 2)) <= n / 2)) {
			cool[n] = n / i * (i - 2);
		}
	}
	if (cool.find(n) == cool.end()) {
		if (n & 1) {}
		else
			a++;
		while ((a < 50 && LCA((n - a) / 2, a) > n / 2))
			a += 2;
		if (LCA((n - a) / 2, a) > n / 2) {
			while (((n - a) / 2) % a && a % ((n - a) / 2)) {
				a += 2;
				if (a > n / 2)
					exit(1);
			}
		}
		cool[n] = a;
	} else
		a = cool[n];

	v.push_back(a);
	v.push_back((n - a) / 2);
	v.push_back((n - a) / 2);
	for (auto i : v)
		cout << i << ' ';
	cout << '\n';
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