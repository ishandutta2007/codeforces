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
const ll p = 123457;
const long long inf = ml * ml * ml + 7;
 
ll n, o;
vector<ll> cnt, who, h, pp, op, hh, h3;
string s, s2, s3;
set<ll> z;
bool viv = false;

long long obr(long long v, long long mod) {
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


ll zero(ll l, ll r) {
	ll res = 0;
	res += cnt[r];
	res -= cnt[l];
	return res;
}

void prepare() {
	hh.push_back(rand() % ml);
	hh.push_back(rand() % ml);

	h.push_back(0);
	h3.push_back(0);
	pp.push_back(1);
	for (ll i = 0; i < ml; i++)
		pp.push_back(pp.back() * p), pp.back() %= mod;

	for (ll i = 0; i < s2.size(); i++) {
		h.push_back(h.back() * p + hh[s2[i] - '0']);
		h.back() %= mod;
	}
	for (ll i = 0; i < s3.size(); i++) {
		h3.push_back(h3.back() * p + hh[s3[i] - '0']);
		h3.back() %= mod;
	}
}

ll has(ll l, ll r) {
	ll hs = h[r];
	ll rhs = h[l];
	rhs *= pp[r - l];
	hs -= rhs;
	hs %= mod;
	if (hs < 0)
		hs += mod;
	return hs;
}

ll has2(ll l, ll r) {
	ll hs = h3[r];
	ll rhs = h3[l];
	rhs *= pp[r - l];
	hs -= rhs;
	hs %= mod;
	if (hs < 0)
		hs += mod;
	return hs;
}



void solve() {
	cin >> n >> s;
	cnt.push_back(0);
	for (auto i : s)
		cnt.push_back(cnt.back() + (i == '0'));

	for (ll i = 0; i < n; i++)
		if (s[i] == '0')
			z.insert(i);

	for (auto i : z)
		s2 += ('0' + (i & 1));
	for (auto i : z)
		s3 += ('1' - (i & 1));
	prepare();

	who.resize(n, 0);
	if (s[0] == '0')
		who[0] = 1;
	for (ll i = 1; i < n; i++)
		who[i] = who[i - 1] + (s[i] == '0');


	ll q;
	cin >> q;
	while (q--) {
		ll l1, l2, l;
		cin >> l1 >> l2 >> l;
		l1--, l2--;
		if (zero(l1, l1 + l) != zero(l2, l2 + l)) {
			cout << "No\n";
		} else {
			if (zero(l1, l1 + l) == 0) {
				cout << "Yes\n";
			} else {
				ll z1 = *z.lower_bound(l1);
				ll z2 = *z.lower_bound(l2);	
				if (abs(l1 + l2 - z1 - z2) & 1) {
					cout << "No\n"; 
				} else {
					ll n1 = who[z1] - 1;
					ll n2 = who[z2] - 1;
					ll z = zero(l1, l1 + l);
					if (has(n1, n1 + z) == has(n2, n2 + z) || has2(n1, n1 + z) == has(n2, n2 + z) || has2(n1, n1 + z) == has2(n2, n2 + z) || has(n1, n1 + z) == has2(n2, n2 + z))
						cout << "Yes\n";
					else
						cout << "No\n";
				}
			}
		}
	}
}


int main() {
//	viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}