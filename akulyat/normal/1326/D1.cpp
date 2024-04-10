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
const ll p[2] = {123457, 239};
const long long mod[2] = {ml * kk + 7, 998244353};
const long long inf = ml * ml * ml + 7; 


ll n, cnt;
vector<vector<ll>> lh;
vector<pll> hh1, hh2;
vector<pll> sh1, sh2;
bool viv = false;
string s, s2;

bool pal(string s) {
	for (int i = 0; i < s.size(); i++)
		if (s[i] != s[s.size() - 1 - i])
			return false;
	return true;		
}

ll ran() {
	ll res = 0;
	for (int i = 0; i < 10; i++) {
		ll a = rand() % kk;
		ll b = rand() % kk;
		res *= a;
		res += b;
		res %= mod[0];
	}
	return res;
}

void build() {
	cnt++;
	if (cnt == 1) {
		lh.resize(2);
		for (int i = 0; i < 2; i++) {
			lh[i].resize(26);
			for (auto &val : lh[i])
				val = ran();
		}
	}

	hh1.clear();
	hh2.clear();
	sh1.clear();
	sh2.clear();

	hh1.push_back({0, 0});	
	hh2.push_back({0, 0});	
	for (int i = 0; i < n; i++) {
		hh1.push_back(hh1.back());
		hh1.back().F *= p[0];
		hh1.back().S *= p[1];
		hh1.back().F += lh[0][s[i] - 'a'];
		hh1.back().S += lh[1][s[i] - 'a'];
		hh1.back().F %= mod[0]; 
		hh1.back().S %= mod[1]; 

		hh2.push_back(hh2.back());
		hh2.back().F *= p[0];
		hh2.back().S *= p[1];
		hh2.back().F += lh[0][s2[i] - 'a'];
		hh2.back().S += lh[1][s2[i] - 'a'];
		hh2.back().F %= mod[0]; 
		hh2.back().S %= mod[1]; 


	}
	sh1.push_back({0, 0});	
	sh2.push_back({0, 0});	
	ll stp[2] = {1, 1};
	for (int i = 0; i < n; i++) {
		sh1.push_back(sh1.back());
		sh1.back().F += (stp[0] * lh[0][s[n - 1 - i] - 'a']);
		sh1.back().S += (stp[1] * lh[1][s[n - 1 - i] - 'a']);
		sh1.back().F %= mod[0]; 
		sh1.back().S %= mod[1]; 

		sh2.push_back(sh2.back());
		sh2.back().F += (stp[0] * lh[0][s2[n - 1 - i] - 'a']);
		sh2.back().S += (stp[1] * lh[1][s2[n - 1 - i] - 'a']);
		sh2.back().F %= mod[0]; 
		sh2.back().S %= mod[1]; 

		stp[0] *= p[0];
		stp[1] *= p[1];
		stp[0] %= mod[0];
		stp[1] %= mod[1];
	}
	reverse(sh1.begin(), sh1.end());
	reverse(sh2.begin(), sh2.end());
}

void show() {
	if (!viv)
		return;
	cout << "hh1 " << endl;
	for (auto p : hh1) {
		cout << p.F << ' ' << p.S << endl;
	}
	cout << "hh2 " << endl;
	for (auto p : hh2) {
		cout << p.F << ' ' << p.S << endl;
	}
	cout << "sh1 " << endl;
	for (auto p : sh1) {
		cout << p.F << ' ' << p.S << endl;
	}
	cout << "sh2 " << endl;
	for (auto p : sh2) {
		cout << p.F << ' ' << p.S << endl;
	}
}

pll h(int l, int r) {
	if (l == 0) {
		r++;
		return hh1[r];
	}
	return sh1[l];
}

pll h2(int l, int r) {
	if (l == 0) {
		r++;
		return hh2[r];
	}
	return sh2[l];
}

bool pap(ll l, ll r) {
	int l2 = n - 1 - r;
	int r2 = n - 1 - l;

	return h(l, r) == h2(l2, r2);
}

void solve() {
	cin >> s;
	n = s.size();
	if (pal(s)) {
		cout << s << '\n';
		return;
	}

	ll l = 0;
	while (s[l] == s[s.size() - 1 - l])
		l++;

	if (viv)
		cout << "same " << l << endl;

	string pr = s.substr(0, l);
	string sf = pr;
	reverse(sf.begin(), sf.end());

	for (int i = 0; i < l; i++)
		s.pop_back();
	reverse(s.begin(), s.end());
	for (int i = 0; i < l; i++)
		s.pop_back();
	reverse(s.begin(), s.end());

	s2 = s;
	n = s.size();
	reverse(s2.begin(), s2.end());
	if (viv)
		cout << "Star " << endl;
	build();
	show();
	if (viv)
		cout << "End " << endl;

	vector<pair<ll, pll>> all;
	for (int r = 0; r < s.size(); r++)
		if (pap(0, r))
			all.push_back({r + 1, {0, r}});
	for (int l = 0; l < s.size(); l++)
		if (pap(l, s.size() - 1))
			all.push_back({s.size() - l, {l, s.size() - 1}});
	if (viv) {
		cout << s << endl;
		for (auto p : all)
			cout << p.S.F << ' ' << p.S.S << endl;
	}
	if (viv)
		cout << "Got " << all.size() << endl;

	auto best = all[0];
	for (auto it : all)
		best = max(best, it);

	cout << pr;
	for (int i = best.S.F; i <= best.S.S; i++)
		cout << s[i];
	cout << sf;
	cout << '\n';




}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}