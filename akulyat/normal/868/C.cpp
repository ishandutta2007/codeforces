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

ll n, k;
vector<ll> v, cnt;
bool viv = false;

void good() {
	cout << "YES";
	exit(0);
}

bool c(ll a, ll b) {
	return (a & b) == 0;	
}

void solve() {
	cin >> n >> k;
	ll z = (1 << k);
	cnt.resize(z);
	for (int i = 0; i < n; i++) {
		ll res = 0;
		for (int j = 0; j < k; j++) {
			res <<= 1;
			ll a;
			cin >> a;
			res += a;
		}
		cnt[res]++;
	}
	for (int i = 0; i < z; i++)
		for (int j = 0; j < z; j++)
			if (cnt[i] && cnt[j] && c(i, j))
				good();
	cout << "NO";
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}