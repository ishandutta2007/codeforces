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
 
 
ll n;
vector<ll> v;
vector<vector<bool>> e;
int canf[1ll << 14][14][1ll << 6];
int cans[1ll << 14][14][1ll << 6];
bool viv = false;
 
int get(vector<int> who) {
	int res = 0;
	for (int i = 0; i < (int)who.size() - 1; i++) {
		res <<= 1;
		res += e[who[i]][who[i + 1]];
	}
	return res;
}
 
void work(int mask) {
	vector<int> who;
	int fmask = mask;
	for (int i = 0; i < n; i++) {
		if (fmask & 1)
			who.push_back(i);
		fmask >>= 1;
	}
	auto fr = get(who);
	canf[mask][who.back()][fr]++;
	cans[mask][who[0]][fr]++;
	int it = 1;
	while (next_permutation(who.begin(), who.end())) {
		auto fr = get(who);
		canf[mask][who.back()][fr]++;
		cans[mask][who[0]][fr]++;
		it++;
	}
}
 
void solve() {
	cin >> n;
	e.resize(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			e[i].push_back(s[j] == '1');
	}
 
	for (int i = 0; i < (1 << n); i++) {
		int mask = i, cnt = 0;
		while (mask)
			cnt += (mask & 1), mask >>= 1;
		if (cnt == n / 2 || cnt == (n + 1) / 2) {
			work(i);
		}
	}
 
	vector<long long> ans(1 << (n - 1));
	for (int i = 0; i < (1 << n); i++) {
		int mask = i, cnt = 0;
		vector<int> s, f;
		for (int j = 0; j < n; j++) {
			cnt += (mask & 1);
			if (mask & 1)
				s.push_back(j);
			else
				f.push_back(j);
			mask >>= 1;
		}
		mask = i;
		int dmask = (1 << n) - 1 - mask;
		int sz1 = n / 2;
		int sz2 = n - sz1;
		if (cnt == n / 2) {
			for (auto sf : s)
				for (auto fs : f) {
					int ffr = (e[sf][fs] << (sz2 - 1));
					for (int i = 0; i < (1 << (sz1 - 1)); i++) {
						for (int j = 0; j < (1 << (sz2 - 1)); j++) {
							ans[(i << (sz2)) + ffr + j] += (long long)canf[mask][sf][i] * cans[dmask][fs][j];
						}
					}
				}
		}		
	}
	for (auto i : ans)
		cout << i << ' ';
 
}
 
 
int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();
 
	return 0;
}