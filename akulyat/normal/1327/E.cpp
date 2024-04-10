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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 


ll n;
vector<ll> p;
bool viv = false;


void solve() {
	cin >> n;
	vector<ll> ans;
	p.push_back(1);
	for (int i = 1; i < n + 10; i++) {
		p.push_back(10 * p.back());
		p.back() %= mod;
	}
	for (int i = 1; i < n - 1; i++) {
		ll dif = 0;
		ans.push_back(0);

		{
			dif = 10;
			dif *= 9;
			dif *= 9;
			dif *= p[n - i - 2];
			dif *= (n + 1 - i - 2);
			dif %= mod;
			ans.back() += dif;
		}

		dif = 10;
		dif *= 9;
		dif *= p[n - i - 1];
		dif *= 2;
		dif %= mod;
		ans.back() += dif;

		ans.back() %= mod;
	}
	if (n != 1)
		ans.push_back(180);
	ans.push_back(10);
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}