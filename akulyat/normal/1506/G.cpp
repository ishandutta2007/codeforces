#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
string s;
bool viv = false;


void solve() {
	cin >> s;	
	n = s.size();
	// reverse(s.begin(), s.end());

	vector<int> v;
	for (auto i : s)
		v.push_back(i - 'a');
	vector<int> cnt(26, 0);
	for (auto i : v)
		cnt[i]++;
	vector<bool> ans(n, false);

	vector<deque<int>> pl(26);
	for (int i = 0; i < n; i++)
		pl[v[i]].push_back(i);

	int sz = 0;
	for (auto i : pl)
		sz += !i.empty();

	string res;
	while (true) {
		int nice = -1;
		for (int j = 0; j < 26; j++) {
			if (pl[j].size()) {
				int add = pl[j].front();
				int good = true;
				for (int i = 0; i < 26; i++) {
					if (pl[i].size() && pl[i].back() < add)
						good = false;
				}
				if (good)
					nice = j;
			}
		}
		if (nice == -1) {
			cout << res << '\n';
			if (res.size() < sz) {
				cout << endl;
				assert(false);
			}
			return;
		}

		int add = pl[nice].front();
		res += char('a' + v[add]);
		for (int i = 0; i < 26; i++) {
			while (pl[i].size() && pl[i].front() <= add)
				pl[i].pop_front();
			pl[nice].clear();
		}
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}