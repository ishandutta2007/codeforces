#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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


ll n[3];
vector<ll> v[3];
bool viv = false;

inline ll sq(ll v) {
	return v * v;
}

void solve() {
	for (int i = 0; i < 3; i++) {
		cin >> n[i];
	}
	for (int i = 0; i < 3; i++) {
		v[i].clear();
		v[i].resize(n[i]);
		for (auto &it : v[i])
			cin >> it;
		sort(v[i].begin(), v[i].end());
	}

	ll ans = inf * 4;
	for (int a = 0; a < 3; a++) {
		int b = 0, c = 0;
		while (b == a)
			b++;
		while (c == a || c == b)
			c++;
		int p1 = 0;
		int p2 = 0;
		for (int i = 0; i < n[a]; i++) {
			while (p1 < n[b] && v[b][p1] < v[a][i])
				p1++;
			while (p2 < n[c] && v[c][p2] < v[a][i])
				p2++;
			vector<ll> va, vb, vc;

			va.push_back(v[a][i]);
	
			if (p1 != n[b])		
				vb.push_back(v[b][p1]);
			if (p1 != 0)		
				vb.push_back(v[b][p1 - 1]);

			if (p2 != n[c])		
				vc.push_back(v[c][p2]);
			if (p2 != 0)		
				vc.push_back(v[c][p2 - 1]);

			for (int i1 = 0; i1 < va.size(); i1++) {
				for (int i2 = 0; i2 < vb.size(); i2++) {
					for (int i3 = 0; i3 < vc.size(); i3++) {
						ll lans = 0;
						lans += sq(abs(va[i1] - vb[i2]));
						lans += sq(abs(vb[i2] - vc[i3]));
						lans += sq(abs(vc[i3] - va[i1]));
						ans = min(ans, lans);
					}
				}
			}
		}
	}

	cout << ans << '\n';
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