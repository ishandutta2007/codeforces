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
 
ll n;
vector<ll> p;
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


ll phi(ll v) {
	ll res = 1;
	for (auto i : p) {
		ll cnt = 0;
		while (!(v % i)) {
			if (!cnt)
				res *= (i - 1);
			else
				res *= i;
			cnt++;
			v /= i;
		}
	}
	if (v != 1)
		res *= (v - 1);
	return res;
}

void solve() {
	ll a, b;
	cin >> a >> b;
	ll g = __gcd(a, b);
	a /= g;
	b /= g;
	cout << phi(b) << '\n';

}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    p = erat(2e5);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}