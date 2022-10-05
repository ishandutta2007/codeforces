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

ll n;
bool viv = false;

vector<long long> erat(long long last)
{
vector<bool> bad;
vector<long long> r;
for (long long i = 0; i < last + 10; i++)
    bad.push_back(true);
for (long long i = 2; i <= last; i++)
    if (bad[i])
        {
        long long j = 2;
        while (j * i <= last)
            {
            bad[j * i] = false;
            j++;
            }
        r.push_back(i);
        }
return r;
}



void solve() {
	vector<vector<ll>> cnt(200 * kk + 10);
	vector<ll> p = erat(1000);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		for (auto d : p) 
			if (a % d == 0) {
				ll val = 0;
				while (a % d == 0)
					a /= d, val++;
				cnt[d].push_back(val);
			}
		if (a != 1)
			cnt[a].push_back(1);
	}

	ll ans = 1;
	for (int i = 2; i < cnt.size(); i++) {
		if (cnt[i].size() >= n - 1) {
			if (cnt[i].size() == n - 1)
				cnt[i].push_back(0);
			sort(cnt[i].begin(), cnt[i].end());
			for (int j = 0; j < cnt[i][1]; j++)
				ans *= i;
		}
	}
	cout << ans << '\n';
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