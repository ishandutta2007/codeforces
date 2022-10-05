#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 

ll n;
bool viv = false;
vector<ll> v, f, of;

long long obr(long long v, ll st = mod - 2)
{
long long i = 0;
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


void prepare() {
	f.push_back(1);
	for (int i = 1; i < ml; i++)
		f.push_back(f.back() * i), f.back() %= mod;

	for (auto i : f) {
		assert(i >= 0);
		assert(i < mod);
		of.push_back(obr(i));
	}
}

ll fac(ll n) {
	return f[n];
}

ll C(ll n, ll k) {
	if (k < 0 || k > n)
		return 0;
	ll res = 1;
	res *= f[n];
	res %= mod;
	res *= of[k];
	res %= mod;
	res *= of[n - k];
	res %= mod;
	return res;
}

void solve() {
	prepare();
	ll k;
	cin >> n >> k;
	if (k >= n) {
		cout << 0;
		exit(0);
	}

	ll nxt = n - 1 - k;
	ll ans = 1;

	if (viv)
		cout << "OK" << endl;

	nxt++;
	ans = obr(nxt, n);
	for (int i = 1; i < nxt; i++) {
		ll st = obr(i, n);
		st *= C(nxt, i);
		st %= mod;
		if ((nxt - i) & 1)
			st *= -1;
		st %= mod;
		while (st < 0)
			st += mod;
		ans += st;
		ans %= mod; 
		while (ans < 0)
			ans += mod;
	}
	ans %= mod;
	if (viv)
		cout << "OK " << ans << endl;
	nxt--;

	ans *= C(n, nxt + 1);
	ans %= mod;
	if (viv)
		cout << "OK " << ans << endl;

	if (k != 0)
		ans *= 2;
	ans %= mod;
	if (viv)
		cout << "OK " << ans << endl;

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