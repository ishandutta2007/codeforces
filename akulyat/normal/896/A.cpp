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
vector<ll> sz;
string s0, s1, s2, s3, s4;

bool viv = false;

void prepare() {
	s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
	sz.push_back(s0.size());
	s1 = "What are you doing while sending ''? Are you busy? Will you send ''?";
	s2 = "What are you doing while sending '";
	s3 = "'? Are you busy? Will you send '";
	s4 = "'?";

	while (sz.back() < ml * ml * ml + ml)
		sz.push_back(sz.back() * 2 + s1.size());
	while (sz.size() < ml / 4)
		sz.push_back(sz.back());


}

char who(ll n, ll k) {
	if (k >= sz[n]) 
		return '.';

	if (n == 0) 
		return s0[k];

	if (k < s2.size()) 
		return s2[k];
	k -= s2.size();
	if (k < sz[n - 1]) {
		return who(n - 1, k);
	}
	k -= sz[n - 1];

	if (k < s3.size()) 
		return s3[k];
	k -= s3.size();
	if (k < sz[n - 1]) {
		return who(n - 1, k);
	}
	k -= sz[n - 1];

	return s4[k];
}

void solve() {
	ll n, k;
	cin >> n >> k;
	k--;
	auto ans = who(n, k);
	string aa;
	aa += ans;
	if (aa == "'")
		ans = '"';
	cout << ans;
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prepare();
    ll t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}