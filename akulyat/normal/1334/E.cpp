#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC targer ("avx2")

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


ll n, q;
bool viv = false;
vector<int> p;
vector<ll> f, of;
vector<pll> dd;

vector<int> erat(long long last) {
vector<bool> bad;
vector<int> r;
for (int i = 0; i < last + 10; i++)
    bad.push_back(true);
for (int i = 2; i <= last; i++)
    if (bad[i])
        {
        int j = 2;
        while (j * i <= last)
            {
            bad[j * i] = false;
            j++;
            }
        r.push_back(i);
        }
return r;
}

long long obr(long long v, long long mod)
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




void prepare() {
	int con = 1;
//	con = 100;
//	p = erat(32 * ml / con);
	ll fn = n;
	for (int i = 2; i < int(sqrt(n)) + 10; i++) {
		int d = i;
		if (!(fn % d)) {
			pll add = {d, 0};
			while (!(fn % d)) 
				add.S++, fn /= d;
			dd.push_back(add);
		}
	}
	if (fn != 1)
		dd.push_back({fn, 1});

	f.push_back(1);
	for (int i = 1; i < 100 * kk; i++) {
		f.push_back(f.back() * i), f.back() %= mod;
	}
	for (auto i : f)
		of.push_back(obr(i, mod));
}

int C(int n, int k) {
	ll res = 1;
	res *= f[n];
	res %= mod;
	res *= of[n - k];
	res %= mod;
	res *= of[k];
	res %= mod;
	return res;
}

void work() {
	ll u, v;
	cin >> u >> v;

	auto ddu = dd, ddv = dd;
	ll fu = u, fv = v;
	for (auto &i : ddu) {
		i.S = 0;
		while (!(fu % i.F))
			i.S++, fu /= i.F;
	}
	for (auto &i : ddv) {
		i.S = 0;
		while (!(fv % i.F))
			i.S++, fv /= i.F;
	}

	vector<int> nn, pn;
	for (int i = 0; i < ddv.size(); i++) {
		if (ddv[i].S > ddu[i].S)
			nn.push_back(ddv[i].S - ddu[i].S);
		if (ddv[i].S < ddu[i].S)
			pn.push_back(-(ddv[i].S - ddu[i].S));
	}

	int ns = 0, ps = 0;
	for (auto i : nn)
		ns += i;
	for (auto i : pn)
		ps += i;
	ll ans = 1;
	for (int i = 0; i < nn.size(); i++) {
		// cout << "A " << ns << ' ' << nn[i] << endl;
		ans *= C(ns, nn[i]);
		ans %= mod;
		ns -= nn[i];		
	}
	for (int i = 0; i < pn.size(); i++) {		
		// cout << "B " << ps << ' ' << pn[i] << endl;
		ans *= C(ps, pn[i]);
		ans %= mod;
		ps -= pn[i];		
	}

	cout << ans << '\n';
}

void solve() {
	cin >> n >> q;
	prepare();
	while (q--)
		work();
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}