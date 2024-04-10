#include <bits/stdc++.h>
 
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
 
 
ll n, t, a, b;
vector<vector<ll>> m;
vector<ll> all, pr;
bool viv = false;

long long obr(long long v)
{
long long i = 0;
long long st = mod - 2;
vector<long long> bin;
long long l = 0;
while(st > 0)
    {
    bin.push_back(st & 1);
    st /= 2;
    l++;
    }

vector<long long> sq;
sq.push_back(v);
for (i = 1; i < l; i++)
    {
    long long s = sq.back();
    s *= s;
    s %= mod;
    sq.push_back(s);
    }

long long ans = 1;
for (i = 0; i < l; i++)
    if (bin[i])
        {
        ans *= sq[i];
        ans %= mod;
        }
return ans;
}


void count() {
	pr.resize(all.size());
	ll oo = obr(m.size());
	for (ll i = 0; i < n; i++) {
		ll o = obr(m[i].size());
		o *= oo;
		o %= mod;
		for (auto j : m[i]) {
			pr[j] += o;
			if (pr[j] >= mod)
				pr[j] -= mod;
		}
	}
}

void solve() {
	cin >> n;
	m.resize(n);
	all.resize(ml + 10);
	for (ll i = 0; i < n; i++) {
		ll k;
		cin >> k;
		for (ll j = 0; j < k; j++) {
			ll a;
			cin >> a;
			a--;
			m[i].push_back(a);
			all[a]++;
		}
	}
	count();
	ll ans = 0;
	// for (ll i = 0; i < n; i++)
	// 	cout << pr[i] * 4 << ' ';
	// cout << endl;
	// for (ll i = 0; i < n; i++)
	// 	cout << all[i] << ' ';
	// cout << endl;
	ll on = obr(n);
	for (ll i = 0; i < all.size(); i++) 
		if (all[i]) {
			ans += ((pr[i] * all[i]) % mod) * on;
			ans %= mod;
		}
	ans %= mod;
	cout << ans << endl;
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while (t--)
    	solve();


    return 0;
}