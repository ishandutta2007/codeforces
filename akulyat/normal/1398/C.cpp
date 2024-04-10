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
const ll N = 10 * ml;

ll n, k;
bool viv = false;

void solve() {
    cin >> n;
    string s;
    cin >> s;  
    n = s.size();
    map<ll, ll> cnt;
    ll bal = 0, ans = 0;
    cnt[bal]++;
    for (auto a: s) {
    bal += (a - '0');
    bal--;
    ans += cnt[bal];
    cnt[bal]++;
    }
    cout << ans << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}